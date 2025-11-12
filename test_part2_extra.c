#include "tester.h"
#include "libft.h"

void	test_ft_strtrim(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_strtrim");
	
	/* Test 1: Normal trim */
	total++;
	char *result = ft_strtrim("   Hello World   ", " ");
	if (result && strcmp(result, "Hello World") == 0)
	{
		print_test_result("Trim spaces from both ends", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Trim spaces from both ends", 0, "");
	free(result);
	
	/* Test 2: Nothing to trim */
	total++;
	result = ft_strtrim("Hello", " ");
	if (result && strcmp(result, "Hello") == 0)
	{
		print_test_result("Nothing to trim", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Nothing to trim", 0, "");
	free(result);
	
	/* Test 3: Trim multiple characters */
	total++;
	result = ft_strtrim("***Hello***", "*");
	if (result && strcmp(result, "Hello") == 0)
	{
		print_test_result("Trim multiple characters", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Trim multiple characters", 0, "");
	free(result);
	
	/* Test 4: Different trim set */
	total++;
	result = ft_strtrim("abc123abc", "abc");
	if (result && strcmp(result, "123") == 0)
	{
		print_test_result("Different trim set", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Different trim set", 0, "");
	free(result);
	
	/* Test 5: Everything trimmed */
	total++;
	result = ft_strtrim("aaaa", "a");
	if (result && strcmp(result, "") == 0)
	{
		print_test_result("Everything trimmed", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Everything trimmed", 0, "");
	free(result);
	
	/* Test 6: Empty string */
	total++;
	result = ft_strtrim("", " ");
	if (result && strcmp(result, "") == 0)
	{
		print_test_result("Empty string", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Empty string", 0, "");
	free(result);
	
	/* Test 7: Empty set */
	total++;
	result = ft_strtrim("  Hello  ", "");
	if (result && strcmp(result, "  Hello  ") == 0)
	{
		print_test_result("Empty trim set", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Empty trim set", 0, "");
	free(result);
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_split(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_split");
	
	/* Test 1: Normal split */
	total++;
	char **result = ft_split("Hello World Test", ' ');
	if (result && result[0] && result[1] && result[2] && !result[3] &&
		strcmp(result[0], "Hello") == 0 &&
		strcmp(result[1], "World") == 0 &&
		strcmp(result[2], "Test") == 0)
	{
		print_test_result("Normal split", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Normal split", 0, "");
	if (result)
	{
		for (int i = 0; result[i]; i++)
			free(result[i]);
		free(result);
	}
	
	/* Test 2: Multiple delimiters */
	total++;
	result = ft_split("Hello   World", ' ');
	if (result && result[0] && result[1] && !result[2] &&
		strcmp(result[0], "Hello") == 0 &&
		strcmp(result[1], "World") == 0)
	{
		print_test_result("Multiple consecutive delimiters", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Multiple consecutive delimiters", 0, "");
	if (result)
	{
		for (int i = 0; result[i]; i++)
			free(result[i]);
		free(result);
	}
	
	/* Test 3: Leading and trailing delimiters */
	total++;
	result = ft_split("  Hello  ", ' ');
	if (result && result[0] && !result[1] &&
		strcmp(result[0], "Hello") == 0)
	{
		print_test_result("Leading/trailing delimiters", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Leading/trailing delimiters", 0, "");
	if (result)
	{
		for (int i = 0; result[i]; i++)
			free(result[i]);
		free(result);
	}
	
	/* Test 4: Empty string */
	total++;
	result = ft_split("", ' ');
	if (result && !result[0])
	{
		print_test_result("Empty string", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Empty string", 0, "");
	if (result)
		free(result);
	
	/* Test 5: No delimiter found */
	total++;
	result = ft_split("Hello", ',');
	if (result && result[0] && !result[1] &&
		strcmp(result[0], "Hello") == 0)
	{
		print_test_result("No delimiter found", 1, "");
		tests_passed++;
	}
	else
		print_test_result("No delimiter found", 0, "");
	if (result)
	{
		for (int i = 0; result[i]; i++)
			free(result[i]);
		free(result);
	}
	
	/* Test 6: Single character */
	total++;
	result = ft_split("a", ' ');
	if (result && result[0] && !result[1] &&
		strcmp(result[0], "a") == 0)
	{
		print_test_result("Single character", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Single character", 0, "");
	if (result)
	{
		for (int i = 0; result[i]; i++)
			free(result[i]);
		free(result);
	}
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_itoa(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_itoa");
	
	/* Test 1: Positive number */
	total++;
	char *result = ft_itoa(42);
	if (result && strcmp(result, "42") == 0)
	{
		print_test_result("Positive number", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Positive number", 0, "");
	free(result);
	
	/* Test 2: Negative number */
	total++;
	result = ft_itoa(-42);
	if (result && strcmp(result, "-42") == 0)
	{
		print_test_result("Negative number", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Negative number", 0, "");
	free(result);
	
	/* Test 3: Zero */
	total++;
	result = ft_itoa(0);
	if (result && strcmp(result, "0") == 0)
	{
		print_test_result("Zero", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Zero", 0, "");
	free(result);
	
	/* Test 4: INT_MAX */
	total++;
	result = ft_itoa(2147483647);
	if (result && strcmp(result, "2147483647") == 0)
	{
		print_test_result("INT_MAX", 1, "");
		tests_passed++;
	}
	else
		print_test_result("INT_MAX", 0, "");
	free(result);
	
	/* Test 5: INT_MIN */
	total++;
	result = ft_itoa(-2147483648);
	if (result && strcmp(result, "-2147483648") == 0)
	{
		print_test_result("INT_MIN", 1, "");
		tests_passed++;
	}
	else
		print_test_result("INT_MIN", 0, "");
	free(result);
	
	/* Test 6: Single digit positive */
	total++;
	result = ft_itoa(7);
	if (result && strcmp(result, "7") == 0)
	{
		print_test_result("Single digit positive", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Single digit positive", 0, "");
	free(result);
	
	/* Test 7: Single digit negative */
	total++;
	result = ft_itoa(-7);
	if (result && strcmp(result, "-7") == 0)
	{
		print_test_result("Single digit negative", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Single digit negative", 0, "");
	free(result);
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

static char test_strmapi_func(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	test_ft_strmapi(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_strmapi");
	
	/* Test 1: Normal mapping */
	total++;
	char *result = ft_strmapi("hello", test_strmapi_func);
	if (result && strcmp(result, "HELLO") == 0)
	{
		print_test_result("Normal mapping (lowercase to uppercase)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Normal mapping (lowercase to uppercase)", 0, "");
	free(result);
	
	/* Test 2: Empty string */
	total++;
	result = ft_strmapi("", test_strmapi_func);
	if (result && strcmp(result, "") == 0)
	{
		print_test_result("Empty string", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Empty string", 0, "");
	free(result);
	
	/* Test 3: NULL function */
	total++;
	result = ft_strmapi("test", NULL);
	if (result == NULL)
	{
		print_test_result("NULL function", 1, "");
		tests_passed++;
	}
	else
	{
		print_test_result("NULL function", 0, "");
		free(result);
	}
	
	/* Test 4: Single character */
	total++;
	result = ft_strmapi("a", test_strmapi_func);
	if (result && strcmp(result, "A") == 0)
	{
		print_test_result("Single character", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Single character", 0, "");
	free(result);
	
	/* Test 5: Mixed case */
	total++;
	result = ft_strmapi("HeLLo", test_strmapi_func);
	if (result && strcmp(result, "HELLO") == 0)
	{
		print_test_result("Mixed case", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Mixed case", 0, "");
	free(result);
	
	/* Test 6: With numbers and special chars */
	total++;
	result = ft_strmapi("hello123!", test_strmapi_func);
	if (result && strcmp(result, "HELLO123!") == 0)
	{
		print_test_result("With numbers and special chars", 1, "");
		tests_passed++;
	}
	else
		print_test_result("With numbers and special chars", 0, "");
	free(result);
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

static void test_striteri_func(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

void	test_ft_striteri(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_striteri");
	
	/* Test 1: Normal iteration */
	total++;
	char str1[20] = "hello";
	ft_striteri(str1, test_striteri_func);
	if (strcmp(str1, "HELLO") == 0)
	{
		print_test_result("Normal iteration (lowercase to uppercase)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Normal iteration (lowercase to uppercase)", 0, "");
	
	/* Test 2: Empty string */
	total++;
	char str2[1] = "";
	ft_striteri(str2, test_striteri_func);
	if (strcmp(str2, "") == 0)
	{
		print_test_result("Empty string", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Empty string", 0, "");
	
	/* Test 3: NULL function */
	total++;
	char str3[20] = "test";
	ft_striteri(str3, NULL);
	if (strcmp(str3, "test") == 0)
	{
		print_test_result("NULL function (no crash, no change)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("NULL function (no crash, no change)", 0, "");
	
	/* Test 4: Single character */
	total++;
	char str4[2] = "a";
	ft_striteri(str4, test_striteri_func);
	if (strcmp(str4, "A") == 0)
	{
		print_test_result("Single character", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Single character", 0, "");
	
	/* Test 5: Mixed case */
	total++;
	char str5[20] = "HeLLo";
	ft_striteri(str5, test_striteri_func);
	if (strcmp(str5, "HELLO") == 0)
	{
		print_test_result("Mixed case", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Mixed case", 0, "");
	
	/* Test 6: With numbers and special chars */
	total++;
	char str6[20] = "hello123!";
	ft_striteri(str6, test_striteri_func);
	if (strcmp(str6, "HELLO123!") == 0)
	{
		print_test_result("With numbers and special chars", 1, "");
		tests_passed++;
	}
	else
		print_test_result("With numbers and special chars", 0, "");
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}
