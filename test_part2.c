#include "tester.h"
#include "libft.h"

void	test_ft_calloc(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_calloc");
	
	/* Test 1: Normal allocation */
	total++;
	int *ft_arr = (int *)ft_calloc(10, sizeof(int));
	int *std_arr = (int *)calloc(10, sizeof(int));
	int passed = 1;
	if (ft_arr && std_arr)
	{
		for (int i = 0; i < 10; i++)
		{
			if (ft_arr[i] != std_arr[i])
			{
				passed = 0;
				break;
			}
		}
	}
	else
		passed = 0;
	if (passed)
		print_test_result("Normal allocation (10 ints)", 1, "");
	else
		print_test_result("Normal allocation (10 ints)", 0, "");
	if (passed)
		tests_passed++;
	free(ft_arr);
	free(std_arr);
	
	/* Test 2: Zero count */
	total++;
	void *ft_ptr = ft_calloc(0, sizeof(int));
	void *std_ptr = calloc(0, sizeof(int));
	if ((ft_ptr == NULL && std_ptr == NULL) || (ft_ptr != NULL && std_ptr != NULL))
	{
		print_test_result("Zero count", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Zero count", 0, "");
	free(ft_ptr);
	free(std_ptr);
	
	/* Test 3: Zero size */
	total++;
	ft_ptr = ft_calloc(10, 0);
	std_ptr = calloc(10, 0);
	if ((ft_ptr == NULL && std_ptr == NULL) || (ft_ptr != NULL && std_ptr != NULL))
	{
		print_test_result("Zero size", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Zero size", 0, "");
	free(ft_ptr);
	free(std_ptr);
	
	/* Test 4: Single byte allocation */
	total++;
	char *ft_byte = (char *)ft_calloc(1, 1);
	char *std_byte = (char *)calloc(1, 1);
	if (ft_byte && std_byte && *ft_byte == *std_byte)
	{
		print_test_result("Single byte allocation", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Single byte allocation", 0, "");
	free(ft_byte);
	free(std_byte);
	
	/* Test 5: Large allocation */
	total++;
	char *ft_large = (char *)ft_calloc(1000, sizeof(char));
	char *std_large = (char *)calloc(1000, sizeof(char));
	passed = 1;
	if (ft_large && std_large)
	{
		for (int i = 0; i < 1000; i++)
		{
			if (ft_large[i] != 0)
			{
				passed = 0;
				break;
			}
		}
	}
	else
		passed = 0;
	if (passed)
	{
		print_test_result("Large allocation (1000 bytes zeroed)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Large allocation (1000 bytes zeroed)", 0, "");
	free(ft_large);
	free(std_large);
	
	/* Test 6: Multiple element types */
	total++;
	double *ft_dbl = (double *)ft_calloc(5, sizeof(double));
	double *std_dbl = (double *)calloc(5, sizeof(double));
	passed = 1;
	if (ft_dbl && std_dbl)
	{
		for (int i = 0; i < 5; i++)
		{
			if (ft_dbl[i] != std_dbl[i])
			{
				passed = 0;
				break;
			}
		}
	}
	else
		passed = 0;
	if (passed)
	{
		print_test_result("Double array allocation", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Double array allocation", 0, "");
	free(ft_dbl);
	free(std_dbl);
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_strdup(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_strdup");
	
	/* Test 1: Normal string */
	total++;
	char *ft_dup = ft_strdup("Hello World");
	char *std_dup = strdup("Hello World");
	if (ft_dup && std_dup && strcmp(ft_dup, std_dup) == 0)
	{
		print_test_result("Normal string", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Normal string", 0, "");
	free(ft_dup);
	free(std_dup);
	
	/* Test 2: Empty string */
	total++;
	ft_dup = ft_strdup("");
	std_dup = strdup("");
	if (ft_dup && std_dup && strcmp(ft_dup, std_dup) == 0)
	{
		print_test_result("Empty string", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Empty string", 0, "");
	free(ft_dup);
	free(std_dup);
	
	/* Test 3: String with special characters */
	total++;
	ft_dup = ft_strdup("!@#$%^&*()");
	std_dup = strdup("!@#$%^&*()");
	if (ft_dup && std_dup && strcmp(ft_dup, std_dup) == 0)
	{
		print_test_result("Special characters", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Special characters", 0, "");
	free(ft_dup);
	free(std_dup);
	
	/* Test 4: Long string */
	total++;
	char long_str[500];
	memset(long_str, 'A', 499);
	long_str[499] = '\0';
	ft_dup = ft_strdup(long_str);
	std_dup = strdup(long_str);
	if (ft_dup && std_dup && strcmp(ft_dup, std_dup) == 0)
	{
		print_test_result("Long string (499 chars)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Long string (499 chars)", 0, "");
	free(ft_dup);
	free(std_dup);
	
	/* Test 5: String with spaces */
	total++;
	ft_dup = ft_strdup("   spaces   ");
	std_dup = strdup("   spaces   ");
	if (ft_dup && std_dup && strcmp(ft_dup, std_dup) == 0)
	{
		print_test_result("String with spaces", 1, "");
		tests_passed++;
	}
	else
		print_test_result("String with spaces", 0, "");
	free(ft_dup);
	free(std_dup);
	
	/* Test 6: Single character */
	total++;
	ft_dup = ft_strdup("X");
	std_dup = strdup("X");
	if (ft_dup && std_dup && strcmp(ft_dup, std_dup) == 0)
	{
		print_test_result("Single character", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Single character", 0, "");
	free(ft_dup);
	free(std_dup);
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_substr(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_substr");
	
	/* Test 1: Normal substring */
	total++;
	char *result = ft_substr("Hello World", 6, 5);
	if (result && strcmp(result, "World") == 0)
	{
		print_test_result("Normal substring", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Normal substring", 0, "");
	free(result);
	
	/* Test 2: Substring from beginning */
	total++;
	result = ft_substr("Hello World", 0, 5);
	if (result && strcmp(result, "Hello") == 0)
	{
		print_test_result("Substring from beginning", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Substring from beginning", 0, "");
	free(result);
	
	/* Test 3: Start beyond string length */
	total++;
	result = ft_substr("Hello", 10, 5);
	if (result && strcmp(result, "") == 0)
	{
		print_test_result("Start beyond string length", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Start beyond string length", 0, "");
	free(result);
	
	/* Test 4: Length longer than remaining string */
	total++;
	result = ft_substr("Hello", 2, 100);
	if (result && strcmp(result, "llo") == 0)
	{
		print_test_result("Length exceeds string", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Length exceeds string", 0, "");
	free(result);
	
	/* Test 5: Empty string */
	total++;
	result = ft_substr("", 0, 5);
	if (result && strcmp(result, "") == 0)
	{
		print_test_result("Empty string", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Empty string", 0, "");
	free(result);
	
	/* Test 6: Length = 0 */
	total++;
	result = ft_substr("Hello", 0, 0);
	if (result && strcmp(result, "") == 0)
	{
		print_test_result("Length = 0", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Length = 0", 0, "");
	free(result);
	
	/* Test 7: Single character */
	total++;
	result = ft_substr("Hello", 1, 1);
	if (result && strcmp(result, "e") == 0)
	{
		print_test_result("Single character", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Single character", 0, "");
	free(result);
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_strjoin(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_strjoin");
	
	/* Test 1: Normal join */
	total++;
	char *result = ft_strjoin("Hello ", "World");
	if (result && strcmp(result, "Hello World") == 0)
	{
		print_test_result("Normal join", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Normal join", 0, "");
	free(result);
	
	/* Test 2: First string empty */
	total++;
	result = ft_strjoin("", "World");
	if (result && strcmp(result, "World") == 0)
	{
		print_test_result("First string empty", 1, "");
		tests_passed++;
	}
	else
		print_test_result("First string empty", 0, "");
	free(result);
	
	/* Test 3: Second string empty */
	total++;
	result = ft_strjoin("Hello", "");
	if (result && strcmp(result, "Hello") == 0)
	{
		print_test_result("Second string empty", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Second string empty", 0, "");
	free(result);
	
	/* Test 4: Both strings empty */
	total++;
	result = ft_strjoin("", "");
	if (result && strcmp(result, "") == 0)
	{
		print_test_result("Both strings empty", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Both strings empty", 0, "");
	free(result);
	
	/* Test 5: Long strings */
	total++;
	char long1[100], long2[100];
	memset(long1, 'A', 99);
	long1[99] = '\0';
	memset(long2, 'B', 99);
	long2[99] = '\0';
	result = ft_strjoin(long1, long2);
	if (result && strlen(result) == 198)
	{
		print_test_result("Long strings", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Long strings", 0, "");
	free(result);
	
	/* Test 6: Special characters */
	total++;
	result = ft_strjoin("42 ", "@#$%");
	if (result && strcmp(result, "42 @#$%") == 0)
	{
		print_test_result("Special characters", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Special characters", 0, "");
	free(result);
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}
