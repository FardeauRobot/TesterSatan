#include "tester.h"
#include "trace.h"
#include "libft.h"

t_test_stats g_stats;

void run_part1_tests(void)
{
	printf("\n%s%s════════════════════════════════════════════════════════════════════════════════%s\n", BOLD, CYAN, RESET);
	printf("%s%s                              PART 1: LIBC FUNCTIONS                              %s\n", BOLD, CYAN, RESET);
	printf("%s%s════════════════════════════════════════════════════════════════════════════════%s\n\n", BOLD, CYAN, RESET);
	
	/* Character checking functions */
	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();
	
	/* String functions */
	test_ft_strlen();
	test_ft_strlcpy();
	test_ft_strlcat();
	test_ft_strchr();
	test_ft_strrchr();
	test_ft_strncmp();
	test_ft_strnstr();
	
	/* Memory functions */
	test_ft_memset();
	test_ft_bzero();
	test_ft_memcpy();
	test_ft_memmove();
	test_ft_memchr();
	test_ft_memcmp();
	
	/* Conversion functions */
	test_ft_toupper();
	test_ft_tolower();
	test_ft_atoi();
}

void run_part2_tests(void)
{
	printf("\n%s%s════════════════════════════════════════════════════════════════════════════════%s\n", BOLD, MAGENTA, RESET);
	printf("%s%s                         PART 2: ADDITIONAL FUNCTIONS                            %s\n", BOLD, MAGENTA, RESET);
	printf("%s%s════════════════════════════════════════════════════════════════════════════════%s\n\n", BOLD, MAGENTA, RESET);
	
	/* Memory allocation functions */
	test_ft_calloc();
	test_ft_strdup();
	
	/* String manipulation functions */
	test_ft_substr();
	test_ft_strjoin();
	test_ft_strtrim();
	test_ft_split();
	test_ft_itoa();
	test_ft_strmapi();
	test_ft_striteri();
	
	/* File descriptor functions */
	test_ft_putchar_fd();
	test_ft_putstr_fd();
	test_ft_putendl_fd();
	test_ft_putnbr_fd();
}

void run_all_tests(void)
{
	print_header("LIBFT COMPREHENSIVE TESTER");
	run_part1_tests();
	run_part2_tests();
}

int main(int argc, char **argv)
{
	/* Check for interactive mode flag */
	if (argc > 1 && (strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "--interactive") == 0))
	{
		run_interactive_mode();
		return 0;
	}
	
	/* Check for isolation mode flag (crash protection) */
	if (argc > 1 && (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "--safe") == 0))
	{
		init_stats();
		init_trace_system();
		
		run_all_tests_isolated();
		
		/* Print final summary */
		print_summary();
		
		/* Save traces if there were failures */
		if (g_stats.failed_tests > 0)
		{
			save_traces_to_file();
			printf("\n%s%s💡 TIP: Some tests crashed or timed out. Check traces for details.%s\n", 
				BOLD, YELLOW, RESET);
		}
		
		return (g_stats.failed_tests > 0 ? 1 : 0);
	}
	
	/* Default: Run all tests in batch mode with crash protection */
	init_stats();
	init_trace_system();
	
	run_all_tests_isolated();
	
	/* Print final summary */
	print_summary();
	
	/* Save traces and display if there were failures */
	if (g_stats.failed_tests > 0)
	{
		save_traces_to_file();
		printf("\n%s%s💡 TIP: Run with -i flag for interactive mode to view detailed failure traces%s\n", 
			BOLD, YELLOW, RESET);
	}
	
	return (g_stats.failed_tests > 0 ? 1 : 0);
}
