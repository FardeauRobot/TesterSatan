#ifndef ADVICE_H
# define ADVICE_H

/**
 * get_function_advice - Returns specific advice for a failing function
 * 
 * @function_name: Name of the function (e.g., "ft_strlen", "ft_split")
 * @test_name: Name of the specific test that failed
 * 
 * Return: String with specific advice for fixing the issue
 */
const char *get_function_advice(const char *function_name, const char *test_name);

#endif
