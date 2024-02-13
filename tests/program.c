/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:25:14 by otodd             #+#    #+#             */
/*   Updated: 2024/02/13 15:07:29 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <bsd/string.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <fcntl.h>
#include <math.h>

char	EDGES[] = "====================================================================";

static char	ft_toupper_a(unsigned int i, char c)
{
	const unsigned char		char_offset = ('a' - 'A');

	if (c >= 'a' && c <= 'z')
		c -= char_offset;
	return (c);
}

static void	ft_toupper_a_1(unsigned int i, char *c)
{
	const unsigned char		char_offset = ('a' - 'A');

	if (*c >= 'a' && *c <= 'z')
		*c -= char_offset;
}

void	start_test(char *name)
{
	printf("\n%s\n", EDGES);
	printf("\n"BCYN"		  START TEST CASE:"WHT" ""%s\n"RESET, name);
}

void	end_test(char *name)
{
	printf("\n"BYEL"		  END TEST CASE:"WHT" ""%s\n"RESET, name);
	printf("\n%s\n", EDGES);
}

void	start_sub_test(char *name)
{
	printf("\n%s\n", EDGES);
	printf("\n"BLUB"		  START SUB TEST CASE:"WHT" ""%s\n"RESET, name);
}

void	end_sub_test(char *name)
{
	printf("\n"BLUB"		  END SUB TEST CASE:"WHT" ""%s\n"RESET, name);
	printf("\n%s\n", EDGES);
}

void	assert_ext(char *func, int result)
{
	printf("\n%s\n", EDGES);
	printf("\nFunction: "BBLU"%s\n"RESET, func);
	printf("\n"BHYEL"	     FUNCTION ASSESSED EXTERNALLY!!!\n"RESET);
	if (result)
		printf("\n"BGRN"			PASSED!\n"RESET);
	else
		printf("\n"BRED"			FAILED!\n"RESET);
	printf("\n%s\n", EDGES);
}

void	assert_char(char original, char ft, char *func)
{
	int		result;

	printf("\n%s\n", EDGES);
	printf("\nFunction: "BBLU"%s\n"RESET, func);
	printf("\nCompare Type: "BGRN"%s\n"RESET, "Character Compare");
	result = (original == ft);
	if (result)
	{
		printf("\n"BGRN"			PASSED!\n"RESET);
		printf("\nComparison result: %d\n", result);
		printf("\nExpected: "BGRN"%c"RESET" | Got: "BGRN"%c\n"RESET, original, ft);
	}
	else
	{
		printf("\n"BRED"			FAILED!\n"RESET);
		printf("\nComparison result: %d\n", result);
		printf("\nExpected: "BGRN"%c"RESET" | Got: "BRED"%c\n"RESET, original, ft);
	}
	printf("\n%s\n", EDGES);
}

void	assert_str(char *original, char *ft, char *func)
{
	int		result;

	printf("\n%s\n", EDGES);
	printf("\nFunction: "BBLU"%s\n"RESET, func);
	printf("\nCompare Type: "BGRN"%s\n"RESET, "String Compare");
	if (original != NULL && ft != NULL)
	{
		result = strcmp(original, ft);
		if (!result)
		{
			printf("\n"BGRN"			PASSED!\n"RESET);
			printf("\nComparison result: %d\n", result);
			printf("\nExpected: "BGRN"%s"RESET" | Got: "BGRN"%s\n"RESET, original, ft);
		}
		else
		{
			printf("\n"BRED"			FAILED!\n"RESET);
			printf("\nComparison result: %d\n", result);
			printf("\nExpected: "BGRN"%s"RESET" | Got: "BRED"%s\n"RESET, original, ft);
		}
	}
	else
	{
		printf("\n"BMAG"		      Caught NULL!\n"RESET);
		printf("\nOriginal: "BYEL"%s"RESET" | Ft: "BYEL"%s\n"RESET, original, ft);
	}
	printf("\n%s\n", EDGES);
}

void	assert_mem(char *original, char *ft, size_t length, char *func)
{
	int		result;

	printf("\n%s\n", EDGES);
	printf("\nFunction: "BBLU"%s\n"RESET, func);
	printf("\nCompare Type: "BGRN"%s\n"RESET, "Memory Compare");
	if (original != NULL && ft != NULL)
	{
		result = memcmp(original, ft, length);
		if (!result)
		{
			printf("\n"BGRN"			PASSED!\n"RESET);
			printf("\nComparison result: %d | (Compared %zu places)\n", result, length);
			printf("\nExpected: "BGRN"%s"RESET" | Got: "BGRN"%s\n"RESET, original, ft);
		}
		else
		{
			printf("\n"BRED"			FAILED!\n"RESET);
			printf("\nComparison result: %d | (Compared %zu places)\n", result, length);
			printf("\nExpected: "BGRN"%s"RESET" | Got: "BRED"%s\n"RESET, original, ft);
		}
	}
	else
	{
		printf("\n"BMAG"		      Caught NULL!\n"RESET);
		printf("\nOriginal: "BYEL"%s"RESET" | Ft: "YEL"%s\n"RESET, original, ft);
	}
	printf("\n%s\n", EDGES);
}

void	assert_int(int original, int ft, const char *func)
{
	int		result;

	printf("\n%s\n", EDGES);
	printf("\nFunction: "BBLU"%s\n"RESET, func);
	printf("\nCompare Type: "BGRN"%s\n"RESET, "Integer Compare");
	result = (original == ft);
	if (result)
	{
		printf("\n"BGRN"			PASSED!\n"RESET);
		printf("\nComparison result: %d\n", result);
		printf("\nExpected: "BGRN"%d"RESET" | Got: "BGRN"%d\n"RESET, original, ft);
	}
	else
	{
		printf("\n"BRED"			FAILED!\n"RESET);
		printf("\nComparison result: %d\n", result);
		printf("\nExpected: "BGRN"%d"RESET" | Got: "BRED"%d\n"RESET, original, ft);
	}
	printf("\n%s\n", EDGES);
}

void	test_isalpha(void)
{
	const int		test_character = 'a';

	assert_int(isalpha(test_character), ft_isalpha(test_character), __func__);
}

void	test_isdigit(void)
{
	const int		test_character = 'a';

	assert_int(isdigit(test_character), ft_isdigit(test_character), __func__);
}

void	test_isalnum(void)
{
	const int		test_character = 'a';

	assert_int(isalnum(test_character), ft_isalnum(test_character), __func__);
}

void	test_isascii(void)
{
	const int		test_character = 'a';

	assert_int(isascii(test_character), ft_isascii(test_character), __func__);
}

void	test_isprint(void)
{
	const int		test_character = 'a';

	assert_int(isprint(test_character), ft_isprint(test_character), __func__);
}

void	test_strlen(void)
{
	const char	test_string[] = "This is a test string.";

	assert_int(strlen(test_string), ft_strlen(test_string), __func__);
}

void	test_memset(void)
{
	char	test_string[] = "This is a test string.";
	char	test2[sizeof(test_string)];
	char	test_char = '-';
	size_t	place = 5;

	memcpy(test2, test_string, sizeof(test_string));
	assert_str((char *)memset(test_string, test_char, place), (char *)ft_memset(test2, test_char, place), (char *)__func__);
}

void	test_bzero(void)
{
	char	test_string[] = "This is a test string.";
	char	test2[sizeof(test_string)];
	size_t	place = 5;

	memcpy(test2, test_string, sizeof(test_string));
	bzero(test_string, place);
	ft_bzero(test2, place);
	assert_mem(test_string, test2, place, (char *)__func__);
}

void	test_memcpy(void)
{
	char	test_src[] = "This is a test string.";
	char	test_dest[strlen(test_src)];
	char	test_src_clone[] = "This is a test string.";
	char	test_dest_clone[strlen(test_src_clone)];
	size_t	place = 2;

	memcpy(test_dest, test_src, place);
	ft_memcpy(test_dest_clone, test_src_clone, place);
	assert_mem(test_dest, test_dest_clone, place, (char *)__func__);
	assert_str(test_dest, test_dest_clone, (char *)__func__);
}

void	test_memmove(void)
{
	char	test_src[] = "This is a test string.";
	char	test_dest[sizeof(test_src)];
	char	test_src_clone[] = "This is a test string.";
	char	test_dest_clone[sizeof(test_src_clone)];
	size_t	place = 7;

	memmove(test_dest, test_src, place);
	ft_memmove(test_dest_clone, test_src_clone, place);
	assert_mem(test_dest, test_dest_clone, place, (char *)__func__);
	assert_str(test_dest, test_dest_clone, (char *)__func__);
}

void	test_strlcpy(void)
{
	char	src[] = "This is a test string.";
	char	dest[strlen(src) + 1];
	char	src_clone[] = "This is a test string.";
	char	dest_clone[strlen(src_clone) + 1];
	size_t	place = 1;

	strlcpy(dest, src, place);
	ft_strlcpy(dest_clone, src_clone, place);
	assert_mem(dest, dest_clone, place, (char *)__func__);
	assert_str(dest, dest_clone, (char *)__func__);
}

void	test_strlcat(void)
{
	char	string[] = "Hello my name is";
	char	string_2[] = " Oliver Todd!";
	char	string_clone[strlen(string) + 1];
	char	string_2_clone[strlen(string_2) + 1];
	strcpy(string_clone, string);
	strcpy(string_2_clone, string_2);
	size_t	sizer = 10;
	size_t	output = strlcat(string, string_2, sizer);
	size_t	output_2 = ft_strlcat(string_clone, string_2_clone, sizer);
	assert_str(string, string_clone, (char *)__func__);
	assert_int(output, output_2, (char *)__func__);
}

void	test_toupper(void)
{
	char	test_char = 'A';

	assert_char(toupper(test_char), ft_toupper(test_char), (char *)__func__);
}

void	test_tolower(void)
{
	char	test_char = 'a';

	assert_char(tolower(test_char), ft_tolower(test_char), (char *)__func__);
}

void	test_strchr(void)
{
	char		string[] = "This is a test string, find the !.";
	const char	test_char = '!';

	assert_str(strchr(string, test_char), ft_strchr(string, test_char), (char *)__func__);
}

void	test_strrchr(void)
{
	char	string[] = "This is a test string, find the !.";
	char	test_char = '!';

	assert_str(strrchr(string, test_char), ft_strrchr(string, test_char), (char *)__func__);
}

void	test_strncmp(void)
{
	char			string[] = "This is a test";
	char			string_2[strlen(string) + 1];
	strcpy(string_2, string);
	const size_t	place = 3;

	assert_int(strncmp(string, string_2, place), ft_strncmp(string, string_2, place), (char *)__func__);
}

void	test_memchr(void)
{
	char			string[] = "This is a test string, find the !.";
	char			test_char = 'a';
	const size_t	place = 3;

	assert_mem(memchr(string, test_char, sizeof(string)), ft_memchr(string, test_char, sizeof(string)), place, (char *)__func__);
}

void	test_memcmp(void)
{
	char			string[] = "This is a test string.";
	char			string_2[strlen(string) + 1];

	strcpy(string_2, string);
	const size_t	place = 0;
	assert_int(memcmp(string, string_2, place), ft_memcmp(string, string_2, place), (char *)__func__);
}

void	test_strnstr(void)
{
	const char		haystack[] = "This is a test string";
	const char		needle[] = "is";
	const size_t	place = 10;

	assert_str(strnstr(haystack, needle, place), ft_strnstr(haystack, needle, place), (char *)__func__);
}

void	test_atoi(void)
{
	const char	num_string[] = "123123123123123";

	assert_int(atoi(num_string), ft_atoi(num_string), (char *)__func__);
}

void	test_calloc(void)
{
	const size_t	size = sizeof(int);
	const size_t	count = 10;
	void			*test = calloc(count, size);
	void			*test_2 = ft_calloc(count, size);

	assert_mem(test, test_2, (count * size), (char *)__func__);
	free(test);
	free(test_2);
}

void	test_strdup(void)
{
	char	test_string[] = "This is a test stringasdasd.";
	char	*test_dup = strdup(test_string);
	char	*test_dup_2 = ft_strdup(test_string);

	assert_str(test_dup, test_dup_2, (char *)__func__);
	assert_mem(test_dup, test_dup_2, strlen(test_string), (char *)__func__);
	free(test_dup);
	free(test_dup_2);
}

void	test_substr(void)
{
	char	test_string[] = "This is a test string.";
	char	*test_res = ft_substr(test_string, 5, 2);

	assert_str("is", test_res, (char *)__func__);
	free(test_res);
}

void	test_strjoin(void)
{
	char	test_string[] = "This is a test string.";
	char	test_string_2[] = " This is also test string.";
	char	*result = ft_strjoin(test_string, test_string_2);

	assert_str(
		"This is a test string. This is also test string.",
		result,
		(char *)__func__);
	free(result);
}

void	test_strtrim(void)
{
	char	test_string[] = "   hello world   ";
	char	test_str[] = " ";
	char	*result = ft_strtrim(test_string, test_str);

	assert_str("hello world", result, (char *)__func__);
	free(result);
}

void	test_split(void)
{
	char		*list_of_strings[] = {"this", "is", "a", "test"};
	char const	test_string[] = "this is a test";
	char		**result = ft_split(test_string, ' ');

	assert_str(list_of_strings[0], result[0], (char *)__func__);
	ft_free_array(result, ft_strarraylen(result));
	free(result);
}

void	test_itoa(void)
{
	assert_str("-2147483648", ft_itoa(INT_MIN), (char *)__func__);
}

void	test_strmapi(void)
{
	char	*result = ft_strmapi("Test", &ft_toupper_a);

	assert_str("TEST", result, (char *)__func__);
	free(result);
}

void	test_striteri(void)
{
	char	*result = strdup("Test");

	ft_striteri(result, &ft_toupper_a_1);
	assert_str("TEST", result, (char *)__func__);
	free(result);
}

void	test_abs(void)
{
	assert_int(abs(-123123213), ft_abs(-123123213), (char *)__func__);
}

void	test_isnegative(void)
{
	assert_int((-1 < 0), ft_isnegative(-123123213), (char *)__func__);
}

void	test_numlen(void)
{
	assert_int(ft_strlen("123456789"), ft_numlen(123456789), (char *)__func__);
}

void	test_strcpy(void)
{
	char	test_src[] = "This is a test string.";
	char	test_dest[30];
	char	test_src_clone[] = "This is a test string.";
	char	test_dest_clone[30];

	strcpy(test_dest, test_src);
	strcpy(test_dest_clone, test_src_clone);
	assert_mem(test_dest, test_dest_clone, strlen(test_src), (char *)__func__);
	assert_str(test_dest, test_dest_clone, (char *)__func__);
}

void	test_strncpy(void)
{
	char			test_src[] = "This is a test string.";
	char			test_dest[30];
	char			test_src_clone[] = "This is a test string.";
	char			test_dest_clone[30];
	const size_t	place = 6;

	strncpy(test_dest, test_src, place);
	test_dest[place] = '\0';
	strncpy(test_dest_clone, test_src_clone, place);
	test_dest_clone[place] = '\0';
	assert_mem(test_dest, test_dest_clone, place, (char *)__func__);
	assert_str(test_dest, test_dest_clone, (char *)__func__);
}

void	test_strcat(void)
{
	char	test_src[] = "This is a test string.";
	char	test_dest[50] = "";
	char	test_src_clone[] = "This is a test string.";
	char	test_dest_clone[50] = "";

	strcat(test_dest, test_src);
	ft_strcat(test_dest_clone, test_src_clone);
	assert_str(test_dest, test_dest_clone, (char *)__func__);
	assert_int(strlen(test_dest), strlen(test_dest_clone), (char *)__func__);
}

void	test_strncat(void)
{
	char			test_src[] = "This is a test string.";
	char			test_dest[50] = "";
	char			test_src_clone[] = "This is a test string.";
	char			test_dest_clone[50] = "";
	const size_t	place = 6;

	strncat(test_dest, test_src, place);
	ft_strncat(test_dest_clone, test_src_clone, place);
	assert_str(test_dest, test_dest_clone, (char *)__func__);
	assert_mem(test_dest, test_dest_clone, place, (char *)__func__);
}

void	test_strstr(void)
{
	const char	haystack[] = "This is a test string";
	const char	needle[] = "is";

	assert_str(strstr(haystack, needle), ft_strstr(haystack, needle), (char *)__func__);
}

void	test_sqrt(void)
{
	assert_int(sqrt(25), ft_sqrt(25), (char *)__func__);
}

void	test_range(void)
{
	int	test_src[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int	*test_out = ft_range(0, 13);
	int	index;
	int	is_match = 1;

	for (index = 0; index < 13; index++)
	{
		if (test_out[index] != test_src[index])
		{
			is_match = 0;
			break ;
		}
	}
	assert_int(1, is_match, (char *)__func__);
	free(test_out);
}

void	test_swap(void)
{
	char	tmp = 'a';
	char	tmp2 = 'b';
	char	*a = &tmp;
	char	*b = &tmp2;

	ft_swap(a, b);
	assert_char(*b, 'a', (char *)__func__);
}

void	test_strcheck(void)
{
	char	*str = "this";
	char	*func_str = strdup((char *)__func__);
	size_t	len = strlen(func_str) + strlen(" (ft_isalpha)") + 1;

	func_str = realloc(func_str, len);
	assert_int(1, ft_ischeck_str(str, ft_isalpha), strcat(func_str, " (ft_isalpha)"));
	free(func_str);
	func_str = strdup((char *)__func__);
	len = strlen(func_str) + strlen(" (ft_isdigit)") + 1;
	func_str = realloc(func_str, len);
	assert_int(1, ft_ischeck_str(str, ft_isdigit), strcat(func_str, " (ft_isdigit)"));
	free(func_str);
	func_str = strdup((char *)__func__);
	len = strlen(func_str) + strlen(" (ft_isalnum)") + 1;
	func_str = realloc(func_str, len);
	assert_int(1, ft_ischeck_str(str, ft_isalnum), strcat(func_str, " (ft_isalnum)"));
	free(func_str);
	func_str = strdup((char *)__func__);
	len = strlen(func_str) + strlen(" (ft_isascii)") + 1;
	func_str = realloc(func_str, len);
	assert_int(1, ft_ischeck_str(str, ft_isascii), strcat(func_str, " (ft_isascii)"));
	free(func_str);
	func_str = strdup((char *)__func__);
	len = strlen(func_str) + strlen(" (ft_isprint)") + 1;
	func_str = realloc(func_str, len);
	assert_int(1, ft_ischeck_str(str, ft_isprint), strcat(func_str, " (ft_isprint)"));
	free(func_str);
	func_str = strdup((char *)__func__);
	len = strlen(func_str) + strlen(" (ft_islower)") + 1;
	func_str = realloc(func_str, len);
	assert_int(1, ft_ischeck_str(str, ft_islower), strcat(func_str, " (ft_islower)"));
	free(func_str);
	func_str = strdup((char *)__func__);
	len = strlen(func_str) + strlen(" (ft_isupper)") + 1;
	func_str = realloc(func_str, len);
	assert_int(1, ft_ischeck_str(str, ft_isupper), strcat(func_str, " (ft_isupper)"));
	free(func_str);
	func_str = strdup((char *)__func__);
	len = strlen(func_str) + strlen(" (ft_iswhitespace)") + 1;
	func_str = realloc(func_str, len);
	assert_int(1, ft_ischeck_str(str, ft_iswhitespace), strcat(func_str, " (ft_iswhitespace)"));
	free(func_str);
}

void	test_standard_format_specifiers(void)
{
	char			test_char = 'a';
	char			*test_str = "|I AM A TEST STRINGS|";
	int				test_int_val = INT_MIN;
	int				*test_int_ptr = &test_int_val;
	unsigned int	test_unsigned_int = 123456;

	printf("\n%s\n", EDGES);
	printf("\n    Own:          "BLU"%d"RESET" chars\n\n", ft_printf("This is "BGRN"%c"RESET" test for char.", test_char));
	printf("\n    Original:     "BLU"%d"RESET" chars", printf("This is "BGRN"%c"RESET" test for char.", test_char));
	printf("\n%s\n", EDGES);
	printf("\n%s\n", EDGES);
	printf("\n    Own:          "BLU"%d"RESET" chars\n\n", ft_printf("This is "BGRN"%c"RESET" test for char and this is a test for "BGRN"%yyy"RESET, test_char));
	printf("\n    Original:     "BLU"%d"RESET" chars", printf("This is "BGRN"%c"RESET" test for char and this is a test for "BGRN"%yyy"RESET, test_char));
	printf("\n%s\n", EDGES);
	printf("\n%s\n", EDGES);
	printf("\n    Own:          "BLU"%d"RESET" chars\n\n", ft_printf("This is a test for str "BGRN"%s"RESET".", test_str));
	printf("\n    Original:     "BLU"%d"RESET" chars", printf("This is a test for str "BGRN"%s"RESET".", test_str));
	printf("\n%s\n", EDGES);
	printf("\n%s\n", EDGES);
	printf("\n    Own:          "BLU"%d"RESET" chars\n\n", ft_printf("This is a test for digit and this is "BGRN"%d"RESET, test_int_ptr));
	printf("\n    Original:     "BLU"%d"RESET" chars", printf("This is a test for digit and this is "BGRN"%d"RESET, test_int_ptr));
	printf("\n%s\n", EDGES);
	printf("\n%s\n", EDGES);
	printf("\n    Own:          "BLU"%d"RESET" chars\n\n", ft_printf("This is a test for int and this is "BGRN"%i"RESET, test_int_ptr));
	printf("\n    Original:     "BLU"%d"RESET" chars", printf("This is a test for int and this is "BGRN"%i"RESET, test_int_ptr));
	printf("\n%s\n", EDGES);
	printf("\n%s\n", EDGES);
	printf("\n    Own:          "BLU"%d"RESET" chars\n\n", ft_printf("This is a test for lower hex and this is "BGRN"%x"RESET, test_int_ptr));
	printf("\n    Original:     "BLU"%d"RESET" chars", printf("This is a test for lower hex and this is "BGRN"%x"RESET, test_int_ptr));
	printf("\n%s\n", EDGES);
	printf("\n%s\n", EDGES);
	printf("\n    Own:          "BLU"%d"RESET" chars\n\n", ft_printf("This is a test for upper hex and this is "BGRN"%X"RESET, test_int_ptr));
	printf("\n    Original:     "BLU"%d"RESET" chars", printf("This is a test for upper hex and this is "BGRN"%X"RESET, test_int_ptr));
	printf("\n%s\n", EDGES);
	printf("\n%s\n", EDGES);
	printf("\n    Own:          "BLU"%d"RESET" chars\n\n", ft_printf("This is a test for ptr and this is "BGRN"%p"RESET, test_int_ptr));
	printf("\n    Original:     "BLU"%d"RESET" chars", printf("This is a test for ptr and this is "BGRN"%p"RESET, test_int_ptr));
	printf("\n%s\n", EDGES);
	printf("\n%s\n", EDGES);
	printf("\n    Own:          "BLU"%d"RESET" chars\n\n", ft_printf("This is a test for unsigned int and this is "BGRN"%u"RESET, test_int_ptr));
	printf("\n    Original:     "BLU"%d"RESET" chars", printf("This is a test for unsigned int and this is "BGRN"%u"RESET, test_int_ptr));
	printf("\n%s\n", EDGES);
}

void	test_custom_format_specifiers(void)
{
	size_t	len = 100;
	char	**char_array;
	int		*int_array;
	int		*int_array_head;
	t_list	**int_list = NULL;
	t_list	**char_list = NULL;
	t_list	*new_node = NULL;
	char	*content_char = NULL;
	int		*content_int = NULL;
	char	*tmp = NULL;
	char	*tmp2 = NULL;
	size_t	i = 0;
	size_t	j = 0;
	size_t	k = 0;

	char_array = (char **)malloc(sizeof(char *) * len);
	for (j = 0; j < len; j++)
	{
		tmp = ft_itoa(j);
		tmp2 = ft_strjoin(tmp, RESET);
		char_array[j] = ft_strjoin("This is a test string "BGRN, tmp2);
		free(tmp);
		free(tmp2);
	}
	int_array = ft_range(0, len);
	int_array_head = int_array;
	while (*int_array_head++ != INT_MAX)
		k++;
	while (i < k)
	{
		content_char = malloc(sizeof(char) * i);
		sprintf(content_char, "This is "BGRN"%d"RESET, int_array[i]);
		new_node = ft_lstnew(content_char);
		ft_lstadd_back(&char_list, new_node);
		content_int = malloc(sizeof(int));
		*content_int = i;
		new_node = ft_lstnew(content_int);
		ft_lstadd_back(&int_list, new_node);
		i++;
	}
	printf("\n%s\n", EDGES);
	ft_printf("This is an array that contains strings: %a\n", char_array);
	printf("\n%s\n", EDGES);
	printf("\n%s\n", EDGES);
	ft_printf("This is an array that contains integers in base 10: "BGRN"%n\n"RESET, int_array);
	printf("\n%s\n", EDGES);
	printf("\n%s\n", EDGES);
	ft_printf("This is an array that contains integers in base 16 in lower case: "BGRN"%nx\n"RESET, int_array);
	printf("\n%s\n", EDGES);
	printf("\n%s\n", EDGES);
	ft_printf("This is an array that contains integers in base 16 in upper case: "BGRN"%nX\n"RESET, int_array);
	printf("\n%s\n", EDGES);
	printf("\n%s\n", EDGES);
	ft_printf("This is an array that contains integers in base 2: "BGRN"%nb\n"RESET, int_array);
	printf("\n%s\n", EDGES);
	printf("\n%s\n", EDGES);
	ft_printf("This is an array that contains integers in base 8: "BGRN"%no\n"RESET, int_array);
	printf("\n%s\n", EDGES);
	printf("\n%s\n", EDGES);
	ft_printf("This is a linked list that contains strings: "BGRN"%l\n"RESET, char_list);
	printf("\n%s\n", EDGES);
	printf("\n%s\n", EDGES);
	ft_printf("This is a linked list that contains integers in base 10: "BGRN"%L\n"RESET, int_list);
	printf("\n%s\n", EDGES);
	printf("\n%s\n", EDGES);
	ft_printf("This is a linked list that contains integers in base 16 in lower case: "BGRN"%Lx\n"RESET, int_list);
	printf("\n%s\n", EDGES);
	printf("\n%s\n", EDGES);
	ft_printf("This is a linked list that contains integers in base 16 in upper case: "BGRN"%LX\n"RESET, int_list);
	printf("\n%s\n", EDGES);
	printf("\n%s\n", EDGES);
	ft_printf("This is a linked list that contains integers in base 2: "BGRN"%Lb\n"RESET, int_list);
	printf("\n%s\n", EDGES);
	printf("\n%s\n", EDGES);
	ft_printf("This is a linked list that contains integers in base 8: "BGRN"%Lo\n"RESET, int_list);
	printf("\n%s\n", EDGES);
	ft_lstclear(&int_list, free);
	ft_lstclear(&char_list, free);
	ft_free_array(char_array, ft_strarraylen(char_array));
	free(char_array);
	free(int_array);
}

void	test_all_format_specifiers_in_one(void)
{
	char			test_char = 'a';
	char			*test_str = "|I AM A TEST STRINGS|";
	int				test_int_val = INT_MIN;
	int				*test_int_ptr = &test_int_val;
	unsigned int	test_unsigned_int = 123456;
	size_t			len = 10;
	char			**char_array;
	int				*int_array;
	int				*int_array_head;
	t_list			**int_list = NULL;
	t_list			**char_list = NULL;
	t_list			*new_node = NULL;
	char			*content_char = NULL;
	int				*content_int = NULL;
	char			*tmp = NULL;
	char			*tmp2 = NULL;
	size_t			i = 0;
	size_t			j = 0;
	size_t			k = 0;

	char_array = (char **)malloc(sizeof(char *) * len);
	for (j = 0; j < len; j++)
	{
		tmp = ft_itoa(j);
		char_array[j] = ft_strjoin("This is a test string ", tmp);
		free(tmp);
	}
	int_array = ft_range(0, len);
	int_array_head = int_array;
	while (*int_array_head++ != INT_MAX)
		k++;
	while (i < k)
	{
		content_char = malloc(sizeof(char) * i);
		sprintf(content_char, "Index: %d", int_array[i]);
		new_node = ft_lstnew(content_char);
		ft_lstadd_back(&char_list, new_node);
		content_int = malloc(sizeof(int));
		*content_int = i;
		new_node = ft_lstnew(content_int);
		ft_lstadd_back(&int_list, new_node);
		i++;
	}
	printf("\n%s\n", EDGES);
	ft_printf("This is a test that contains all the standard and custom format specifiers in one call: \n%c\n%s\n%d\n%i\n%x\n%X\n%p\n%u\n%a\n%n\n%nx\n%nX\n%nb\n%no\n%l\n%L\n%Lx\n%LX\n%Lb\n%Lo\n",
		test_char,
		test_str,
		test_int_val,
		test_int_val,
		test_int_val,
		test_int_val,
		test_int_ptr,
		test_unsigned_int,
		char_array,
		int_array,
		int_array,
		int_array,
		int_array,
		int_array,
		char_list,
		int_list,
		int_list,
		int_list,
		int_list,
		int_list,
		int_list,
		int_list,
		int_list);
	printf("\n%s\n", EDGES);
	ft_lstclear(&int_list, free);
	ft_lstclear(&char_list, free);
	ft_free_array(char_array, ft_strarraylen(char_array));
	free(char_array);
	free(int_array);
}

void	test_ft_printf(void)
{
	test_standard_format_specifiers();
	test_custom_format_specifiers();
	test_all_format_specifiers_in_one();
}

void	test_gnl_single(char *arg_a)
{
	int		fd;
	int		i;
	char	*c_line;

	i = 0;
	fd = open(arg_a, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return ;
	}
	printf("\n%s\n", EDGES);
	printf("|\n| %s ["BBLU"%d"RESET"]\n|\n", "Opening fd with buffer size of", BUFFER_SIZE);
	while ((c_line = ft_get_next_line(fd)) != NULL)
	{
		printf("| ["BBLU"%d"RESET"] - ["BGRN"%zu"RESET"] - %s", i++, ft_g_strl(c_line, 0), c_line);
		free(c_line);
	}
	close(fd);
	printf("\n|""\n%s\n", EDGES);
}

void	test_strcmp(void)
{
	char			string[] = "This is a test";
	char			string_2[strlen(string) + 1];
	strcpy(string_2, string);

	assert_int(strcmp(string, string_2), ft_strcmp(string, string_2), (char *)__func__);
}

void	test_overflow_check(void)
{
	int	n = INT_MIN;
	int	n_2 = INT_MAX;

	assert_int(1, ft_check_overflow(&n, sizeof(int)),(char *)__func__);
	assert_int(1, ft_check_overflow(&n_2, sizeof(int)),(char *)__func__);
}

int	main(void)
{
	start_test("Core functions");
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	test_strlcpy();
	test_strlcat();
	test_toupper();
	test_tolower();
	test_strchr();
	test_strrchr();
	test_strncmp();
	test_memchr();
	test_memcmp();
	test_strnstr();
	test_atoi();
	test_calloc();
	test_strdup();
	end_test("Core functions");
	start_test("Additional functions");
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();
	test_strmapi();
	test_striteri();
	assert_ext("ft_putchar_fd", 1);
	assert_ext("ft_putstr_fd", 1);
	assert_ext("ft_putendl_fd", 1);
	assert_ext("ft_putnbr_fd", 1);
	test_abs();
	test_isnegative();
	test_numlen();
	test_strcpy();
	test_strncpy();
	test_strcat();
	test_strncat();
	test_strstr();
	assert_ext("ft_putchar", 1);
	assert_ext("ft_putstr", 1);
	test_sqrt();
	assert_ext("ft_isprime", 1);
	test_range();
	assert_ext("ft_putnbr", 1);
	test_swap();
	assert_ext("ft_putendl", 1);
	test_strcheck();
	test_strcmp();
	test_overflow_check();
	end_test("Additional functions");
	start_test("Modules");
	start_sub_test("ft_printf");
	test_ft_printf();
	end_sub_test("ft_printf");
	start_sub_test("get_next_line");
	test_gnl_single("Makefile");
	end_sub_test("get_next_line");
	end_test("Modules");
	return (0);

}
