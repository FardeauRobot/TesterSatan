#include "tester.h"
#include "libft.h"

void	test_ft_isalpha(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_isalpha");
	
	/* Test 1: Lowercase letters */
	total++;
	if (!!ft_isalpha('a') == !!isalpha('a') && !!ft_isalpha('z') == !!isalpha('z'))
	{
		print_test_result("Lowercase letters (a, z)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Lowercase letters (a, z)", 0, "");
	
	/* Test 2: Uppercase letters */
	total++;
	if (!!ft_isalpha('A') == !!isalpha('A') && !!ft_isalpha('Z') == !!isalpha('Z'))
	{
		print_test_result("Uppercase letters (A, Z)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Uppercase letters (A, Z)", 0, "");
	
	/* Test 3: Digits */
	total++;
	if (!!ft_isalpha('0') == !!isalpha('0') && !!ft_isalpha('9') == !!isalpha('9'))
	{
		print_test_result("Digits (0, 9)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Digits (0, 9)", 0, "");
	
	/* Test 4: Special characters */
	total++;
	if (!!ft_isalpha('@') == !!isalpha('@') && !!ft_isalpha('!') == !!isalpha('!'))
	{
		print_test_result("Special characters (@, !)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Special characters (@, !)", 0, "");
	
	/* Test 5: Space and tab */
	total++;
	if (!!ft_isalpha(' ') == !!isalpha(' ') && !!ft_isalpha('\t') == !!isalpha('\t'))
	{
		print_test_result("Whitespace (space, tab)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Whitespace (space, tab)", 0, "");
	
	/* Test 6: Edge cases (before 'A', after 'Z', before 'a', after 'z') */
	total++;
	if (!!ft_isalpha('@') == !!isalpha('@') && !!ft_isalpha('[') == !!isalpha('[') &&
		!!ft_isalpha('`') == !!isalpha('`') && !!ft_isalpha('{') == !!isalpha('{'))
	{
		print_test_result("Boundary characters (@, [, `, {)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Boundary characters (@, [, `, {)", 0, "");
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_isdigit(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_isdigit");
	
	/* Test 1: All digits */
	total++;
	if (!!ft_isdigit('0') == !!isdigit('0') && !!ft_isdigit('5') == !!isdigit('5') && !!ft_isdigit('9') == !!isdigit('9'))
	{
		print_test_result("Digits (0, 5, 9)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Digits (0, 5, 9)", 0, "");
	
	/* Test 2: Letters */
	total++;
	if (!!ft_isdigit('a') == !!isdigit('a') && !!ft_isdigit('Z') == !!isdigit('Z'))
	{
		print_test_result("Letters (a, Z)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Letters (a, Z)", 0, "");
	
	/* Test 3: Special characters */
	total++;
	if (!!ft_isdigit('@') == !!isdigit('@') && !!ft_isdigit('#') == !!isdigit('#'))
	{
		print_test_result("Special characters (@, #)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Special characters (@, #)", 0, "");
	
	/* Test 4: Boundary characters (before '0', after '9') */
	total++;
	if (!!ft_isdigit('/') == !!isdigit('/') && !!ft_isdigit(':') == !!isdigit(':'))
	{
		print_test_result("Boundary characters (/, :)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Boundary characters (/, :)", 0, "");
	
	/* Test 5: Whitespace */
	total++;
	if (!!ft_isdigit(' ') == !!isdigit(' ') && !!ft_isdigit('\n') == !!isdigit('\n'))
	{
		print_test_result("Whitespace (space, newline)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Whitespace (space, newline)", 0, "");
	
	/* Test 6: Negative values and extended ASCII */
	total++;
	if (!!ft_isdigit(-1) == !!isdigit(-1) && !!ft_isdigit(200) == !!isdigit(200))
	{
		print_test_result("Out of range values (-1, 200)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Out of range values (-1, 200)", 0, "");
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_isalnum(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_isalnum");
	
	/* Test 1: Letters */
	total++;
	if (!!ft_isalnum('a') == !!isalnum('a') && !!ft_isalnum('Z') == !!isalnum('Z'))
	{
		print_test_result("Letters (a, Z)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Letters (a, Z)", 0, "");
	
	/* Test 2: Digits */
	total++;
	if (!!ft_isalnum('0') == !!isalnum('0') && !!ft_isalnum('9') == !!isalnum('9'))
	{
		print_test_result("Digits (0, 9)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Digits (0, 9)", 0, "");
	
	/* Test 3: Special characters */
	total++;
	if (!!ft_isalnum('@') == !!isalnum('@') && !!ft_isalnum('!') == !!isalnum('!'))
	{
		print_test_result("Special characters (@, !)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Special characters (@, !)", 0, "");
	
	/* Test 4: Whitespace */
	total++;
	if (!!ft_isalnum(' ') == !!isalnum(' ') && !!ft_isalnum('\t') == !!isalnum('\t'))
	{
		print_test_result("Whitespace (space, tab)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Whitespace (space, tab)", 0, "");
	
	/* Test 5: Boundary characters */
	total++;
	if (!!ft_isalnum('/') == !!isalnum('/') && !!ft_isalnum(':') == !!isalnum(':') &&
		!!ft_isalnum('[') == !!isalnum('[') && !!ft_isalnum('`') == !!isalnum('`'))
	{
		print_test_result("Boundary characters (/, :, [, `)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Boundary characters (/, :, [, `)", 0, "");
	
	/* Test 6: Extended ASCII */
	total++;
	if (!!ft_isalnum(127) == !!isalnum(127) && !!ft_isalnum(200) == !!isalnum(200))
	{
		print_test_result("Extended ASCII (127, 200)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Extended ASCII (127, 200)", 0, "");
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_isascii(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_isascii");
	
	/* Test 1: Valid ASCII range (0-127) */
	total++;
	if (!!ft_isascii(0) == !!isascii(0) && !!ft_isascii(65) == !!isascii(65) && !!ft_isascii(127) == !!isascii(127))
	{
		print_test_result("Valid ASCII (0, 65, 127)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Valid ASCII (0, 65, 127)", 0, "");
	
	/* Test 2: Below ASCII range */
	total++;
	if (!!ft_isascii(-1) == !!isascii(-1) && !!ft_isascii(-100) == !!isascii(-100))
	{
		print_test_result("Below ASCII range (-1, -100)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Below ASCII range (-1, -100)", 0, "");
	
	/* Test 3: Above ASCII range */
	total++;
	if (!!ft_isascii(128) == !!isascii(128) && !!ft_isascii(255) == !!isascii(255))
	{
		print_test_result("Above ASCII range (128, 255)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Above ASCII range (128, 255)", 0, "");
	
	/* Test 4: Control characters */
	total++;
	if (!!ft_isascii('\0') == !!isascii('\0') && !!ft_isascii('\n') == !!isascii('\n') && !!ft_isascii('\t') == !!isascii('\t'))
	{
		print_test_result("Control characters (\\0, \\n, \\t)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Control characters (\\0, \\n, \\t)", 0, "");
	
	/* Test 5: Printable characters */
	total++;
	if (!!ft_isascii('A') == !!isascii('A') && !!ft_isascii('z') == !!isascii('z') && !!ft_isascii('5') == !!isascii('5'))
	{
		print_test_result("Printable characters (A, z, 5)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Printable characters (A, z, 5)", 0, "");
	
	/* Test 6: Large values */
	total++;
	if (!!ft_isascii(300) == !!isascii(300) && !!ft_isascii(1000) == !!isascii(1000))
	{
		print_test_result("Large values (300, 1000)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Large values (300, 1000)", 0, "");
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_isprint(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_isprint");
	
	/* Test 1: Printable characters */
	total++;
	if (!!ft_isprint('A') == !!isprint('A') && !!ft_isprint('z') == !!isprint('z') && !!ft_isprint('5') == !!isprint('5'))
	{
		print_test_result("Letters and digits (A, z, 5)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Letters and digits (A, z, 5)", 0, "");
	
	/* Test 2: Special printable characters */
	total++;
	if (!!ft_isprint(' ') == !!isprint(' ') && !!ft_isprint('!') == !!isprint('!') && !!ft_isprint('~') == !!isprint('~'))
	{
		print_test_result("Special printable (space, !, ~)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Special printable (space, !, ~)", 0, "");
	
	/* Test 3: Control characters */
	total++;
	if (!!ft_isprint('\0') == !!isprint('\0') && !!ft_isprint('\n') == !!isprint('\n') && !!ft_isprint('\t') == !!isprint('\t'))
	{
		print_test_result("Control characters (\\0, \\n, \\t)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Control characters (\\0, \\n, \\t)", 0, "");
	
	/* Test 4: Boundary values (space=32, DEL=127) */
	total++;
	if (!!ft_isprint(31) == !!isprint(31) && !!ft_isprint(32) == !!isprint(32) && 
		!!ft_isprint(126) == !!isprint(126) && !!ft_isprint(127) == !!isprint(127))
	{
		print_test_result("Boundary values (31, 32, 126, 127)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Boundary values (31, 32, 126, 127)", 0, "");
	
	/* Test 5: Extended ASCII */
	total++;
	if (!!ft_isprint(128) == !!isprint(128) && !!ft_isprint(200) == !!isprint(200))
	{
		print_test_result("Extended ASCII (128, 200)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Extended ASCII (128, 200)", 0, "");
	
	/* Test 6: Negative values */
	total++;
	if (!!ft_isprint(-1) == !!isprint(-1) && !!ft_isprint(-50) == !!isprint(-50))
	{
		print_test_result("Negative values (-1, -50)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Negative values (-1, -50)", 0, "");
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}
