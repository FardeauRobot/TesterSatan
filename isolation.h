#ifndef ISOLATION_H
# define ISOLATION_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>

/* Maximum timeout for a single test (in seconds) */
# define TEST_TIMEOUT 5

/* Exit codes for child processes */
# define CRASH_SEGFAULT 139
# define CRASH_ABORT 134
# define CRASH_TIMEOUT 124
# define CRASH_OTHER 127

/**
 * run_isolated_test - Runs a test function in an isolated child process
 * 
 * This function forks a child process and runs the provided test function
 * in isolation. If the test crashes (segfault, abort, etc.), it catches
 * the signal and prevents the main program from crashing.
 * 
 * @test_func: Pointer to the test function to run
 * @test_name: Name of the test (for reporting)
 * 
 * Return: 1 if test completed successfully, 0 if crashed/timed out
 */
int	run_isolated_test(void (*test_func)(void), const char *test_name);

/**
 * get_crash_reason - Returns a human-readable explanation of why a process crashed
 * 
 * @status: Wait status returned by waitpid
 * 
 * Return: String describing the crash reason
 */
const char *get_crash_reason(int status);

#endif
