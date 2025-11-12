#include "trace.h"
#include "tester.h"
#include <stdio.h>
#include <stdlib.h>

void	display_main_menu(void)
{
	printf("\n");
	printf("%s%s╔════════════════════════════════════════════════════════════════════════════════╗%s\n", 
		BOLD, BLUE, RESET);
	printf("%s%s║                                                                                ║%s\n", 
		BOLD, BLUE, RESET);
	printf("%s%s║                        LIBFT COMPREHENSIVE TESTER                              ║%s\n", 
		BOLD, BLUE, RESET);
	printf("%s%s║                              Interactive Mode                                  ║%s\n", 
		BOLD, BLUE, RESET);
	printf("%s%s║                                                                                ║%s\n", 
		BOLD, BLUE, RESET);
	printf("%s%s╚════════════════════════════════════════════════════════════════════════════════╝%s\n", 
		BOLD, BLUE, RESET);
	printf("\n");
	
	printf("%s%s┌─────────────────────────────── MENU OPTIONS ───────────────────────────────┐%s\n", 
		BOLD, CYAN, RESET);
	printf("%s%s│                                                                            │%s\n", 
		BOLD, CYAN, RESET);
	printf("%s%s│%s  %s1.%s 🧪 Run All Tests                                                     %s%s│%s\n", 
		BOLD, CYAN, RESET, YELLOW, RESET, BOLD, CYAN, RESET);
	printf("%s%s│%s     Execute complete test suite (Part 1 + Part 2)                        %s%s│%s\n", 
		BOLD, CYAN, RESET, BOLD, CYAN, RESET);
	printf("%s%s│                                                                            │%s\n", 
		BOLD, CYAN, RESET);
	printf("%s%s│%s  %s2.%s 📋 Run Part 1 Tests Only                                              %s%s│%s\n", 
		BOLD, CYAN, RESET, YELLOW, RESET, BOLD, CYAN, RESET);
	printf("%s%s│%s     Test only libc functions                                             %s%s│%s\n", 
		BOLD, CYAN, RESET, BOLD, CYAN, RESET);
	printf("%s%s│                                                                            │%s\n", 
		BOLD, CYAN, RESET);
	printf("%s%s│%s  %s3.%s 📋 Run Part 2 Tests Only                                              %s%s│%s\n", 
		BOLD, CYAN, RESET, YELLOW, RESET, BOLD, CYAN, RESET);
	printf("%s%s│%s     Test only additional functions                                       %s%s│%s\n", 
		BOLD, CYAN, RESET, BOLD, CYAN, RESET);
	printf("%s%s│                                                                            │%s\n", 
		BOLD, CYAN, RESET);
	printf("%s%s│%s  %s4.%s 📊 View Last Test Results                                              %s%s│%s\n", 
		BOLD, CYAN, RESET, YELLOW, RESET, BOLD, CYAN, RESET);
	printf("%s%s│%s     Display failures and advice from previous run                        %s%s│%s\n", 
		BOLD, CYAN, RESET, BOLD, CYAN, RESET);
	printf("%s%s│                                                                            │%s\n", 
		BOLD, CYAN, RESET);
	printf("%s%s│%s  %s5.%s 🗑️  Clear Trace History                                                %s%s│%s\n", 
		BOLD, CYAN, RESET, YELLOW, RESET, BOLD, CYAN, RESET);
	printf("%s%s│%s     Remove all saved failure traces                                      %s%s│%s\n", 
		BOLD, CYAN, RESET, BOLD, CYAN, RESET);
	printf("%s%s│                                                                            │%s\n", 
		BOLD, CYAN, RESET);
	printf("%s%s│%s  %s6.%s 📖 Help & Documentation                                                %s%s│%s\n", 
		BOLD, CYAN, RESET, YELLOW, RESET, BOLD, CYAN, RESET);
	printf("%s%s│%s     View usage instructions and tips                                     %s%s│%s\n", 
		BOLD, CYAN, RESET, BOLD, CYAN, RESET);
	printf("%s%s│                                                                            │%s\n", 
		BOLD, CYAN, RESET);
	printf("%s%s│%s  %s0.%s 🚪 Exit                                                                %s%s│%s\n", 
		BOLD, CYAN, RESET, YELLOW, RESET, BOLD, CYAN, RESET);
	printf("%s%s│                                                                            │%s\n", 
		BOLD, CYAN, RESET);
	printf("%s%s└────────────────────────────────────────────────────────────────────────────┘%s\n", 
		BOLD, CYAN, RESET);
	printf("\n%sEnter your choice (0-6): %s", BOLD, RESET);
}

