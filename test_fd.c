#include "tester.h"
#include "libft.h"
#include <fcntl.h>

void	test_ft_putchar_fd(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_putchar_fd");
	
	/* Test 1: Write to file */
	total++;
	int fd = open("test_putchar.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putchar_fd('A', fd);
		ft_putchar_fd('B', fd);
		ft_putchar_fd('C', fd);
		close(fd);
		
		fd = open("test_putchar.txt", O_RDONLY);
		char buf[4];
		int bytes = read(fd, buf, 3);
		buf[bytes] = '\0';
		close(fd);
		
		if (strcmp(buf, "ABC") == 0)
		{
			print_test_result("Write to file", 1, "");
			tests_passed++;
		}
		else
			print_test_result("Write to file", 0, "");
		unlink("test_putchar.txt");
	}
	else
		print_test_result("Write to file", 0, "(failed to open file)");
	
	/* Test 2: Special characters */
	total++;
	fd = open("test_putchar.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putchar_fd('!', fd);
		ft_putchar_fd('@', fd);
		ft_putchar_fd('#', fd);
		close(fd);
		
		fd = open("test_putchar.txt", O_RDONLY);
		char buf[4];
		int bytes = read(fd, buf, 3);
		buf[bytes] = '\0';
		close(fd);
		
		if (strcmp(buf, "!@#") == 0)
		{
			print_test_result("Special characters", 1, "");
			tests_passed++;
		}
		else
			print_test_result("Special characters", 0, "");
		unlink("test_putchar.txt");
	}
	else
		print_test_result("Special characters", 0, "(failed to open file)");
	
	/* Test 3: Newline character */
	total++;
	fd = open("test_putchar.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putchar_fd('A', fd);
		ft_putchar_fd('\n', fd);
		ft_putchar_fd('B', fd);
		close(fd);
		
		fd = open("test_putchar.txt", O_RDONLY);
		char buf[4];
		int bytes = read(fd, buf, 3);
		close(fd);
		
		if (bytes == 3 && buf[0] == 'A' && buf[1] == '\n' && buf[2] == 'B')
		{
			print_test_result("Newline character", 1, "");
			tests_passed++;
		}
		else
			print_test_result("Newline character", 0, "");
		unlink("test_putchar.txt");
	}
	else
		print_test_result("Newline character", 0, "(failed to open file)");
	
	/* Test 4: Write to stdout (visual check) */
	total++;
	printf("%s      Manual test - should print 'X': ", DIM);
	ft_putchar_fd('X', 1);
	printf("%s\n", RESET);
	print_test_result("Write to stdout (visual check)", 1, "");
	tests_passed++;
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_putstr_fd(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_putstr_fd");
	
	/* Test 1: Normal string to file */
	total++;
	int fd = open("test_putstr.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putstr_fd("Hello World", fd);
		close(fd);
		
		fd = open("test_putstr.txt", O_RDONLY);
		char buf[50];
		int bytes = read(fd, buf, 49);
		buf[bytes] = '\0';
		close(fd);
		
		if (strcmp(buf, "Hello World") == 0)
		{
			print_test_result("Normal string to file", 1, "");
			tests_passed++;
		}
		else
			print_test_result("Normal string to file", 0, "");
		unlink("test_putstr.txt");
	}
	else
		print_test_result("Normal string to file", 0, "(failed to open file)");
	
	/* Test 2: Empty string */
	total++;
	fd = open("test_putstr.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putstr_fd("", fd);
		close(fd);
		
		fd = open("test_putstr.txt", O_RDONLY);
		char buf[50];
		int bytes = read(fd, buf, 49);
		close(fd);
		
		if (bytes == 0)
		{
			print_test_result("Empty string", 1, "");
			tests_passed++;
		}
		else
			print_test_result("Empty string", 0, "");
		unlink("test_putstr.txt");
	}
	else
		print_test_result("Empty string", 0, "(failed to open file)");
	
	/* Test 3: String with newlines */
	total++;
	fd = open("test_putstr.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putstr_fd("Line1\nLine2\nLine3", fd);
		close(fd);
		
		fd = open("test_putstr.txt", O_RDONLY);
		char buf[50];
		int bytes = read(fd, buf, 49);
		buf[bytes] = '\0';
		close(fd);
		
		if (strcmp(buf, "Line1\nLine2\nLine3") == 0)
		{
			print_test_result("String with newlines", 1, "");
			tests_passed++;
		}
		else
			print_test_result("String with newlines", 0, "");
		unlink("test_putstr.txt");
	}
	else
		print_test_result("String with newlines", 0, "(failed to open file)");
	
	/* Test 4: NULL string (should not crash) */
	total++;
	fd = open("test_putstr.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putstr_fd(NULL, fd);
		close(fd);
		print_test_result("NULL string (no crash)", 1, "");
		tests_passed++;
		unlink("test_putstr.txt");
	}
	else
		print_test_result("NULL string (no crash)", 0, "(failed to open file)");
	
	/* Test 5: Write to stdout (visual check) */
	total++;
	printf("%s      Manual test - should print 'TEST': ", DIM);
	ft_putstr_fd("TEST", 1);
	printf("%s\n", RESET);
	print_test_result("Write to stdout (visual check)", 1, "");
	tests_passed++;
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_putendl_fd(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_putendl_fd");
	
	/* Test 1: Normal string to file */
	total++;
	int fd = open("test_putendl.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putendl_fd("Hello", fd);
		close(fd);
		
		fd = open("test_putendl.txt", O_RDONLY);
		char buf[50];
		int bytes = read(fd, buf, 49);
		close(fd);
		
		if (bytes == 6 && buf[0] == 'H' && buf[5] == '\n')
		{
			print_test_result("Normal string with newline", 1, "");
			tests_passed++;
		}
		else
			print_test_result("Normal string with newline", 0, "");
		unlink("test_putendl.txt");
	}
	else
		print_test_result("Normal string with newline", 0, "(failed to open file)");
	
	/* Test 2: Empty string */
	total++;
	fd = open("test_putendl.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putendl_fd("", fd);
		close(fd);
		
		fd = open("test_putendl.txt", O_RDONLY);
		char buf[50];
		int bytes = read(fd, buf, 49);
		close(fd);
		
		if (bytes == 1 && buf[0] == '\n')
		{
			print_test_result("Empty string with newline", 1, "");
			tests_passed++;
		}
		else
			print_test_result("Empty string with newline", 0, "");
		unlink("test_putendl.txt");
	}
	else
		print_test_result("Empty string with newline", 0, "(failed to open file)");
	
	/* Test 3: Multiple lines */
	total++;
	fd = open("test_putendl.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putendl_fd("Line1", fd);
		ft_putendl_fd("Line2", fd);
		close(fd);
		
		fd = open("test_putendl.txt", O_RDONLY);
		char buf[50];
		int bytes = read(fd, buf, 49);
		buf[bytes] = '\0';
		close(fd);
		
		if (strcmp(buf, "Line1\nLine2\n") == 0)
		{
			print_test_result("Multiple lines", 1, "");
			tests_passed++;
		}
		else
			print_test_result("Multiple lines", 0, "");
		unlink("test_putendl.txt");
	}
	else
		print_test_result("Multiple lines", 0, "(failed to open file)");
	
	/* Test 4: NULL string (should not crash) */
	total++;
	fd = open("test_putendl.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putendl_fd(NULL, fd);
		close(fd);
		print_test_result("NULL string (no crash)", 1, "");
		tests_passed++;
		unlink("test_putendl.txt");
	}
	else
		print_test_result("NULL string (no crash)", 0, "(failed to open file)");
	
	/* Test 5: Write to stdout (visual check) */
	total++;
	printf("%s      Manual test - should print 'TEST' with newline: ", DIM);
	ft_putendl_fd("TEST", 1);
	printf("%s", RESET);
	print_test_result("Write to stdout (visual check)", 1, "");
	tests_passed++;
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}

void	test_ft_putnbr_fd(void)
{
	int tests_passed = 0;
	int total = 0;
	char details[100];
	
	print_function_header("ft_putnbr_fd");
	
	/* Test 1: Positive number */
	total++;
	int fd = open("test_putnbr.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putnbr_fd(42, fd);
		close(fd);
		
		fd = open("test_putnbr.txt", O_RDONLY);
		char buf[50];
		int bytes = read(fd, buf, 49);
		buf[bytes] = '\0';
		close(fd);
		
		if (strcmp(buf, "42") == 0)
		{
			print_test_result("Positive number", 1, "");
			tests_passed++;
		}
		else
			print_test_result("Positive number", 0, "");
		unlink("test_putnbr.txt");
	}
	else
		print_test_result("Positive number", 0, "(failed to open file)");
	
	/* Test 2: Negative number */
	total++;
	fd = open("test_putnbr.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putnbr_fd(-42, fd);
		close(fd);
		
		fd = open("test_putnbr.txt", O_RDONLY);
		char buf[50];
		int bytes = read(fd, buf, 49);
		buf[bytes] = '\0';
		close(fd);
		
		if (strcmp(buf, "-42") == 0)
		{
			print_test_result("Negative number", 1, "");
			tests_passed++;
		}
		else
			print_test_result("Negative number", 0, "");
		unlink("test_putnbr.txt");
	}
	else
		print_test_result("Negative number", 0, "(failed to open file)");
	
	/* Test 3: Zero */
	total++;
	fd = open("test_putnbr.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putnbr_fd(0, fd);
		close(fd);
		
		fd = open("test_putnbr.txt", O_RDONLY);
		char buf[50];
		int bytes = read(fd, buf, 49);
		buf[bytes] = '\0';
		close(fd);
		
		if (strcmp(buf, "0") == 0)
		{
			print_test_result("Zero", 1, "");
			tests_passed++;
		}
		else
			print_test_result("Zero", 0, "");
		unlink("test_putnbr.txt");
	}
	else
		print_test_result("Zero", 0, "(failed to open file)");
	
	/* Test 4: INT_MAX */
	total++;
	fd = open("test_putnbr.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putnbr_fd(2147483647, fd);
		close(fd);
		
		fd = open("test_putnbr.txt", O_RDONLY);
		char buf[50];
		int bytes = read(fd, buf, 49);
		buf[bytes] = '\0';
		close(fd);
		
		if (strcmp(buf, "2147483647") == 0)
		{
			print_test_result("INT_MAX", 1, "");
			tests_passed++;
		}
		else
			print_test_result("INT_MAX", 0, "");
		unlink("test_putnbr.txt");
	}
	else
		print_test_result("INT_MAX", 0, "(failed to open file)");
	
	/* Test 5: INT_MIN */
	total++;
	fd = open("test_putnbr.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putnbr_fd(-2147483648, fd);
		close(fd);
		
		fd = open("test_putnbr.txt", O_RDONLY);
		char buf[50];
		int bytes = read(fd, buf, 49);
		buf[bytes] = '\0';
		close(fd);
		
		if (strcmp(buf, "-2147483648") == 0)
		{
			print_test_result("INT_MIN", 1, "");
			tests_passed++;
		}
		else
			print_test_result("INT_MIN", 0, "");
		unlink("test_putnbr.txt");
	}
	else
		print_test_result("INT_MIN", 0, "(failed to open file)");
	
	/* Test 6: Write to stdout (visual check) */
	total++;
	printf("%s      Manual test - should print '12345': ", DIM);
	ft_putnbr_fd(12345, 1);
	printf("%s\n", RESET);
	print_test_result("Write to stdout (visual check)", 1, "");
	tests_passed++;
	
	sprintf(details, "[%d/%d tests passed]", tests_passed, total);
	printf("%s%s  %s%s\n", DIM, tests_passed == total ? GREEN : RED, details, RESET);
	update_function_stats(tests_passed == total);
}
