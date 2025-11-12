#include "isolation.h"
#include "tester.h"
#include <signal.h>
#include "advice.h"

/**
 * Signal handler for timeout - kills child process after TEST_TIMEOUT seconds
 */
static void timeout_handler(int signum)
{
	(void)signum;
	exit(CRASH_TIMEOUT);
}

/**
 * run_isolated_test - Executes a test function in a child process
 * 
 * This prevents any crashes (segfaults, aborts) from affecting the main program.
 * The child process is given TEST_TIMEOUT seconds to complete.
 * 
 * Returns:
 *   1 = Test completed successfully
 *   0 = Test crashed, hung, or timed out
 */
int	run_isolated_test(void (*test_func)(void), const char *test_name)
{
	pid_t	child_pid;
	int		status;

	if (!test_func)
		return (0);

	/* Print function header in parent before forking */
	if (g_isolated_mode)
	{
		g_function_counter++;
		g_current_function = test_name;
		g_stats.total_functions++;
		printf("\n%s%s┌────────────────────────────────────────────────────────────────────────────────┐%s\n", BOLD, YELLOW, RESET);
		printf("%s%s│ [%02d] Testing: %-65s│%s\n", BOLD, YELLOW, g_function_counter, test_name, RESET);
		printf("%s%s└────────────────────────────────────────────────────────────────────────────────┘%s\n", BOLD, YELLOW, RESET);
	}

	/* Flush all output before forking to prevent duplication */
	fflush(stdout);
	fflush(stderr);

	child_pid = fork();

	if (child_pid < 0)
	{
		/* Fork failed */
		printf("%s[ERROR] Failed to fork process for test '%s'%s\n", RED, test_name, RESET);
		return (0);
	}

	if (child_pid == 0)
	{
		/* Child process */
		
		/* Reset all signal handlers to defaults (important!) */
		signal(SIGSEGV, SIG_DFL);  /* Let segfault be caught by parent */
		signal(SIGABRT, SIG_DFL);
		signal(SIGBUS, SIG_DFL);
		signal(SIGFPE, SIG_DFL);
		signal(SIGILL, SIG_DFL);
		signal(SIGPIPE, SIG_IGN);   /* Ignore broken pipe */
		
		/* Set up timeout handler */
		signal(SIGALRM, timeout_handler);
		alarm(TEST_TIMEOUT);

		/* Run the test function */
		test_func();

		/* If we reach here, test completed without crashing */
		exit(EXIT_SUCCESS);
	}
	else
	{
		/* Parent process - wait for child */
		if (waitpid(child_pid, &status, 0) == -1)
		{
			printf("%s[ERROR] waitpid failed for test '%s'%s\n", RED, test_name, RESET);
			return (0);
		}

		/* Check child's exit status */
		if (WIFEXITED(status))
		{
			/* Child exited normally */
			if (WEXITSTATUS(status) == EXIT_SUCCESS)
				return (1);  /* Test passed */
			else if (WEXITSTATUS(status) == CRASH_TIMEOUT)
			{
				printf("%s[TIMEOUT] Test '%s' exceeded %d seconds%s\n", 
					YELLOW, test_name, TEST_TIMEOUT, RESET);
				/* Log timeout to trace system and increment failed count */
				g_stats.failed_tests++;
				g_stats.failed_functions++;
				const char *advice = get_function_advice(test_name, "timeout");
				log_failure(test_name, "TIMEOUT", "Exceeded time limit", 
					"Test hung or infinite loop detected", advice);
				return (0);
			}
			else
			{
				printf("%s[CRASH] Test '%s' exited with code %d%s\n", 
					RED, test_name, WEXITSTATUS(status), RESET);
				return (0);
			}
		}
		else if (WIFSIGNALED(status))
		{
			/* Child killed by signal (crash) */
			int sig = WTERMSIG(status);
			printf("%s[CRASH] Test '%s' killed by signal %d (%s)%s\n", 
				RED, test_name, sig, strsignal(sig), RESET);
			/* Log crash to trace system and increment failed count */
			g_stats.failed_tests++;
			g_stats.failed_functions++;
			const char *advice = get_function_advice(test_name, strsignal(sig));
			log_failure(test_name, strsignal(sig), sig == SIGSEGV ? "Segmentation fault" : "Signal termination",
				"Test process crashed", advice);
			return (0);
		}
		else
		{
			printf("%s[ERROR] Test '%s' terminated abnormally%s\n", 
				RED, test_name, RESET);
			return (0);
		}
	}

	return (0);
}

/**
 * get_crash_reason - Returns human-readable crash reason
 */
const char *get_crash_reason(int status)
{
	if (WIFEXITED(status))
	{
		int exit_code = WEXITSTATUS(status);
		if (exit_code == CRASH_TIMEOUT)
			return ("Timeout (exceeded time limit)");
		else if (exit_code == EXIT_SUCCESS)
			return ("Completed successfully");
		else
			return ("Abnormal exit");
	}
	else if (WIFSIGNALED(status))
	{
		int sig = WTERMSIG(status);
		switch (sig)
		{
			case SIGSEGV:
				return ("Segmentation fault");
			case SIGABRT:
				return ("Abort signal");
			case SIGBUS:
				return ("Bus error");
			case SIGFPE:
				return ("Floating point exception");
			case SIGILL:
				return ("Illegal instruction");
			default:
				return ("Signal termination");
		}
	}
	return ("Unknown termination");
}