int		get_user_choice(void)
{
	int choice;
	char buffer[100];
	
	if (fgets(buffer, sizeof(buffer), stdin) == NULL)
		return -1;
	
	if (sscanf(buffer, "%d", &choice) != 1)
		return -1;
	
	return choice;
}

static void	display_help(void)
{
	printf("\n%s%s╔════════════════════════════════════════════════════════════════════════════════╗%s\n", 
		BOLD, BLUE, RESET);
	printf("%s%s║                              HELP & DOCUMENTATION                              ║%s\n", 
		BOLD, BLUE, RESET);
	printf("%s%s╚════════════════════════════════════════════════════════════════════════════════╝%s\n\n", 
		BOLD, BLUE, RESET);
	
	printf("%s%sUnderstanding Test Results:%s\n", BOLD, CYAN, RESET);
	printf("  %s✓%s Green checkmark = Test passed\n", GREEN, RESET);
	printf("  %s✗%s Red X mark = Test failed\n", RED, RESET);
	printf("  %s[6/6]%s = Number of passed tests / Total tests\n\n", YELLOW, RESET);
	
	printf("%s%sWhen Tests Fail:%s\n", BOLD, CYAN, RESET);
	printf("  1. Check the failure trace (Option 4)\n");
	printf("  2. Read the advice provided for each failure\n");
	printf("  3. Fix the issues in your libft\n");
	printf("  4. Run tests again\n\n");
	
	printf("%s%sTrace System:%s\n", BOLD, CYAN, RESET);
	printf("  • Failures are automatically logged\n");
	printf("  • Traces persist between runs\n");
	printf("  • Each trace includes:\n");
	printf("    - Function and test name\n");
	printf("    - Expected vs actual output\n");
	printf("    - Specific advice to fix the issue\n");
	printf("  • Traces saved to: %s.libft_test_traces.log%s\n\n", YELLOW, RESET);
	
	printf("%s%sOffline Mode:%s\n", BOLD, CYAN, RESET);
	printf("  This tester works completely offline!\n");
	printf("  • No internet connection required\n");
	printf("  • All comparisons with standard libc\n");
	printf("  • Full functionality available locally\n\n");
	
	printf("%s%sTips:%s\n", BOLD, CYAN, RESET);
	printf("  • Test incrementally as you code\n");
	printf("  • Focus on one failing function at a time\n");
	printf("  • Read the advice - it's tailored to each failure\n");
	printf("  • Use valgrind to check for memory leaks\n");
	printf("  • Compare with man pages for edge cases\n\n");
	
	printf("Press Enter to continue...");
	getchar();
}

void	run_interactive_mode(void)
{
	int choice;
	int running = 1;
	
	init_trace_system();
	
	while (running)
	{
		display_main_menu();
		choice = get_user_choice();
		
		switch (choice)
		{
			case 1:
				printf("\n%s%sStarting complete test suite...%s\n\n", BOLD, GREEN, RESET);
				sleep(1);
				init_stats();
				clear_all_traces();
				
				// Run all tests (this will be called from main)
				extern void run_all_tests(void);
				run_all_tests();
				
				print_summary();
				save_traces_to_file();
				
				printf("\nPress Enter to continue...");
				getchar();
				break;
				
			case 2:
				printf("\n%s%sStarting Part 1 tests...%s\n\n", BOLD, GREEN, RESET);
				sleep(1);
				init_stats();
				clear_all_traces();
				
				extern void run_part1_tests(void);
				run_part1_tests();
				
				print_summary();
				save_traces_to_file();
				
				printf("\nPress Enter to continue...");
				getchar();
				break;
				
			case 3:
				printf("\n%s%sStarting Part 2 tests...%s\n\n", BOLD, GREEN, RESET);
				sleep(1);
				init_stats();
				clear_all_traces();
				
				extern void run_part2_tests(void);
				run_part2_tests();
				
				print_summary();
				save_traces_to_file();
				
				printf("\nPress Enter to continue...");
				getchar();
				break;
				
			case 4:
				display_last_traces();
				printf("Press Enter to continue...");
				getchar();
				break;
				
			case 5:
				clear_all_traces();
				printf("Press Enter to continue...");
				getchar();
				break;
				
			case 6:
				display_help();
				break;
				
			case 0:
				printf("\n%s%sThank you for using Libft Tester! Good luck! 🍀%s\n\n", 
					BOLD, GREEN, RESET);
				running = 0;
				break;
				
			default:
				printf("\n%s%sInvalid choice! Please enter a number between 0 and 6.%s\n", 
					BOLD, RED, RESET);
				sleep(2);
				break;
		}
	}
}
