/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:00:48 by glevin            #+#    #+#             */
/*   Updated: 2024/05/26 16:37:10 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Applies the function f to each character of the
string s, passing its index as the first argument
and the character itself as the second. A new
string is created (using malloc(3)) to collect the
results from the successive applications of f.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			s_len;
	char			*res;

	i = 0;
	s_len = ft_strlen(s);
	res = (char *)malloc(s_len + 1 * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[s_len] = '\0';
	return (res);
}

//////////////////
///////TEST///////
//////////////////

// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Function prototypes
// size_t			ft_strlen(const char *str);
// char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// // Mock function for transformation: capitalize each character
// char	capitalize(unsigned int i, char c)
// {
// 	(void)i; // Unused parameter
// 	return (toupper(c));
// }

// // Mock function for transformation: add index to each character
// char	add_index(unsigned int i, char c)
// {
// 	return (c + i);
// }

// // Helper function to free memory and avoid memory leaks in tests
// void	free_result(char *result)
// {
// 	if (result)
// 		free(result);
// }

// // Test function to compare expected and actual results
// void	test_strmapi(char const *s, char (*f)(unsigned int, char),
// 		char const *expected, const char *test_name)
// {
// 	char	*result;

// 	result = ft_strmapi(s, f);
// 	if (strcmp(result, expected) == 0)
// 	{
// 		printf("%s: Passed\n", test_name);
// 	}
// 	else
// 	{
// 		printf("%s: Failed (Expected: \"%s\", Got: \"%s\")\n", test_name,
// 			expected, result);
// 	}
// 	free_result(result);
// }

// // Main function with test cases
// int	main(void)
// {
// 	// Test 1: Basic functionality - capitalize each character
// 	test_strmapi("hello", capitalize, "HELLO", "Test 1 - Basic functionality");
// 	// Test 2: Edge case - empty string
// 	test_strmapi("", capitalize, "", "Test 2 - Empty string");
// 	// Test 3: Long string
// 	test_strmapi("thisisaverylongstringtotestthefunctionality", capitalize,
// 		"THISISAVERYLONGSTRINGTOTESTTHEFUNCTIONALITY", "Test 3 - Long string");
// 	// Test 4: Character transformation - add index to each character
// 	test_strmapi("abcd", add_index, "aceg",
// "Test 4- Add index to each character");
// 	return (0);
// }
