#include "libft.h"
#include "ANSI-color-codes.h"
#include <bsd/string.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <ctype.h>


void	assert_char(char original, char ft, char *func)
{
	int	result;

	printf("\n=========================================================\n");
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
	printf("\n=========================================================\n");
}

void	assert_str(char *original, char *ft, char *func)
{
	int	result;

	printf("\n=========================================================\n");
	printf("\nFunction: "BLU"%s\n"reset, func);
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
	printf("\n=========================================================\n");
}

void	assert_mem(char *original, char *ft, char *func)
{
	int	result;

	printf("\n=========================================================\n");
	printf("\nFunction: "BLU"%s\n"reset, func);
	result = memcmp(original, ft, sizeof(original));
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
	printf("\n=========================================================\n");
}

void	assert_int(int original, int ft, const char *func)
{
	int	result;

	printf("\n=========================================================\n");
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
	printf("\n=========================================================\n");
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
	return (0);
}