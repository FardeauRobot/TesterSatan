#ifndef TRACE_H
# define TRACE_H

# include "tester.h"
# include <time.h>

/* Trace structure for logging test failures */
typedef struct s_trace {
	char function_name[100];
	char test_name[200];
	char expected[500];
	char got[500];
	char advice[1000];
	time_t timestamp;
} t_trace;

/* Trace management functions */
void	init_trace_system(void);
void	log_failure(const char *function, const char *test, const char *expected, 
				const char *got, const char *advice);
void	save_traces_to_file(void);
void	load_traces_from_file(void);
void	display_last_traces(void);
void	clear_all_traces(void);
int		get_trace_count(void);

/* Menu system */
void	display_main_menu(void);
int		get_user_choice(void);
void	run_interactive_mode(void);

#endif
