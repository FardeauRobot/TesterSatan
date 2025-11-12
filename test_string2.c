#include "tester.h"
#include "libft.h"

void	test_ft_strlcpy(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_strlcpy");
	
	/* Test 1: Normal copy */
	total++;
	char dst1[20], dst2[20];
	size_t ft_ret = ft_strlcpy(dst1, "Hello", 20);
	size_t std_ret = strlcpy(dst2, "Hello", 20);
	if (ft_ret == std_ret && strcmp(dst1, dst2) == 0)
	{
		print_test_result("Normal copy", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Normal copy", 0, "");
	
	/* Test 2: Buffer too small */
	total++;
	ft_ret = ft_strlcpy(dst1, "Hello World", 5);
	std_ret = strlcpy(dst2, "Hello World", 5);
	if (ft_ret == std_ret && strcmp(dst1, dst2) == 0)
	{
		print_test_result("Buffer too small", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Buffer too small", 0, "");
	
	/* Test 3: Size = 0 */
	total++;
	strcpy(dst1, "XXXXXXXXXX");
	strcpy(dst2, "XXXXXXXXXX");
	ft_ret = ft_strlcpy(dst1, "Hello", 0);
	std_ret = strlcpy(dst2, "Hello", 0);
	if (ft_ret == std_ret && strcmp(dst1, dst2) == 0)
	{
		print_test_result("Size = 0 (no copy)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Size = 0 (no copy)", 0, "");
	
	/* Test 4: Empty source */
	total++;
	ft_ret = ft_strlcpy(dst1, "", 20);
	std_ret = strlcpy(dst2, "", 20);
	if (ft_ret == std_ret && strcmp(dst1, dst2) == 0)
	{
		print_test_result("Empty source", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Empty source", 0, "");
	
	/* Test 5: Size = 1 (only null terminator) */
	total++;
	ft_ret = ft_strlcpy(dst1, "Hello", 1);
	std_ret = strlcpy(dst2, "Hello", 1);
	if (ft_ret == std_ret && strcmp(dst1, dst2) == 0)
	{
		print_test_result("Size = 1 (only null terminator)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Size = 1 (only null terminator)", 0, "");
	
	/* Test 6: Return value check */
	total++;
	ft_ret = ft_strlcpy(dst1, "Hello World", 20);
	std_ret = strlcpy(dst2, "Hello World", 20);
	if (ft_ret == std_ret && ft_ret == 11)
	{
		print_test_result("Return value (length of src)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Return value (length of src)", 0, "");
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_strlcat(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_strlcat");
	
	/* Test 1: Normal concatenation */
	total++;
	char dst1[20], dst2[20];
	strcpy(dst1, "Hello");
	strcpy(dst2, "Hello");
	size_t ft_ret = ft_strlcat(dst1, " World", 20);
	size_t std_ret = strlcat(dst2, " World", 20);
	if (ft_ret == std_ret && strcmp(dst1, dst2) == 0)
	{
		print_test_result("Normal concatenation", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Normal concatenation", 0, "");
	
	/* Test 2: Buffer too small */
	total++;
	strcpy(dst1, "Hello");
	strcpy(dst2, "Hello");
	ft_ret = ft_strlcat(dst1, " World", 10);
	std_ret = strlcat(dst2, " World", 10);
	if (ft_ret == std_ret && strcmp(dst1, dst2) == 0)
	{
		print_test_result("Buffer too small", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Buffer too small", 0, "");
	
	/* Test 3: Size <= initial dst length */
	total++;
	strcpy(dst1, "Hello");
	strcpy(dst2, "Hello");
	ft_ret = ft_strlcat(dst1, " World", 3);
	std_ret = strlcat(dst2, " World", 3);
	if (ft_ret == std_ret && strcmp(dst1, dst2) == 0)
	{
		print_test_result("Size <= dst length", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Size <= dst length", 0, "");
	
	/* Test 4: Empty source */
	total++;
	strcpy(dst1, "Hello");
	strcpy(dst2, "Hello");
	ft_ret = ft_strlcat(dst1, "", 20);
	std_ret = strlcat(dst2, "", 20);
	if (ft_ret == std_ret && strcmp(dst1, dst2) == 0)
	{
		print_test_result("Empty source", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Empty source", 0, "");
	
	/* Test 5: Empty destination */
	total++;
	dst1[0] = '\0';
	dst2[0] = '\0';
	ft_ret = ft_strlcat(dst1, "Hello", 20);
	std_ret = strlcat(dst2, "Hello", 20);
	if (ft_ret == std_ret && strcmp(dst1, dst2) == 0)
	{
		print_test_result("Empty destination", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Empty destination", 0, "");
	
	/* Test 6: Return value check */
	total++;
	strcpy(dst1, "Hello");
	strcpy(dst2, "Hello");
	ft_ret = ft_strlcat(dst1, " World", 20);
	std_ret = strlcat(dst2, " World", 20);
	if (ft_ret == std_ret && ft_ret == 11)
	{
		print_test_result("Return value check", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Return value check", 0, "");
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_strnstr(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_strnstr");
	
	/* Test 1: Needle found at beginning */
	total++;
	const char *haystack = "Hello World";
	if (ft_strnstr(haystack, "Hello", 11) == strnstr(haystack, "Hello", 11))
	{
		print_test_result("Needle at beginning", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Needle at beginning", 0, "");
	
	/* Test 2: Needle found in middle */
	total++;
	if (ft_strnstr(haystack, "World", 11) == strnstr(haystack, "World", 11))
	{
		print_test_result("Needle in middle", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Needle in middle", 0, "");
	
	/* Test 3: Needle not found */
	total++;
	if (ft_strnstr(haystack, "xyz", 11) == strnstr(haystack, "xyz", 11))
	{
		print_test_result("Needle not found", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Needle not found", 0, "");
	
	/* Test 4: Empty needle */
	total++;
	if (ft_strnstr(haystack, "", 11) == strnstr(haystack, "", 11))
	{
		print_test_result("Empty needle", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Empty needle", 0, "");
	
	/* Test 5: Len too short */
	total++;
	if (ft_strnstr(haystack, "World", 5) == strnstr(haystack, "World", 5))
	{
		print_test_result("Len too short to find needle", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Len too short to find needle", 0, "");
	
	/* Test 6: Needle longer than haystack */
	total++;
	if (ft_strnstr("Hi", "Hello", 10) == strnstr("Hi", "Hello", 10))
	{
		print_test_result("Needle longer than haystack", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Needle longer than haystack", 0, "");
	
	/* Test 7: Len = 0 */
	total++;
	if (ft_strnstr(haystack, "Hello", 0) == strnstr(haystack, "Hello", 0))
	{
		print_test_result("Len = 0", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Len = 0", 0, "");
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_atoi(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_atoi");
	
	/* Test 1: Positive number */
	total++;
	if (ft_atoi("42") == atoi("42"))
	{
		print_test_result("Positive number", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Positive number", 0, "");
	
	/* Test 2: Negative number */
	total++;
	if (ft_atoi("-42") == atoi("-42"))
	{
		print_test_result("Negative number", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Negative number", 0, "");
	
	/* Test 3: Zero */
	total++;
	if (ft_atoi("0") == atoi("0"))
	{
		print_test_result("Zero", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Zero", 0, "");
	
	/* Test 4: Leading whitespace */
	total++;
	if (ft_atoi("   123") == atoi("   123"))
	{
		print_test_result("Leading whitespace", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Leading whitespace", 0, "");
	
	/* Test 5: Plus sign */
	total++;
	if (ft_atoi("+42") == atoi("+42"))
	{
		print_test_result("Plus sign", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Plus sign", 0, "");
	
	/* Test 6: Non-numeric characters after number */
	total++;
	if (ft_atoi("123abc") == atoi("123abc"))
	{
		print_test_result("Non-numeric characters after", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Non-numeric characters after", 0, "");
	
	/* Test 7: INT_MAX */
	total++;
	if (ft_atoi("2147483647") == atoi("2147483647"))
	{
		print_test_result("INT_MAX", 1, "");
		tests_passed++;
	}
	else
		print_test_result("INT_MAX", 0, "");
	
	/* Test 8: INT_MIN */
	total++;
	if (ft_atoi("-2147483648") == atoi("-2147483648"))
	{
		print_test_result("INT_MIN", 1, "");
		tests_passed++;
	}
	else
		print_test_result("INT_MIN", 0, "");
	
	/* Test 9: Multiple signs */
	total++;
	if (ft_atoi("--42") == atoi("--42"))
	{
		print_test_result("Multiple signs", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Multiple signs", 0, "");
	
	/* Test 10: Only whitespace */
	total++;
	if (ft_atoi("   ") == atoi("   "))
	{
		print_test_result("Only whitespace", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Only whitespace", 0, "");
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}
