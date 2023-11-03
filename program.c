#include "libft.h"
#include "ANSI-color-codes.h"
#include <bsd/string.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>


void	asset_char(char original, char ft, char *func)
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

void	asset_str(char *original, char *ft, char *func)
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

void	asset_int(int original, int ft, const char *func)
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

	asset_int(isalpha(test), ft_isalpha(test), __func__);
}

void	test_isdigit()
{
	int	test = 1;

	asset_int(isdigit(test), ft_isdigit(test), __func__);
}

void	test_isalnum()
{
	int	test = 'a';

	asset_int(isalnum(test), ft_isalnum(test), __func__);
}

void	test_isascii()
{
	int	test = 'a';

	asset_int(isascii(test), ft_isascii(test), __func__);
}

void	test_isalpha()
{
	int	test = 'a';

	asset_int(isalpha(test), ft_isalpha(test), __func__);
}

void	test_isalpha()
{
	int	test = 'a';

	asset_int(isalpha(test), ft_isalpha(test), __func__);
}

void	test_isalpha()
{
	int	test = 'a';

	asset_int(isalpha(test), ft_isalpha(test), __func__);
}

int	main(void)
{
	test_isalpha();
	return (0);
}