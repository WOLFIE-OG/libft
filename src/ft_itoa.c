/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:57:29 by otodd             #+#    #+#             */
/*   Updated: 2024/01/23 18:13:37 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"


static int	placements(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	is_negative_num(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	const int	is_negative = is_negative_num(n);
	int			len;
	char		*string;

	if (n == INT_MIN)
		return ("-2147483648");
	if (n == INT_MAX)
		return ("2147483647");
	n = ft_abs(n);
	len = placements(ft_abs(n)) + is_negative;
	string = malloc(sizeof(char) * (len + 1));
	string[len--] = '\0';
	if (is_negative)
		string[0] = '-';
	while (len >= is_negative)
	{
		string[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (string);
}