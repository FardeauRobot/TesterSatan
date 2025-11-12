#include "advice.h"
#include <string.h>

/**
 * get_function_advice - Returns contextual advice based on function and test
 * 
 * Provides specific, actionable advice for each function's common mistakes
 */
const char *get_function_advice(const char *function_name, const char *test_name)
{
	if (!function_name || !test_name)
		return "Review your function logic and compare with expected output";

	/* Character functions */
	if (strcmp(function_name, "ft_isalpha") == 0)
		return "Remember: isalpha returns true ONLY for alphabetic characters (a-z, A-Z)";
	if (strcmp(function_name, "ft_isdigit") == 0)
		return "Remember: isdigit returns true ONLY for digits (0-9)";
	if (strcmp(function_name, "ft_isalnum") == 0)
		return "Remember: isalnum returns true for letters OR digits";
	if (strcmp(function_name, "ft_isascii") == 0)
		return "Remember: ASCII range is 0-127. Check your comparison operators";
	if (strcmp(function_name, "ft_isprint") == 0)
		return "Remember: printable ASCII is 32-126 (space to tilde)";
	if (strcmp(function_name, "ft_toupper") == 0)
		return "Remember: only convert lowercase letters. Return others unchanged";
	if (strcmp(function_name, "ft_tolower") == 0)
		return "Remember: only convert uppercase letters. Return others unchanged";

	/* String length */
	if (strcmp(function_name, "ft_strlen") == 0)
		return "Remember: count characters BEFORE the null terminator, don't include it";

	/* Copy functions */
	if (strcmp(function_name, "ft_strlcpy") == 0)
	{
		if (strstr(test_name, "buffer") || strstr(test_name, "size"))
			return "Remember: return value is length of SRC, not bytes copied. Always null-terminate if size > 0";
		return "Check: dst is null-terminated, return value = strlen(src)";
	}
	if (strcmp(function_name, "ft_strlcat") == 0)
	{
		if (strstr(test_name, "return"))
			return "Return value: initial strlen(dst) + strlen(src), NOT total length written";
		return "Remember: null-terminate only if size > strlen(dst). Return total length that would fit";
	}

	/* Search functions */
	if (strcmp(function_name, "ft_strchr") == 0)
	{
		if (strstr(test_name, "null") || strstr(test_name, "terminator"))
			return "Remember: strchr should find the EXACT byte, including '\\0' at the end";
		return "Remember: return pointer to FIRST occurrence, or NULL if not found";
	}
	if (strcmp(function_name, "ft_strrchr") == 0)
	{
		if (strstr(test_name, "null") || strstr(test_name, "empty"))
			return "Remember: strrchr searches from the END, including the null terminator";
		return "Remember: return pointer to LAST occurrence, or NULL if not found";
	}
	if (strcmp(function_name, "ft_strncmp") == 0)
	{
		if (strstr(test_name, "unsigned") || strstr(test_name, "comparison"))
			return "Remember: compare as UNSIGNED chars. Negative values should be >0, not <0";
		return "Remember: compare first N characters, handle all edge cases";
	}
	if (strcmp(function_name, "ft_strnstr") == 0)
	{
		if (strstr(test_name, "middle") || strstr(test_name, "needle"))
			return "Remember: search for substring within first LEN bytes, not entire string";
		return "Check: empty needle returns haystack, validate length parameter";
	}

	/* Memory functions */
	if (strcmp(function_name, "ft_memset") == 0)
		return "Remember: set VALUE byte (not 0) for N bytes. Return pointer to start";
	if (strcmp(function_name, "ft_bzero") == 0)
		return "Remember: set N bytes to 0. Return value doesn't matter (void function)";
	if (strcmp(function_name, "ft_memcpy") == 0)
		return "Remember: copy exactly N bytes. Don't assume null terminator. Return DST pointer";
	if (strcmp(function_name, "ft_memmove") == 0)
		return "Remember: handle overlapping regions correctly (copy from end if dst > src)";
	if (strcmp(function_name, "ft_memchr") == 0)
	{
		if (strstr(test_name, "null") || strstr(test_name, "byte"))
			return "Remember: search for exact BYTE value in memory, including 0xFF";
		return "Remember: search first N bytes only, return pointer or NULL";
	}
	if (strcmp(function_name, "ft_memcmp") == 0)
	{
		if (strstr(test_name, "unsigned") || strstr(test_name, "comparison"))
			return "Remember: compare as UNSIGNED chars. Check your sign handling";
		return "Remember: return <0, 0, or >0 based on first differing byte";
	}

	/* Conversion functions */
	if (strcmp(function_name, "ft_atoi") == 0)
	{
		if (strstr(test_name, "whitespace") || strstr(test_name, "space"))
			return "Remember: skip leading whitespace (space, tab, newline, etc.)";
		if (strstr(test_name, "sign") || strstr(test_name, "minus"))
			return "Remember: handle optional + or - sign after whitespace";
		return "Remember: stop at first non-digit, handle INT_MIN and INT_MAX";
	}

	/* Allocation functions */
	if (strcmp(function_name, "ft_calloc") == 0)
	{
		if (strstr(test_name, "zero") || strstr(test_name, "allocation"))
			return "Remember: allocate count*size bytes and ZERO all of them";
		return "Remember: return NULL on error or if count/size is 0";
	}
	if (strcmp(function_name, "ft_strdup") == 0)
		return "Remember: allocate new string and copy content. Null-terminate. Return NULL on error";

	/* String manipulation */
	if (strcmp(function_name, "ft_substr") == 0)
	{
		if (strstr(test_name, "length") || strstr(test_name, "exceed"))
			return "Remember: if start is beyond string, return empty string. Handle len > remaining";
		if (strstr(test_name, "beyond"))
			return "If start >= strlen(s), return empty allocated string";
		return "Allocate new string with start+len characters. Handle NULL allocations";
	}
	if (strcmp(function_name, "ft_strjoin") == 0)
		return "Remember: allocate for s1+s2 length. Copy both strings. Null-terminate. Return NULL on error";
	if (strcmp(function_name, "ft_strtrim") == 0)
	{
		if (strstr(test_name, "trim") || strstr(test_name, "space"))
			return "Remember: trim characters in SET from both start and end. Handle empty results";
		return "Allocate new string without leading/trailing chars from set";
	}
	if (strcmp(function_name, "ft_split") == 0)
	{
		if (strstr(test_name, "delimiter") || strstr(test_name, "consecutive"))
			return "Remember: treat consecutive delimiters as one. Allocate array+1 for NULL terminator";
		return "Allocate array of strings. NULL-terminate array. Handle each word independently";
	}
	if (strcmp(function_name, "ft_itoa") == 0)
	{
		if (strstr(test_name, "zero"))
			return "Remember: '0' should return '0', not empty string";
		if (strstr(test_name, "negative") || strstr(test_name, "minus"))
			return "Remember: include '-' sign for negative numbers";
		return "Convert int to string. Handle INT_MIN and INT_MAX carefully";
	}
	if (strcmp(function_name, "ft_strmapi") == 0)
		return "Remember: allocate new string. Call function(index, char). Null-terminate. Return NULL on error";
	if (strcmp(function_name, "ft_striteri") == 0)
		return "Remember: iterate through string, call function(index, &char). Modify string in place";

	/* File descriptor functions */
	if (strcmp(function_name, "ft_putchar_fd") == 0)
		return "Remember: write single char to file descriptor. Check write() return value";
	if (strcmp(function_name, "ft_putstr_fd") == 0)
		return "Remember: write entire string to fd. Handle NULL strings carefully";
	if (strcmp(function_name, "ft_putendl_fd") == 0)
		return "Remember: write string + newline to fd";
	if (strcmp(function_name, "ft_putnbr_fd") == 0)
		return "Remember: write integer as string to fd. Handle INT_MIN correctly";

	/* Default advice */
	return "Compare your output with expected output. Check edge cases and boundary conditions";
}
