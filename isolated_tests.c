#include "tester.h"
#include "advice.h"

/* Wrapper functions that use process isolation */

/* These are wrappers that call the actual test functions in isolated processes */
typedef void (*test_func_t)(void);

/* Track which tests should use isolation */
typedef struct s_test_info {
	test_func_t func;
	const char *name;
} t_test_info;

/* Example isolated test wrapper */
void	run_test_isolated(test_func_t test_func, const char *test_name)
{
	int result = run_isolated_test(test_func, test_name);
	
	if (!result)
	{
		/* Test crashed or timed out - already logged by isolation.c */
		g_stats.failed_tests++;
		g_stats.failed_functions++;
		print_test_result(test_name, 0, "CRASH/TIMEOUT - Process killed");
	}
}

/* Isolated Part 1 Tests */
void	run_part1_tests_isolated(void)
{
	g_isolated_mode = 1;  /* Enable isolated mode to prevent duplicate headers */
	print_header("PART 1: LIBC FUNCTIONS (WITH CRASH PROTECTION)");
	
	/* Note: All tests are already run in isolation via run_isolated_test
	   This prevents any single crash from taking down the entire suite */
	
	run_isolated_test(test_ft_isalpha, "ft_isalpha");
	run_isolated_test(test_ft_isdigit, "ft_isdigit");
	run_isolated_test(test_ft_isalnum, "ft_isalnum");
	run_isolated_test(test_ft_isascii, "ft_isascii");
	run_isolated_test(test_ft_isprint, "ft_isprint");
	run_isolated_test(test_ft_strlen, "ft_strlen");
	run_isolated_test(test_ft_memset, "ft_memset");
	run_isolated_test(test_ft_bzero, "ft_bzero");
	run_isolated_test(test_ft_memcpy, "ft_memcpy");
	run_isolated_test(test_ft_memmove, "ft_memmove");
	run_isolated_test(test_ft_strlcpy, "ft_strlcpy");
	run_isolated_test(test_ft_strlcat, "ft_strlcat");
	run_isolated_test(test_ft_toupper, "ft_toupper");
	run_isolated_test(test_ft_tolower, "ft_tolower");
	run_isolated_test(test_ft_strchr, "ft_strchr");
	run_isolated_test(test_ft_strrchr, "ft_strrchr");
	run_isolated_test(test_ft_strncmp, "ft_strncmp");
	run_isolated_test(test_ft_memchr, "ft_memchr");
	run_isolated_test(test_ft_memcmp, "ft_memcmp");
	run_isolated_test(test_ft_strnstr, "ft_strnstr");
	run_isolated_test(test_ft_atoi, "ft_atoi");
}

/* Isolated Part 2 Tests */
void	run_part2_tests_isolated(void)
{
	g_isolated_mode = 1;  /* Enable isolated mode to prevent duplicate headers */
	print_header("PART 2: ADDITIONAL FUNCTIONS (WITH CRASH PROTECTION)");
	
	run_isolated_test(test_ft_calloc, "ft_calloc");
	run_isolated_test(test_ft_strdup, "ft_strdup");
	run_isolated_test(test_ft_substr, "ft_substr");
	run_isolated_test(test_ft_strjoin, "ft_strjoin");
	run_isolated_test(test_ft_strtrim, "ft_strtrim");
	run_isolated_test(test_ft_split, "ft_split");
	run_isolated_test(test_ft_itoa, "ft_itoa");
	run_isolated_test(test_ft_strmapi, "ft_strmapi");
	run_isolated_test(test_ft_striteri, "ft_striteri");
	run_isolated_test(test_ft_putchar_fd, "ft_putchar_fd");
	run_isolated_test(test_ft_putstr_fd, "ft_putstr_fd");
	run_isolated_test(test_ft_putendl_fd, "ft_putendl_fd");
	run_isolated_test(test_ft_putnbr_fd, "ft_putnbr_fd");
}

/* Run all tests with isolation */
void	run_all_tests_isolated(void)
{
	init_stats();
	run_part1_tests_isolated();
	run_part2_tests_isolated();
}
