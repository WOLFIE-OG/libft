/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:25:14 by otodd             #+#    #+#             */
/*   Updated: 2024/02/05 22:07:15 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "ANSI-color-codes.h"
#include <bsd/string.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <fcntl.h>
#include <math.h>

char EDGES[] = "====================================================================";

static char	ft_toupper_a(unsigned int i, char c)
{
	const unsigned char	char_offset = ('a' - 'A');

	if (c >= 'a' && c <= 'z')
		c -= char_offset;
	return (c);
}

void	start_test(char *name)
{
	printf("\n%s\n", EDGES);
	printf("\n"BCYN"		  START TEST CASE: "WHT"%s\n"reset, name);
}

void	end_test(char *name)
{
	printf("\n"BYEL"		  END TEST CASE: "WHT"%s\n"reset, name);
	printf("\n%s\n", EDGES);
}

void	assert_ext(char *func, int result)
{
	printf("\n%s\n", EDGES);
	printf("\nFunction: "BBLU"%s\n"reset, func);
	printf("\n"BHYEL"	     FUNCTION ASSESSED EXTERNALLY!!!\n"reset);
	if (result)
		printf("\n"BGRN"			PASSED!\n"reset);
	else
		printf("\n"BRED"			FAILED!\n"reset);
	printf("\n%s\n", EDGES);
}

void	assert_char(char original, char ft, char *func)
{
	int	result;

	printf("\n%s\n", EDGES);
	printf("\nFunction: "BBLU"%s\n"reset, func);
	printf("\nCompare Type: "BGRN"%s\n"reset, "Character Compare");
	result = (original == ft);
	if (result)
	{
		printf("\n"BGRN"			PASSED!\n"reset);
		printf("\nComparison result: %d\n", result);
		printf("\nExpected: "BGRN"%c"reset" | Got: "BGRN"%c\n"reset, original, ft);
	}
	else
	{
		printf("\n"BRED"			FAILED!\n"reset);
		printf("\nComparison result: %d\n", result);
		printf("\nExpected: "BGRN"%c"reset" | Got: "BRED"%c\n"reset, original, ft);
	}
	printf("\n%s\n", EDGES);
}

void	assert_str(char *original, char *ft, char *func)
{
	int	result;

	printf("\n%s\n", EDGES);
	printf("\nFunction: "BBLU"%s\n"reset, func);
	printf("\nCompare Type: "BGRN"%s\n"reset, "String Compare");
	if (original != NULL && ft != NULL)
	{
		result = strcmp(original, ft);
		if (!result)
		{
			printf("\n"BGRN"			PASSED!\n"reset);
			printf("\nComparison result: %d\n", result);
			printf("\nExpected: "BGRN"%s"reset" | Got: "BGRN"%s\n"reset, original, ft);
		}
		else
		{
			printf("\n"BRED"			FAILED!\n"reset);
			printf("\nComparison result: %d\n", result);
			printf("\nExpected: "BGRN"%s"reset" | Got: "BRED"%s\n"reset, original, ft);
		}
	}
	else
	{
		printf("\n"BMAG"		      Caught NULL!\n"reset);
		printf("\nOriginal: "BYEL"%s"reset" | Ft: "BYEL"%s\n"reset, original, ft);
	}
	printf("\n%s\n", EDGES);
}

void	assert_mem(char *original, char *ft, size_t length, char *func)
{
	int	result;

	printf("\n%s\n", EDGES);
	printf("\nFunction: "BBLU"%s\n"reset, func);
	printf("\nCompare Type: "BGRN"%s\n"reset, "Memory Compare");
	if (original != NULL && ft != NULL)
	{
		result = memcmp(original, ft, length);
		if (!result)
		{
			printf("\n"BGRN"			PASSED!\n"reset);
			printf("\nComparison result: %d | (Compared %zu places)\n", result, length);
			printf("\nExpected: "BGRN"%s"reset" | Got: "BGRN"%s\n"reset, original, ft);
		}
		else
		{
			printf("\n"BRED"			FAILED!\n"reset);
			printf("\nComparison result: %d | (Compared %zu places)\n", result, length);
			printf("\nExpected: "BGRN"%s"reset" | Got: "BRED"%s\n"reset, original, ft);
		}
	}
	else
	{
		printf("\n"BMAG"		      Caught NULL!\n"reset);
		printf("\nOriginal: "BYEL"%s"reset" | Ft: "YEL"%s\n"reset, original, ft);
	}
	printf("\n%s\n", EDGES);
}

void	assert_int(int original, int ft, const char *func)
{
	int	result;

	printf("\n%s\n", EDGES);
	printf("\nFunction: "BBLU"%s\n"reset, func);
	printf("\nCompare Type: "BGRN"%s\n"reset, "Integer Compare");
	result = (original == ft);
	if (result)
	{
		printf("\n"BGRN"			PASSED!\n"reset);
		printf("\nComparison result: %d\n", result);
		printf("\nExpected: "BGRN"%d"reset" | Got: "BGRN"%d\n"reset, original, ft);
	}
	else
	{
		printf("\n"BRED"			FAILED!\n"reset);
		printf("\nComparison result: %d\n", result);
		printf("\nExpected: "BGRN"%d"reset" | Got: "BRED"%d\n"reset, original, ft);
	}
	printf("\n%s\n", EDGES);
}

void	test_isalpha()
{
	int	test = 'a';

	assert_int(isalpha(test), ft_isalpha(test), __func__);
}

void	test_isdigit()
{
	int	test = 'a';

	assert_int(isdigit(test), ft_isdigit(test), __func__);
}

void	test_isalnum()
{
	int	test = 'a';

	assert_int(isalnum(test), ft_isalnum(test), __func__);
}

void	test_isascii()
{
	int	test = 'a';

	assert_int(isascii(test), ft_isascii(test), __func__);
}

void	test_isprint()
{
	int	test = 'a';

	assert_int(isprint(test), ft_isprint(test), __func__);
}

void	test_strlen()
{
	char	test[] = "This is a test string.";

	assert_int(strlen(test), ft_strlen(test), __func__);
}

void	test_memset()
{
	char	test[] = "This is a test string.";
	char	*test2 = strdup(test);
	char	test_char = '-';
	size_t	place = 5;

	assert_str((char *)memset(test, test_char, place), (char *)ft_memset(test2, test_char, place), (char *)__func__);
	free(test2);
}

void	test_bzero()
{
	char	test[] = "This is a test string.";
	char	*test2 = strdup(test);
	size_t	place = 5;

	bzero(test, place);
	ft_bzero(test2, place);
	assert_mem(test, test2, place, (char *)__func__);
	free(test2);
}

void	test_memcpy()
{
	char	test_src[] = "This is a test string.";
	char	*test_dest = (char *)malloc(sizeof(char) * strlen(test_src));
	char 	test_src_clone[] = "This is a test string.";
	char 	*test_dest_clone = (char *)malloc(sizeof(char) * strlen(test_src_clone));
	size_t	place = 2;

	memcpy(test_dest, test_src, place);
	ft_memcpy(test_dest_clone, test_src_clone, place);
	assert_mem(test_dest, test_dest_clone, place, (char *)__func__);
	assert_str(test_dest, test_dest_clone, (char *)__func__);
	free(test_dest);
	free(test_dest_clone);
}

void	test_memmove()
{
	char	test_src[] = "This is a test string.";
	char	*test_dest = (char *)malloc(sizeof(char) * strlen(test_src));
	char 	test_src_clone[] = "This is a test string.";
	char 	*test_dest_clone = (char *)malloc(sizeof(char) * strlen(test_src_clone));
	size_t	place = 5;

	memmove(test_dest, test_src, place);
	ft_memmove(test_dest_clone, test_src_clone, place);
	assert_mem(test_dest, test_dest_clone, place, (char *)__func__);
	assert_str(test_dest, test_dest_clone, (char *)__func__);
	free(test_dest);
	free(test_dest_clone);
}

void	test_strlcpy()
{
	char	test_src[] = "This is a test string.";
	char	*test_dest = (char *)malloc(sizeof(char) * strlen(test_src));
	char 	test_src_clone[] = "This is a test string.";
	char 	*test_dest_clone = (char *)malloc(sizeof(char) * strlen(test_src_clone));
	size_t	place = 1;

	strlcpy(test_dest, test_src, place);
	ft_strlcpy(test_dest_clone, test_src_clone, place);
	assert_mem(test_dest, test_dest_clone, place, (char *)__func__);
	assert_str(test_dest, test_dest_clone, (char *)__func__);
	free(test_dest);
	free(test_dest_clone);
}

void	test_strlcat()
{
	char	test_string[] = "Hello my name is";
	char	test_string_2[] = " Oliver Todd!";
	char 	*test_string_clone = strdup(test_string);
	char 	*test_string_2_clone = strdup(test_string_2);
	size_t	l_sizer = 10;
	size_t	test_output = strlcat(test_string, test_string_2, l_sizer);
	size_t	test_output_2 = ft_strlcat(test_string_clone, test_string_2_clone, l_sizer);
	
	assert_str(test_string, test_string_clone, (char *)__func__);
	assert_int(test_output, test_output_2, (char *)__func__);
	free(test_string_clone);
	free(test_string_2_clone);
}

void	test_toupper()
{
	char	test_char = 'A';
	
	assert_char(toupper(test_char), ft_toupper(test_char), (char *)__func__);
}

void	test_tolower()
{
	char	test_char = 'a';
	
	assert_char(tolower(test_char), ft_tolower(test_char), (char *)__func__);
}

void	test_strchr()
{
	char	test_string[] = "This is a test string, find the !.";
	char	test_char = '!';

	assert_str(strchr(test_string, test_char), ft_strchr(test_string, test_char), (char *)__func__);
}

void	test_strrchr()
{
	char	test_string[] = "This is a test string, find the !.";
	char	test_char = '!';

	assert_str(strrchr(test_string, test_char), ft_strrchr(test_string, test_char), (char *)__func__);
}

void	test_strncmp()
{
	char	test_string[] = "This is a test";
	char	*test_string_2 = strdup(test_string);
	size_t	place = 3;

	assert_int(strncmp(test_string, test_string_2, place), ft_strncmp(test_string, test_string_2, place), (char *)__func__);
	free(test_string_2);
}

void	test_memchr()
{
	char	test_string[] = "This is a test string, find the !.";
	char	test_char = 'a';
	size_t	place = 3;

	assert_mem(memchr(test_string, test_char, sizeof(test_string)), ft_memchr(test_string, test_char, sizeof(test_string)), place, (char *)__func__);
}

void	test_memcmp()
{
	char	test_string[] = "This is a test string.";
	char	*test_string_2 = strdup(test_string);
	size_t	place = 0;

	assert_int(memcmp(test_string, test_string_2, place), ft_memcmp(test_string, test_string_2, place), (char *)__func__);
	free(test_string_2);
}

void	test_strnstr()
{
	const char	haystack[] = "This is a test string";
	const char	needle[] = "is";
	size_t		place = 10;

	assert_str(strnstr(haystack, needle, place), ft_strnstr(haystack, needle, place), (char *)__func__);
}

void	test_atoi()
{
	const char	num_string[] = "123123123123123";

	assert_int(atoi(num_string), ft_atoi(num_string), (char *)__func__);
}

void	test_calloc()
{
	size_t	size = sizeof(int);
	size_t	count = 10;
	void	*test = calloc(count, size);
	void	*test_2 = ft_calloc(count, size);

	assert_mem(test, test_2, (count * size), (char *)__func__);
	free(test);
	free(test_2);
}

void	test_strdup()
{
	char	test_string[] = "This is a test stringasdasd.";
	char	*test_dup = strdup(test_string);
	char	*test_dup_2 = ft_strdup(test_string);

	assert_str(test_dup, test_dup_2, (char *)__func__);
	assert_mem(test_dup, test_dup_2, strlen(test_string), (char *)__func__);
	free(test_dup);
	free(test_dup_2);
}

void	test_substr()
{
	char	test_string[] = "This is a test string.";
	char	*test_res = ft_substr(test_string, 5, 2);

	assert_str("is", test_res, (char *)__func__);
	free(test_res);
}

void	test_strjoin()
{
	char	test_string[] = "This is a test string.";
	char	test_string_2[] = " This is also test string.";

	assert_str(
		"This is a test string. This is also test string.",
		ft_strjoin(test_string, test_string_2),
		(char *)__func__
	);
}

void	test_strtrim()
{
	char	test_string[] = "   hello world   ";
	char	test_str[] = " ";

	assert_str("hello world", ft_strtrim(test_string, test_str), (char *)__func__);
}

void	test_split()
{
	char		*list_of_strings[] = {"this", "is", "a", "test"};
	char const	test_string[] = "this is a test";
	assert_str(list_of_strings[0], ft_split(test_string, ' ')[0], (char *)__func__);
}

void	test_itoa()
{
	assert_str("-2147483648", ft_itoa(INT_MIN), (char *)__func__);
}

void	test_strmapi()
{
	assert_str("TEST", ft_strmapi("Test", &ft_toupper_a), (char *)__func__);
}

void	test_striteri()
{
	assert_str("TEST", ft_strmapi("Test", &ft_toupper_a), (char *)__func__);
}

void	test_abs()
{
	assert_int(abs(-123123213), ft_abs(-123123213), (char *)__func__);
}

void	test_isnegative()
{
	assert_int((-1 < 0), ft_isnegative(-123123213), (char *)__func__);
}

void	test_numlen()
{
	assert_int(ft_strlen("123456789"), ft_numlen(123456789), (char *)__func__);
}

void	test_strcpy()
{
	char	test_src[] = "This is a test string.";
	char	*test_dest = (char *)malloc(sizeof(char) * strlen(test_src));
	char 	test_src_clone[] = "This is a test string.";
	char 	*test_dest_clone = (char *)malloc(sizeof(char) * strlen(test_src_clone));

	strcpy(test_dest, test_src);
	ft_strcpy(test_dest_clone, test_src_clone);
	assert_mem(test_dest, test_dest_clone, strlen(test_src), (char *)__func__);
	assert_str(test_dest, test_dest_clone, (char *)__func__);
	free(test_dest);
	free(test_dest_clone);
}

void	test_strncpy()
{
	char	test_src[] = "This is a test string.";
	char	*test_dest = (char *)malloc(sizeof(char) * strlen(test_src));
	char 	test_src_clone[] = "This is a test string.";
	char 	*test_dest_clone = (char *)malloc(sizeof(char) * strlen(test_src_clone));
	size_t	place = 6;

	strncpy(test_dest, test_src, place);
	ft_strncpy(test_dest_clone, test_src_clone, place);
	assert_mem(test_dest, test_dest_clone, place, (char *)__func__);
	assert_str(test_dest, test_dest_clone, (char *)__func__);
	free(test_dest);
	free(test_dest_clone);
}

void test_strcat()
{
    char test_src[] = "This is a test string.";
    char *test_dest = (char *)malloc(sizeof(char) * (strlen(test_src) + 1));
    char test_src_clone[] = "This is a test string.";
    char *test_dest_clone = (char *)malloc(sizeof(char) * (strlen(test_src_clone) + 1));

    strcpy(test_dest, "");
    strcpy(test_dest_clone, "");
    strcat(test_dest, test_src);
    ft_strcat(test_dest_clone, test_src_clone);
    assert_str(test_dest, test_dest_clone, (char *)__func__);
    assert_int(strlen(test_dest), strlen(test_dest_clone), (char *)__func__);
    free(test_dest);
    free(test_dest_clone);
}

void test_strncat()
{
    char 	test_src[] = "This is a test string.";
    char 	*test_dest = (char *)malloc(sizeof(char) * (strlen(test_src) + 1));
    char 	test_src_clone[] = "This is a test string.";
    char 	*test_dest_clone = (char *)malloc(sizeof(char) * (strlen(test_src_clone) + 1));
	size_t	place = 6;

    strcpy(test_dest, "");
    strcpy(test_dest_clone, "");
    strncat(test_dest, test_src, place);
    ft_strncat(test_dest_clone, test_src_clone, place);
    assert_str(test_dest, test_dest_clone, (char *)__func__);
	assert_mem(test_dest, test_dest_clone, place, (char *)__func__);
    free(test_dest);
    free(test_dest_clone);
}

void	test_strstr()
{
	const char	haystack[] = "This is a test string";
	const char	needle[] = "is";

	assert_str(strstr(haystack, needle), ft_strstr(haystack, needle), (char *)__func__);
}

void	test_sqrt()
{
	assert_int(sqrt(25), ft_sqrt(25), (char *)__func__);
}

void	test_range()
{
	int 	test_src[]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int		*test_out = ft_range(0, 13);
	int		index;
	int		is_match = 1;

	for (index = 0; index < 13; index++)
		if (test_out[index] != test_src[index])
			is_match = 0;
	assert_int(1, is_match, (char *)__func__);
	free(test_out);
}

void	test_swap()
{
	char 	tmp = 'a';
	char	tmp2 = 'b';
	char	*a = &tmp;
	char	*b = &tmp2;

	ft_swap(a, b);
	assert_char(*b, 'a', (char *)__func__);
}

void	test_strcheck()
{
	char	*str = "this";

	assert_int(1, ft_ischeck_str(str, ft_isalpha), strcat(strdup((char *)__func__), " (ft_isalpha)"));
	assert_int(1, ft_ischeck_str(str, ft_isdigit), strcat(strdup((char *)__func__), " (ft_isdigit)"));
	assert_int(1, ft_ischeck_str(str, ft_isalnum), strcat(strdup((char *)__func__), " (ft_isalnum)"));
	assert_int(1, ft_ischeck_str(str, ft_isascii), strcat(strdup((char *)__func__), " (ft_isascii)"));
	assert_int(1, ft_ischeck_str(str, ft_isprint), strcat(strdup((char *)__func__), " (ft_isprint)"));
	assert_int(1, ft_ischeck_str(str, ft_islower), strcat(strdup((char *)__func__), " (ft_islower)"));
	assert_int(1, ft_ischeck_str(str, ft_isupper), strcat(strdup((char *)__func__), " (ft_isupper)"));
}

void	test_ft_printf()
{
	char			test_char = 'a';
	char			*test_str = "|I AM A TEST STRINGS|";
	int				test_int_val = INT_MIN;
	int				*test_int_ptr = &test_int_val;
	unsigned int	test_unsigned_int = 123456;


	printf(BLU"\n%s\n"reset, EDGES);
	printf("\n	Own: 			%d chars\n\n", ft_printf(GRN"This is %c test for char."reset, test_char));
	printf("\n	Original:		%d chars", printf(GRN"This is %c test for char."reset, test_char));
	printf(BLU"\n%s\n"reset, EDGES);

	printf(BLU"\n%s\n"reset, EDGES);
	printf("\n	Own: 			%d chars\n\n", ft_printf(GRN"This is %c test for char and this is a test for %yyy"reset, test_char));
	printf("\n	Original:		%d chars", printf(GRN"This is %c test for char and this is a test for %yyy"reset, test_char));
	printf(BLU"\n%s\n"reset, EDGES);

	printf(BLU"\n%s\n"reset, EDGES);
	printf("\n	Own:			%d chars\n\n", ft_printf(GRN"This is a test for str %s."reset, test_str));
	printf("\n	Original:		%d chars", printf(GRN"This is a test for str %s."reset, test_str));
	printf(BLU"\n%s\n"reset, EDGES);

	printf(BLU"\n%s\n"reset, EDGES);
	printf("\n	Own: 			%d chars\n\n", ft_printf(GRN"This is a test for digit and this is %d"reset, test_int_ptr));
	printf("\n	Original:		%d chars", printf(GRN"This is a test for digit and this is %d"reset, test_int_ptr));
	printf(BLU"\n%s\n"reset, EDGES);

	printf(BLU"\n%s\n"reset, EDGES);
	printf("\n	Own: 			%d chars\n\n", ft_printf(GRN"This is a test for int and this is %i"reset, test_int_ptr));
	printf("\n	Original:		%d chars", printf(GRN"This is a test for int and this is %i"reset, test_int_ptr));
	printf(BLU"\n%s\n"reset, EDGES);

	printf(BLU"\n%s\n"reset, EDGES);
	printf("\n	Own:			%d chars\n\n", ft_printf(GRN"This is a test for lower hex and this is %x"reset, test_int_ptr));
	printf("\n	Original:		%d chars", printf(GRN"This is a test for lower hex and this is %x"reset, test_int_ptr));
	printf(BLU"\n%s\n"reset, EDGES);

	printf(BLU"\n%s\n"reset, EDGES);
	printf("\n	Own:			%d chars\n\n", ft_printf(GRN"This is a test for upper hex and this is %X"reset, test_int_ptr));
	printf("\n	Original:		%d chars", printf(GRN"This is a test for upper hex and this is %X"reset, test_int_ptr));
	printf(BLU"\n%s\n"reset, EDGES);

	printf(BLU"\n%s\n"reset, EDGES);
	printf("\n	Own: 			%d chars\n\n", ft_printf(GRN"This is a test for ptr and this is %p"reset, test_int_ptr));
	printf("\n	Original:		%d chars", printf(GRN"This is a test for ptr and this is %p"reset, test_int_ptr));
	printf(BLU"\n%s\n"reset, EDGES);

	printf(BLU"\n%s\n"reset, EDGES);
	printf("\n	Own:			%d chars\n\n", ft_printf(GRN"This is a test for unsigned int and this is %u"reset, test_int_ptr));
	printf("\n	Original:		%d chars", printf(GRN"This is a test for unsigned int and this is %u"reset, test_int_ptr));
	printf(BLU"\n%s\n"reset, EDGES);
}

void	test_printf(void)
{
	char	**array;
	int		*array_2;

	array = (char **)malloc(sizeof(char *) * 4);
	array[0] = "This is a test string 1";
	array[1] = "This is a test string 2";
	array[2] = "This is a test string 3";
	array[3] = "This is a test string 4";
	array_2 = ft_range(10, -10);
	printf(BLU"\n%s\n"reset, EDGES);
	ft_printf("This is: %a\n", array);
	ft_printf("This is: %n\n", array_2);
	printf(BLU"\n%s\n"reset, EDGES);
	free(array);
	free(array_2);
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

	printf(BBLU"\n%s\n"reset, EDGES);
	printf("|\n| %s ["BBLU"%d"reset"]\n|\n", "Opening fd with buffer size of", BUFFER_SIZE);

	while ((c_line = ft_get_next_line(fd)) != NULL)
	{
		printf("| ["BBLU"%d"reset"] - ["BGRN"%zu"reset"] - %s", i++, ft_g_strl(c_line, 0), c_line);
		free(c_line);
	}

	close(fd);
	printf("\n|"BBLU"\n%s\n"reset, EDGES);
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
	test_ft_printf();
	test_gnl_single("Makefile");
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
	test_printf();
	end_test("Additional functions");
	return (0);
}