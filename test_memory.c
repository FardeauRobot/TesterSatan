#include "tester.h"
#include "libft.h"

void	test_ft_memset(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_memset");
	
	/* Test 1: Normal memset */
	total++;
	char buf1[50], buf2[50];
	ft_memset(buf1, 'A', 10);
	memset(buf2, 'A', 10);
	if (memcmp(buf1, buf2, 10) == 0)
	{
		print_test_result("Set 10 bytes to 'A'", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Set 10 bytes to 'A'", 0, "");
	
	/* Test 2: Zero fill */
	total++;
	ft_memset(buf1, 0, 20);
	memset(buf2, 0, 20);
	if (memcmp(buf1, buf2, 20) == 0)
	{
		print_test_result("Zero fill", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Zero fill", 0, "");
	
	/* Test 3: Single byte */
	total++;
	ft_memset(buf1, 'X', 1);
	memset(buf2, 'X', 1);
	if (memcmp(buf1, buf2, 1) == 0)
	{
		print_test_result("Single byte", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Single byte", 0, "");
	
	/* Test 4: Large buffer */
	total++;
	char large1[500], large2[500];
	ft_memset(large1, 'Z', 500);
	memset(large2, 'Z', 500);
	if (memcmp(large1, large2, 500) == 0)
	{
		print_test_result("Large buffer (500 bytes)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Large buffer (500 bytes)", 0, "");
	
	/* Test 5: Return value */
	total++;
	char *ft_ret = (char *)ft_memset(buf1, 'B', 5);
	char *std_ret = (char *)memset(buf2, 'B', 5);
	if (ft_ret == buf1 && std_ret == buf2)
	{
		print_test_result("Return value (pointer to buffer)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Return value (pointer to buffer)", 0, "");
	
	/* Test 6: Extended ASCII value */
	total++;
	ft_memset(buf1, 200, 10);
	memset(buf2, 200, 10);
	if (memcmp(buf1, buf2, 10) == 0)
	{
		print_test_result("Extended ASCII value (200)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Extended ASCII value (200)", 0, "");
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_bzero(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_bzero");
	
	/* Test 1: Normal bzero */
	total++;
	char buf1[50], buf2[50];
	memset(buf1, 'A', 50);
	memset(buf2, 'A', 50);
	ft_bzero(buf1, 10);
	bzero(buf2, 10);
	if (memcmp(buf1, buf2, 50) == 0)
	{
		print_test_result("Zero 10 bytes", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Zero 10 bytes", 0, "");
	
	/* Test 2: Single byte */
	total++;
	memset(buf1, 'B', 50);
	memset(buf2, 'B', 50);
	ft_bzero(buf1, 1);
	bzero(buf2, 1);
	if (memcmp(buf1, buf2, 50) == 0)
	{
		print_test_result("Single byte", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Single byte", 0, "");
	
	/* Test 3: Entire buffer */
	total++;
	memset(buf1, 'C', 50);
	memset(buf2, 'C', 50);
	ft_bzero(buf1, 50);
	bzero(buf2, 50);
	if (memcmp(buf1, buf2, 50) == 0)
	{
		print_test_result("Entire buffer", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Entire buffer", 0, "");
	
	/* Test 4: Large buffer */
	total++;
	char large1[500], large2[500];
	memset(large1, 'D', 500);
	memset(large2, 'D', 500);
	ft_bzero(large1, 500);
	bzero(large2, 500);
	if (memcmp(large1, large2, 500) == 0)
	{
		print_test_result("Large buffer (500 bytes)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Large buffer (500 bytes)", 0, "");
	
	/* Test 5: Zero length (should not crash) */
	total++;
	memset(buf1, 'E', 50);
	memset(buf2, 'E', 50);
	ft_bzero(buf1, 0);
	bzero(buf2, (0));
	if (memcmp(buf1, buf2, 50) == 0)
	{
		print_test_result("Zero length (no change)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Zero length (no change)", 0, "");
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_memcpy(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_memcpy");
	
	/* Test 1: Normal copy */
	total++;
	char src[50] = "Hello World!";
	char dst1[50], dst2[50];
	ft_memcpy(dst1, src, 13);
	memcpy(dst2, src, 13);
	if (memcmp(dst1, dst2, 13) == 0)
	{
		print_test_result("Normal copy", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Normal copy", 0, "");
	
	/* Test 2: Copy with zeros */
	total++;
	char src2[20] = "Hello\0World";
	ft_memcpy(dst1, src2, 12);
	memcpy(dst2, src2, 12);
	if (memcmp(dst1, dst2, 12) == 0)
	{
		print_test_result("Copy with null bytes", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Copy with null bytes", 0, "");
	
	/* Test 3: Single byte */
	total++;
	ft_memcpy(dst1, src, 1);
	memcpy(dst2, src, 1);
	if (memcmp(dst1, dst2, 1) == 0)
	{
		print_test_result("Single byte", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Single byte", 0, "");
	
	/* Test 4: Large buffer */
	total++;
	char large_src[500];
	memset(large_src, 'A', 500);
	char large_dst1[500], large_dst2[500];
	ft_memcpy(large_dst1, large_src, 500);
	memcpy(large_dst2, large_src, 500);
	if (memcmp(large_dst1, large_dst2, 500) == 0)
	{
		print_test_result("Large buffer (500 bytes)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Large buffer (500 bytes)", 0, "");
	
	/* Test 5: Return value */
	total++;
	void *ft_ret = ft_memcpy(dst1, src, 5);
	void *std_ret = memcpy(dst2, src, 5);
	if (ft_ret == dst1 && std_ret == dst2)
	{
		print_test_result("Return value (pointer to dst)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Return value (pointer to dst)", 0, "");
	
	/* Test 6: Copy binary data */
	total++;
	unsigned char bin_src[10] = {0, 1, 255, 128, 64, 32, 16, 8, 4, 2};
	unsigned char bin_dst1[10], bin_dst2[10];
	ft_memcpy(bin_dst1, bin_src, 10);
	memcpy(bin_dst2, bin_src, 10);
	if (memcmp(bin_dst1, bin_dst2, 10) == 0)
	{
		print_test_result("Binary data", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Binary data", 0, "");
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_memmove(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_memmove");
	
	/* Test 1: Normal non-overlapping move */
	total++;
	char buf1[50] = "Hello World!";
	char buf2[50] = "Hello World!";
	char dst1[50], dst2[50];
	ft_memmove(dst1, buf1, 13);
	memmove(dst2, buf2, 13);
	if (memcmp(dst1, dst2, 13) == 0)
	{
		print_test_result("Non-overlapping move", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Non-overlapping move", 0, "");
	
	/* Test 2: Overlapping (dst < src) */
	total++;
	strcpy(buf1, "0123456789");
	strcpy(buf2, "0123456789");
	ft_memmove(buf1, buf1 + 3, 5);
	memmove(buf2, buf2 + 3, 5);
	if (strcmp(buf1, buf2) == 0)
	{
		print_test_result("Overlapping (dst < src)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Overlapping (dst < src)", 0, "");
	
	/* Test 3: Overlapping (dst > src) */
	total++;
	strcpy(buf1, "0123456789");
	strcpy(buf2, "0123456789");
	ft_memmove(buf1 + 3, buf1, 5);
	memmove(buf2 + 3, buf2, 5);
	if (strcmp(buf1, buf2) == 0)
	{
		print_test_result("Overlapping (dst > src)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Overlapping (dst > src)", 0, "");
	
	/* Test 4: Same source and destination */
	total++;
	strcpy(buf1, "Hello");
	strcpy(buf2, "Hello");
	ft_memmove(buf1, buf1, 5);
	memmove(buf2, buf2, 5);
	if (strcmp(buf1, buf2) == 0)
	{
		print_test_result("Same src and dst", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Same src and dst", 0, "");
	
	/* Test 5: Return value */
	total++;
	strcpy(buf1, "Test");
	void *ft_ret = ft_memmove(dst1, buf1, 5);
	void *std_ret = memmove(dst2, buf1, 5);
	if (ft_ret == dst1 && std_ret == dst2)
	{
		print_test_result("Return value (pointer to dst)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Return value (pointer to dst)", 0, "");
	
	/* Test 6: Large overlapping move */
	total++;
	char large1[500], large2[500];
	memset(large1, 'A', 500);
	memset(large2, 'A', 500);
	ft_memmove(large1 + 50, large1, 400);
	memmove(large2 + 50, large2, 400);
	if (memcmp(large1, large2, 500) == 0)
	{
		print_test_result("Large overlapping move", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Large overlapping move", 0, "");
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_memchr(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_memchr");
	
	/* Test 1: Character found */
	total++;
	const char *str = "Hello World";
	if (ft_memchr(str, 'W', 11) == memchr(str, 'W', 11))
	{
		print_test_result("Character found", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Character found", 0, "");
	
	/* Test 2: Character not found */
	total++;
	if (ft_memchr(str, 'x', 11) == memchr(str, 'x', 11))
	{
		print_test_result("Character not found", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Character not found", 0, "");
	
	/* Test 3: Search for null byte */
	total++;
	if (ft_memchr(str, '\0', 12) == memchr(str, '\0', 12))
	{
		print_test_result("Search for null byte", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Search for null byte", 0, "");
	
	/* Test 4: Length too short */
	total++;
	if (ft_memchr(str, 'W', 5) == memchr(str, 'W', 5))
	{
		print_test_result("Length too short", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Length too short", 0, "");
	
	/* Test 5: First byte match */
	total++;
	if (ft_memchr(str, 'H', 11) == memchr(str, 'H', 11))
	{
		print_test_result("First byte match", 1, "");
		tests_passed++;
	}
	else
		print_test_result("First byte match", 0, "");
	
	/* Test 6: Binary data */
	total++;
	unsigned char data[10] = {0, 1, 255, 128, 64, 32, 16, 8, 4, 2};
	if (ft_memchr(data, 255, 10) == memchr(data, 255, 10))
	{
		print_test_result("Binary data (value 255)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Binary data (value 255)", 0, "");
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_memcmp(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_memcmp");
	
	/* Test 1: Identical memory */
	total++;
	const char *s1 = "Hello";
	const char *s2 = "Hello";
	if (ft_memcmp(s1, s2, 5) == memcmp(s1, s2, 5))
	{
		print_test_result("Identical memory", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Identical memory", 0, "");
	
	/* Test 2: Different memory */
	total++;
	int ft_res = ft_memcmp("Hello", "World", 5);
	int std_res = memcmp("Hello", "World", 5);
	if ((ft_res == 0 && std_res == 0) || (ft_res < 0 && std_res < 0) || (ft_res > 0 && std_res > 0))
	{
		print_test_result("Different memory", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Different memory", 0, "");
	
	/* Test 3: Partial comparison */
	total++;
	if (ft_memcmp("Hello", "Help", 3) == memcmp("Hello", "Help", 3))
	{
		print_test_result("Partial comparison (first 3)", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Partial comparison (first 3)", 0, "");
	
	/* Test 4: With null bytes */
	total++;
	char data1[10] = "Hel\0lo";
	char data2[10] = "Hel\0lo";
	if (ft_memcmp(data1, data2, 7) == memcmp(data1, data2, 7))
	{
		print_test_result("With null bytes", 1, "");
		tests_passed++;
	}
	else
		print_test_result("With null bytes", 0, "");
	
	/* Test 5: Length = 0 */
	total++;
	if (ft_memcmp("Hello", "World", 0) == memcmp("Hello", "World", 0))
	{
		print_test_result("Length = 0", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Length = 0", 0, "");
	
	/* Test 6: Unsigned comparison */
	total++;
	unsigned char u1[5] = {1, 2, 3, 200, 5};
	unsigned char u2[5] = {1, 2, 3, 100, 5};
	ft_res = ft_memcmp(u1, u2, 5);
	std_res = memcmp(u1, u2, 5);
	if ((ft_res == 0 && std_res == 0) || (ft_res < 0 && std_res < 0) || (ft_res > 0 && std_res > 0))
	{
		print_test_result("Unsigned comparison", 1, "");
		tests_passed++;
	}
	else
		print_test_result("Unsigned comparison", 0, "");
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}
