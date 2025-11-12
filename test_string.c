#include "tester.h"
#include "libft.h"

void	test_ft_strlen(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_strlen");
	
	/* Test 1: Empty string */
	total++;
	if (ft_strlen("") == strlen(""))
	{
		print_test_result("Empty string", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Empty string", 0, "");
	
	/* Test 2: Single character */
	total++;
	if (ft_strlen("a") == strlen("a"))
	{
		print_test_result("Single character", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Single character", 0, "");
	
	/* Test 3: Normal string */
	total++;
	if (ft_strlen("Hello, World!") == strlen("Hello, World!"))
	{
		print_test_result("Normal string", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Normal string", 0, "");
	
	/* Test 4: String with spaces */
	total++;
	if (ft_strlen("   spaces   ") == strlen("   spaces   "))
	{
		print_test_result("String with spaces", 1, "");
		tests_passed++;
	}
	else
		print_test_result("String with spaces", 0, "");
	
	/* Test 5: String with special characters */
	total++;
	if (ft_strlen("!@#$%^&*()_+-=[]{}|;':\",./<>?") == strlen("!@#$%^&*()_+-=[]{}|;':\",./<>?"))
	{
		print_test_result("String with special characters", 1, "");
		tests_passed++;
	}
	else
		print_test_result("String with special characters", 0, "");
	
	/* Test 6: Long string */
	total++;
	char long_str[1000];
	memset(long_str, 'A', 999);
	long_str[999] = '\0';
	if (ft_strlen(long_str) == strlen(long_str))
	{
		print_test_result("Long string (999 chars)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Long string (999 chars)", 0, "");
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_toupper(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_toupper");
	
	/* Test 1: Lowercase letters */
	total++;
	if (ft_toupper('a') == toupper('a') && ft_toupper('z') == toupper('z'))
	{
		print_test_result("Lowercase letters (a, z)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Lowercase letters (a, z)", 0, "");
	
	/* Test 2: Uppercase letters */
	total++;
	if (ft_toupper('A') == toupper('A') && ft_toupper('Z') == toupper('Z'))
	{
		print_test_result("Uppercase letters (A, Z)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Uppercase letters (A, Z)", 0, "");
	
	/* Test 3: Digits */
	total++;
	if (ft_toupper('0') == toupper('0') && ft_toupper('9') == toupper('9'))
	{
		print_test_result("Digits (0, 9)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Digits (0, 9)", 0, "");
	
	/* Test 4: Special characters */
	total++;
	if (ft_toupper('!') == toupper('!') && ft_toupper('@') == toupper('@'))
	{
		print_test_result("Special characters (!, @)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Special characters (!, @)", 0, "");
	
	/* Test 5: Whitespace */
	total++;
	if (ft_toupper(' ') == toupper(' ') && ft_toupper('\t') == toupper('\t') && ft_toupper('\n') == toupper('\n'))
	{
		print_test_result("Whitespace (space, tab, newline)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Whitespace (space, tab, newline)", 0, "");
	
	/* Test 6: Extended ASCII */
	total++;
	if (ft_toupper(200) == toupper(200) && ft_toupper(150) == toupper(150))
	{
		print_test_result("Extended ASCII (200, 150)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Extended ASCII (200, 150)", 0, "");
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_tolower(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_tolower");
	
	/* Test 1: Uppercase letters */
	total++;
	if (ft_tolower('A') == tolower('A') && ft_tolower('Z') == tolower('Z'))
	{
		print_test_result("Uppercase letters (A, Z)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Uppercase letters (A, Z)", 0, "");
	
	/* Test 2: Lowercase letters */
	total++;
	if (ft_tolower('a') == tolower('a') && ft_tolower('z') == tolower('z'))
	{
		print_test_result("Lowercase letters (a, z)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Lowercase letters (a, z)", 0, "");
	
	/* Test 3: Digits */
	total++;
	if (ft_tolower('0') == tolower('0') && ft_tolower('9') == tolower('9'))
	{
		print_test_result("Digits (0, 9)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Digits (0, 9)", 0, "");
	
	/* Test 4: Special characters */
	total++;
	if (ft_tolower('!') == tolower('!') && ft_tolower('@') == tolower('@'))
	{
		print_test_result("Special characters (!, @)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Special characters (!, @)", 0, "");
	
	/* Test 5: Whitespace */
	total++;
	if (ft_tolower(' ') == tolower(' ') && ft_tolower('\t') == tolower('\t') && ft_tolower('\n') == tolower('\n'))
	{
		print_test_result("Whitespace (space, tab, newline)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Whitespace (space, tab, newline)", 0, "");
	
	/* Test 6: Extended ASCII */
	total++;
	if (ft_tolower(200) == tolower(200) && ft_tolower(150) == tolower(150))
	{
		print_test_result("Extended ASCII (200, 150)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Extended ASCII (200, 150)", 0, "");
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_strchr(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_strchr");
	
	/* Test 1: Character found at beginning */
	total++;
	const char *test1 = "Hello World";
	if (ft_strchr(test1, 'H') == strchr(test1, 'H'))
	{
		print_test_result("Character at beginning", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Character at beginning", 0, "");
	
	/* Test 2: Character found in middle */
	total++;
	if (ft_strchr(test1, 'o') == strchr(test1, 'o'))
	{
		print_test_result("Character in middle", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Character in middle", 0, "");
	
	/* Test 3: Character found at end */
	total++;
	if (ft_strchr(test1, 'd') == strchr(test1, 'd'))
	{
		print_test_result("Character at end", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Character at end", 0, "");
	
	/* Test 4: Character not found */
	total++;
	if (ft_strchr(test1, 'x') == strchr(test1, 'x'))
	{
		print_test_result("Character not found", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Character not found", 0, "");
	
	/* Test 5: Search for null terminator */
	total++;
	if (ft_strchr(test1, '\0') == strchr(test1, '\0'))
	{
		print_test_result("Search for null terminator", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Search for null terminator", 0, "");
	
	/* Test 6: Empty string */
	total++;
	const char *empty = "";
	if (ft_strchr(empty, 'a') == strchr(empty, 'a'))
	{
		print_test_result("Empty string", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Empty string", 0, "");
	
	/* Test 7: Multiple occurrences (should return first) */
	total++;
	const char *test7 = "banana";
	if (ft_strchr(test7, 'a') == strchr(test7, 'a'))
	{
		print_test_result("Multiple occurrences (returns first)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Multiple occurrences (returns first)", 0, "");
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_strrchr(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_strrchr");
	
	/* Test 1: Character found at end */
	total++;
	const char *test1 = "Hello World";
	if (ft_strrchr(test1, 'd') == strrchr(test1, 'd'))
	{
		print_test_result("Character at end", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Character at end", 0, "");
	
	/* Test 2: Character found in middle */
	total++;
	if (ft_strrchr(test1, 'o') == strrchr(test1, 'o'))
	{
		print_test_result("Character in middle", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Character in middle", 0, "");
	
	/* Test 3: Character found at beginning */
	total++;
	if (ft_strrchr(test1, 'H') == strrchr(test1, 'H'))
	{
		print_test_result("Character at beginning", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Character at beginning", 0, "");
	
	/* Test 4: Character not found */
	total++;
	if (ft_strrchr(test1, 'x') == strrchr(test1, 'x'))
	{
		print_test_result("Character not found", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Character not found", 0, "");
	
	/* Test 5: Search for null terminator */
	total++;
	if (ft_strrchr(test1, '\0') == strrchr(test1, '\0'))
	{
		print_test_result("Search for null terminator", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Search for null terminator", 0, "");
	
	/* Test 6: Multiple occurrences (should return last) */
	total++;
	const char *test6 = "banana";
	if (ft_strrchr(test6, 'a') == strrchr(test6, 'a'))
	{
		print_test_result("Multiple occurrences (returns last)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Multiple occurrences (returns last)", 0, "");
	
	/* Test 7: Empty string */
	total++;
	const char *empty = "";
	if (ft_strrchr(empty, 'a') == strrchr(empty, 'a'))
	{
		print_test_result("Empty string", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Empty string", 0, "");
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_strncmp(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_strncmp");
	
	/* Test 1: Identical strings */
	total++;
	if (ft_strncmp("Hello", "Hello", 5) == strncmp("Hello", "Hello", 5))
	{
		print_test_result("Identical strings", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Identical strings", 0, "");
	
	/* Test 2: Different strings */
	total++;
	int ft_res = ft_strncmp("Hello", "World", 5);
	int std_res = strncmp("Hello", "World", 5);
	if ((ft_res == 0 && std_res == 0) || (ft_res < 0 && std_res < 0) || (ft_res > 0 && std_res > 0))
	{
		print_test_result("Different strings", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Different strings", 0, "");
	
	/* Test 3: Partial comparison (n < length) */
	total++;
	if (ft_strncmp("Hello", "Help", 3) == strncmp("Hello", "Help", 3))
	{
		print_test_result("Partial comparison (first 3 chars)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Partial comparison (first 3 chars)", 0, "");
	
	/* Test 4: Empty strings */
	total++;
	if (ft_strncmp("", "", 1) == strncmp("", "", 1))
	{
		print_test_result("Empty strings", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Empty strings", 0, "");
	
	/* Test 5: One empty string */
	total++;
	ft_res = ft_strncmp("Hello", "", 5);
	std_res = strncmp("Hello", "", 5);
	if ((ft_res == 0 && std_res == 0) || (ft_res < 0 && std_res < 0) || (ft_res > 0 && std_res > 0))
	{
		print_test_result("One empty string", 1, "");
		tests_passed++;
	}
	else
		print_test_result("One empty string", 0, "");
	
	/* Test 6: n = 0 */
	total++;
	if (ft_strncmp("Hello", "World", 0) == strncmp("Hello", "World", 0))
	{
		print_test_result("Compare with n = 0", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Compare with n = 0", 0, "");
	
	/* Test 7: Unsigned char comparison */
	total++;
	ft_res = ft_strncmp("test\200", "test\0", 6);
	std_res = strncmp("test\200", "test\0", 6);
	if ((ft_res == 0 && std_res == 0) || (ft_res < 0 && std_res < 0) || (ft_res > 0 && std_res > 0))
	{
		print_test_result("Unsigned char comparison", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Unsigned char comparison", 0, "");
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}
