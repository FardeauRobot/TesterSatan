#include "trace.h"
#include <string.h>
#include <time.h>

#define MAX_TRACES 1000
#define TRACE_FILE ".libft_test_traces.log"

static t_trace g_traces[MAX_TRACES];
static int g_trace_count = 0;

void	init_trace_system(void)
{
	g_trace_count = 0;
	memset(g_traces, 0, sizeof(g_traces));
	load_traces_from_file();
}

void	log_failure(const char *function, const char *test, const char *expected, 
				const char *got, const char *advice)
{
	if (g_trace_count >= MAX_TRACES)
		return;
	
	t_trace *trace = &g_traces[g_trace_count];
	
	strncpy(trace->function_name, function, sizeof(trace->function_name) - 1);
	strncpy(trace->test_name, test, sizeof(trace->test_name) - 1);
	strncpy(trace->expected, expected, sizeof(trace->expected) - 1);
	strncpy(trace->got, got, sizeof(trace->got) - 1);
	strncpy(trace->advice, advice, sizeof(trace->advice) - 1);
	trace->timestamp = time(NULL);
	
	g_trace_count++;
}

void	save_traces_to_file(void)
{
	FILE *file = fopen(TRACE_FILE, "w");
	if (!file)
		return;
	
	fprintf(file, "╔═══════════════════════════════════════════════════════════════╗\n");
	fprintf(file, "║           LIBFT TESTER - CRASH & FAILURE REPORT              ║\n");
	fprintf(file, "╠═══════════════════════════════════════════════════════════════╣\n");
	fprintf(file, "║  Total Failures: %-3d                                         ║\n", g_trace_count);
	fprintf(file, "╚═══════════════════════════════════════════════════════════════╝\n\n");
	
	for (int i = 0; i < g_trace_count; i++)
	{
		t_trace *trace = &g_traces[i];
		fprintf(file, "┌───────────────────────────────────────────────────────────────┐\n");
		fprintf(file, "│ FAILURE #%-3d                                                 │\n", i + 1);
		fprintf(file, "├───────────────────────────────────────────────────────────────┤\n");
		fprintf(file, "│ Function: %-51s │\n", trace->function_name);
		fprintf(file, "│ Test:     %-51s │\n", trace->test_name);
		fprintf(file, "└───────────────────────────────────────────────────────────────┘\n\n");
		fprintf(file, "  📋 DETAILS:\n");
		fprintf(file, "    Expected: %s\n", trace->expected);
		fprintf(file, "    Got:      %s\n\n", trace->got);
		fprintf(file, "  💡 ADVICE:\n");
		fprintf(file, "    %s\n\n", trace->advice);
		fprintf(file, "═══════════════════════════════════════════════════════════════\n\n");
	}
	
	fclose(file);
}

void	load_traces_from_file(void)
{
	// For now, we start fresh each time
	// Could be extended to load previous traces if needed
}

void	display_last_traces(void)
{
	if (g_trace_count == 0)
	{
		printf("\n%s%s🎉 No failures logged! All tests passed in the last run! 🎉%s\n\n", 
			BOLD, GREEN, RESET);
		return;
	}
	
	printf("\n%s%s╔════════════════════════════════════════════════════════════════════════════════╗%s\n", 
		BOLD, RED, RESET);
	printf("%s%s║                            FAILURE TRACE REPORT                                ║%s\n", 
		BOLD, RED, RESET);
	printf("%s%s║                         Total Failures: %-3d                                    ║%s\n", 
		BOLD, RED, g_trace_count, RESET);
	printf("%s%s╚════════════════════════════════════════════════════════════════════════════════╝%s\n\n", 
		BOLD, RED, RESET);
	
	for (int i = 0; i < g_trace_count; i++)
	{
		t_trace *trace = &g_traces[i];
		
		printf("%s%s┌────────────────────────────────────────────────────────────────────────────────┐%s\n", 
			BOLD, YELLOW, RESET);
		printf("%s%s│ FAILURE #%-3d                                                                   │%s\n", 
			BOLD, YELLOW, i + 1, RESET);
		printf("%s%s└────────────────────────────────────────────────────────────────────────────────┘%s\n", 
			BOLD, YELLOW, RESET);
		
		printf("  %sFunction:%s  %s%s%s\n", CYAN, RESET, BOLD, trace->function_name, RESET);
		printf("  %sTest:%s      %s\n", CYAN, RESET, trace->test_name);
		printf("  %sTime:%s      %s", CYAN, RESET, ctime(&trace->timestamp));
		printf("\n");
		
		printf("  %s%sExpected:%s %s\n", BOLD, GREEN, RESET, trace->expected);
		printf("  %s%sGot:%s      %s\n", BOLD, RED, RESET, trace->got);
		printf("\n");
		
		printf("  %s%s💡 ADVICE:%s\n", BOLD, BLUE, RESET);
		printf("  %s%s%s\n", DIM, trace->advice, RESET);
		printf("\n");
	}
	
	printf("%s%s════════════════════════════════════════════════════════════════════════════════%s\n", 
		BOLD, RED, RESET);
	printf("%sSaved to: %s%s\n\n", DIM, TRACE_FILE, RESET);
}

void	clear_all_traces(void)
{
	g_trace_count = 0;
	memset(g_traces, 0, sizeof(g_traces));
	remove(TRACE_FILE);
	printf("\n%s✓ All traces cleared!%s\n\n", GREEN, RESET);
}

int		get_trace_count(void)
{
	return g_trace_count;
}
