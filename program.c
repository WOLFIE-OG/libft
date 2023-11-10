/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:25:14 by otodd             #+#    #+#             */
/*   Updated: 2023/11/10 18:14:49 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ANSI-color-codes.h"
#include <bsd/string.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <ctype.h>
#include <limits.h>

char EDGES[] = "====================================================================";

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
	char	test2[] = "This is a test string.";
	char	test_char = '-';
	size_t	place = 5;

	assert_str((char *)memset(test, test_char, place), (char *)ft_memset(test2, test_char, place), (char *)__func__);
}

void	test_bzero()
{
	char	test[] = "This is a test string.";
	char	test2[] = "This is a test string.";
	size_t	place = 5;

	bzero(test, place);
	ft_bzero(test2, place);
	assert_mem(test, test2, place, (char *)__func__);
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
	size_t	place = 20;

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

	assert_str(ft_substr(test_string, 0, 0), ft_substr(test_string, 0, 0), (char *)__func__);
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
	end_test("Additional functions");
	/*start_test("Non-Core functions");
	end_test("Non-Core functions");*/
	return (0);
}