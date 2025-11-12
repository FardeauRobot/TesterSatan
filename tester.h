#ifndef TESTER_H
# define TESTER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <bsd/string.h>
# include <unistd.h>
# include <ctype.h>
# include <limits.h>
# include "trace.h"
# include "isolation.h"
# include "advice.h"

/* Color codes for terminal output */
# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define BOLD "\033[1m"
# define DIM "\033[2m"

/* Test statistics structure */
typedef struct s_test_stats {
	int total_tests;
	int passed_tests;
	int failed_tests;
	int total_functions;
	int passed_functions;
	int failed_functions;
} t_test_stats;

/* Global statistics */
extern t_test_stats g_stats;

/* Global function context for tracing */
extern const char *g_current_function;

/* Global function counter for numbering */
extern int g_function_counter;

/* Flag to skip duplicate headers in isolated mode */
extern int g_isolated_mode;

/* Function prototypes */
void	print_header(const char *title);
void	print_function_header(const char *function_name);
void	print_test_result(const char *test_name, int passed, const char *details);
void	print_summary(void);
void	init_stats(void);
void	update_function_stats(int function_passed);

/* Test function declarations - Part 1 */
void	test_ft_isalpha(void);
void	test_ft_isdigit(void);
void	test_ft_isalnum(void);
void	test_ft_isascii(void);
void	test_ft_isprint(void);
void	test_ft_strlen(void);
void	test_ft_memset(void);
void	test_ft_bzero(void);
void	test_ft_memcpy(void);
void	test_ft_memmove(void);
void	test_ft_strlcpy(void);
void	test_ft_strlcat(void);
void	test_ft_toupper(void);
void	test_ft_tolower(void);
void	test_ft_strchr(void);
void	test_ft_strrchr(void);
void	test_ft_strncmp(void);
void	test_ft_memchr(void);
void	test_ft_memcmp(void);
void	test_ft_strnstr(void);
void	test_ft_atoi(void);

/* Test function declarations - Part 2 */
void	test_ft_calloc(void);
void	test_ft_strdup(void);
void	test_ft_substr(void);
void	test_ft_strjoin(void);
void	test_ft_strtrim(void);
void	test_ft_split(void);
void	test_ft_itoa(void);
void	test_ft_strmapi(void);
void	test_ft_striteri(void);
void	test_ft_putchar_fd(void);
void	test_ft_putstr_fd(void);
void	test_ft_putendl_fd(void);
void	test_ft_putnbr_fd(void);

/* Isolated test runner functions */
void	run_all_tests_isolated(void);
void	run_part1_tests_isolated(void);
void	run_part2_tests_isolated(void);

#endif
