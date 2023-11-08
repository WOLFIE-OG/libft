/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:25:14 by otodd             #+#    #+#             */
/*   Updated: 2023/11/08 14:37:16 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ANSI-color-codes.h"
#include <bsd/string.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <ctype.h>

char EDGES[] = "====================================================================";

void	assert_char(char original, char ft, char *func)
{
	int	result;

	printf("\n%s\n", EDGES);
	printf("\nFunction: "BLU"%s\n"reset, func);
	result = (original == ft);
	if (result)
	{
		printf("\n"GRN"			PASSED!\n"reset);
		printf("\nComparison result: %d\n", result);
		printf("\nExpected: "GRN"%c"reset" | Got: "GRN"%c\n"reset, original, ft);
	}
	else
	{
		printf("\n"RED"			FAILED!\n"reset);
		printf("\nComparison result: %d\n", result);
		printf("\nExpected: "GRN"%c"reset" | Got: "RED"%c\n"reset, original, ft);
	}
	printf("\n%s\n", EDGES);
}

void	assert_str(char *original, char *ft, char *func)
{
	int	result;

	printf("\n%s\n", EDGES);
	printf("\nFunction: "BLU"%s\n"reset, func);
	if (original != NULL && ft != NULL)
	{
		result = strcmp(original, ft);
		if (!result)
		{
			printf("\n"GRN"			PASSED!\n"reset);
			printf("\nComparison result: %d\n", result);
			printf("\nExpected: "GRN"%s"reset" | Got: "GRN"%s\n"reset, original, ft);
		}
		else
		{
			printf("\n"RED"			FAILED!\n"reset);
			printf("\nComparison result: %d\n", result);
			printf("\nExpected: "GRN"%s"reset" | Got: "RED"%s\n"reset, original, ft);
		}
	}
	else
	{
		printf("\n"MAG"		      Caught NULL!\n"reset);
		printf("\nOriginal: "YEL"%s"reset" | Ft: "YEL"%s\n"reset, original, ft);
	}
	printf("\n%s\n", EDGES);
}

void	assert_mem(char *original, char *ft, char *func)
{
	int	result;

	printf("\n%s\n", EDGES);
	printf("\nFunction: "BLU"%s\n"reset, func);
	if (original != NULL && ft != NULL)
	{
		result = memcmp(original, ft, strlen(original));
		if (!result)
		{
			printf("\n"GRN"			PASSED!\n"reset);
			printf("\nComparison result: %d\n", result);
			printf("\nExpected: "GRN"%s"reset" | Got: "GRN"%s\n"reset, original, ft);
		}
		else
		{
			printf("\n"RED"			FAILED!\n"reset);
			printf("\nComparison result: %d\n", result);
			printf("\nExpected: "GRN"%s"reset" | Got: "RED"%s\n"reset, original, ft);
		}
	}
	else
	{
		printf("\n"MAG"		      Caught NULL!\n"reset);
		printf("\nOriginal: "YEL"%s"reset" | Ft: "YEL"%s\n"reset, original, ft);
	}
	printf("\n%s\n", EDGES);
}

void	assert_int(int original, int ft, const char *func)
{
	int	result;

	printf("\n%s\n", EDGES);
	printf("\nFunction: "BLU"%s\n"reset, func);
	result = (original == ft);
	if (result)
	{
		printf("\n"GRN"			PASSED!\n"reset);
		printf("\nComparison result: %d\n", result);
		printf("\nExpected: "GRN"%d"reset" | Got: "GRN"%d\n"reset, original, ft);
	}
	else
	{
		printf("\n"RED"			FAILED!\n"reset);
		printf("\nComparison result: %d\n", result);
		printf("\nExpected: "GRN"%d"reset" | Got: "RED"%d\n"reset, original, ft);
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
	int	test = 1;

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

	assert_str((char *)memset(test, '-', 5), (char *)ft_memset(test2, '-', 5), (char *)__func__);
}

void	test_bzero()
{
	char	test[] = "This is a test string.";
	char	test2[] = "This is a test string.";

	bzero(test, 5);
	ft_bzero(test2, 5);
	assert_mem(test, test2, (char *)__func__);
}

void	test_memcpy()
{
	char	test_src[] = "This is a test string.";
	char	test_dest[] = "";
	char 	test_src_clone[] = "This is a test string.";
	char 	test_dest_clone[] = "";

	memcpy(test_dest, test_src, 1);
	ft_memcpy(test_dest_clone, test_src_clone, 1);
	assert_mem(test_dest, test_dest_clone, (char *)__func__);
}

void	test_memmove()
{
	char	test_src[] = "This is a test string.";
	char	test_dest[] = "";
	char 	test_src_clone[] = "This is a test string.";
	char 	test_dest_clone[] = "";

	memmove(test_dest, test_src, 1);
	ft_memmove(test_dest_clone, test_src_clone, 1);
	assert_mem(test_dest, test_dest_clone, (char *)__func__);
}

void	test_strlcpy()
{
	char	test_src[] = "This is a test string.";
	char	test_dest[] = "";
	char 	test_src_clone[] = "This is a test string.";
	char 	test_dest_clone[] = "";

	strlcpy(test_dest, test_src, 5);
	ft_strlcpy(test_dest_clone, test_src_clone, 5);
	assert_mem(test_dest, test_dest_clone, (char *)__func__);
}

void	test_strlcat()
{
	char	test_string[] = "This is";
	char	test_string_2[] = " a test string.";
	char 	test_string_clone[] = "This is";
	char 	test_string_2_clone[] = " a test string.";
	size_t	l_sizer = 3;
	size_t	test_output = strlcat(test_string, test_string_2, l_sizer);
	size_t	test_output_2 = ft_strlcat(test_string_clone, test_string_2_clone, l_sizer);
	
	assert_str(test_string_2, test_string_2_clone, (char *)__func__);
	assert_int(test_output, test_output_2, (char *)__func__);
}

void	test_toupper()
{
	char	test_char = 'a';
	
	assert_char(toupper(test_char), ft_toupper(test_char), (char *)__func__);
}

void	test_tolower()
{
	char	test_char = 'A';
	
	assert_char(tolower(test_char), ft_tolower(test_char), (char *)__func__);
}

void	test_strchr()
{
	char	test_string[] = "This is a test string, find the !.";
	char	test_char = 't';

	assert_str(strchr(test_string, test_char), ft_strchr(test_string, test_char), (char *)__func__);
}

void	test_strrchr()
{
	char	test_string[] = "This is a test string, find the !.";
	char	test_char = 't';

	assert_str(strrchr(test_string, test_char), ft_strrchr(test_string, test_char), (char *)__func__);
}

void	test_strncmp()
{
	char	test_string[] = "AThis is a test string.";
	char	test_string_2[] = "This is a test string.";

	assert_int(strncmp(test_string, test_string_2, 3), ft_strncmp(test_string, test_string_2, 3), (char *)__func__);

}

void	test_memchr()
{
	char	test_string[] = "This is a test string, find the !.";
	char	test_char = 't';

	assert_mem(memchr(test_string, test_char, sizeof(test_string)), ft_memchr(test_string, test_char, sizeof(test_string)), (char *)__func__);
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
	const char	num_string[] = "a12345678";

	assert_int(atoi(num_string), ft_atoi(num_string), (char *)__func__);
}

int	main(void)
{
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
	test_strnstr();
	test_atoi();
	return (0);
}