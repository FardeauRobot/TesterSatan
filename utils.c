#include "tester.h"
#include "advice.h"

const char *g_current_function = "Unknown";
int g_function_counter = 0;
int g_isolated_mode = 0;

void	init_stats(void)
{
	g_stats.total_tests = 0;
	g_stats.passed_tests = 0;
	g_stats.failed_tests = 0;
	g_stats.total_functions = 0;
	g_stats.passed_functions = 0;
	g_stats.failed_functions = 0;
	g_function_counter = 0;
}

void	print_header(const char *title)
{
	printf("\n%s%s╔════════════════════════════════════════════════════════════════════════════════╗%s\n", BOLD, BLUE, RESET);
	printf("%s%s║                                                                                ║%s\n", BOLD, BLUE, RESET);
	printf("%s%s║                        %-55s║%s\n", BOLD, BLUE, title, RESET);
	printf("%s%s║                                                                                ║%s\n", BOLD, BLUE, RESET);
	printf("%s%s╚════════════════════════════════════════════════════════════════════════════════╝%s\n", BOLD, BLUE, RESET);
}

void	print_function_header(const char *function_name)
{
	/* Skip if we're in isolated mode - header already printed before fork */
	if (g_isolated_mode)
		return;
		
	g_function_counter++;
	g_current_function = function_name;
	g_stats.total_functions++;
	printf("\n%s%s┌────────────────────────────────────────────────────────────────────────────────┐%s\n", BOLD, YELLOW, RESET);
	printf("%s%s│ [%02d] Testing: %-65s│%s\n", BOLD, YELLOW, g_function_counter, function_name, RESET);
	printf("%s%s└────────────────────────────────────────────────────────────────────────────────┘%s\n", BOLD, YELLOW, RESET);
}

void	print_test_result(const char *test_name, int passed, const char *details)
{
	g_stats.total_tests++;
	
	if (passed)
	{
		g_stats.passed_tests++;
		printf("  %s✓%s ", GREEN, RESET);
	}
	else
	{
		g_stats.failed_tests++;
		printf("  %s✗%s ", RED, RESET);
		
		/* Get contextual advice for this function/test */
		const char *advice = get_function_advice(g_current_function, test_name);
		
		/* Log failure to trace system with specific advice */
		log_failure(g_current_function, test_name, "See details", details ? details : "No details", 
			advice);
	}
	
	printf("%s%-50s%s", passed ? GREEN : RED, test_name, RESET);
	
	if (details && strlen(details) > 0)
	{
		printf(" %s%s%s%s%s", DIM, passed ? GREEN : RED, details, RESET, DIM);
	}
	
	printf("%s\n", RESET);
}

void	update_function_stats(int function_passed)
{
	if (function_passed)
		g_stats.passed_functions++;
	else
		g_stats.failed_functions++;
}

void	print_summary(void)
{
	int test_percentage = 0;
	int function_percentage = 0;
	
	if (g_stats.total_tests > 0)
		test_percentage = (g_stats.passed_tests * 100) / g_stats.total_tests;
	
	if (g_stats.total_functions > 0)
		function_percentage = (g_stats.passed_functions * 100) / g_stats.total_functions;
	
	printf("\n\n%s%s╔════════════════════════════════════════════════════════════════════════════════╗%s\n", BOLD, BLUE, RESET);
	printf("%s%s║                                  TEST SUMMARY                                  ║%s\n", BOLD, BLUE, RESET);
	printf("%s%s╠════════════════════════════════════════════════════════════════════════════════╣%s\n", BOLD, BLUE, RESET);
	
	printf("%s%s║%s                                                                                %s%s║%s\n", BOLD, BLUE, RESET, BOLD, BLUE, RESET);
	printf("%s%s║%s  %sFunctions Tested:%s  %-57d  %s%s║%s\n", BOLD, BLUE, RESET, CYAN, RESET, g_stats.total_functions, BOLD, BLUE, RESET);
	printf("%s%s║%s  %sFunctions Passed:%s  %-24d %s[%3d%%]%s                 %s%s║%s\n", 
		BOLD, BLUE, RESET, GREEN, RESET, g_stats.passed_functions, 
		function_percentage >= 80 ? GREEN : (function_percentage >= 50 ? YELLOW : RED),
		function_percentage, RESET, BOLD, BLUE, RESET);
	printf("%s%s║%s  %sFunctions Failed:%s  %-57d  %s%s║%s\n", BOLD, BLUE, RESET, RED, RESET, g_stats.failed_functions, BOLD, BLUE, RESET);
	
	printf("%s%s║%s                                                                                %s%s║%s\n", BOLD, BLUE, RESET, BOLD, BLUE, RESET);
	printf("%s%s║%s  %sTotal Tests:%s      %-57d  %s%s║%s\n", BOLD, BLUE, RESET, CYAN, RESET, g_stats.total_tests, BOLD, BLUE, RESET);
	printf("%s%s║%s  %sTests Passed:%s     %-24d %s[%3d%%]%s                 %s%s║%s\n", 
		BOLD, BLUE, RESET, GREEN, RESET, g_stats.passed_tests,
		test_percentage >= 80 ? GREEN : (test_percentage >= 50 ? YELLOW : RED),
		test_percentage, RESET, BOLD, BLUE, RESET);
	printf("%s%s║%s  %sTests Failed:%s     %-57d  %s%s║%s\n", BOLD, BLUE, RESET, RED, RESET, g_stats.failed_tests, BOLD, BLUE, RESET);
	
	printf("%s%s║%s                                                                                %s%s║%s\n", BOLD, BLUE, RESET, BOLD, BLUE, RESET);
	printf("%s%s╚════════════════════════════════════════════════════════════════════════════════╝%s\n", BOLD, BLUE, RESET);
	
	if (g_stats.failed_tests == 0)
	{
		printf("\n%s%s   🎉 CONGRATULATIONS! ALL TESTS PASSED! 🎉%s\n\n", BOLD, GREEN, RESET);
	}
	else
	{
		printf("\n%s%s   ⚠️  SOME TESTS FAILED - Please review the output above ⚠️%s\n\n", BOLD, RED, RESET);
	}
}
