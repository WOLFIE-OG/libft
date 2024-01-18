/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:57:29 by otodd             #+#    #+#             */
/*   Updated: 2024/01/18 17:06:01 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	get_abs(int n)
{
	if (n == INT_MIN)
		return (INT_MAX);
	if (n < 0)
	{
		if (n == INT_MIN)
			return (INT_MAX);
		return (-n);
	}
	return (n);
}

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

	len = placements(get_abs(n)) + is_negative;
	string = malloc(sizeof(char) * (len + 1));
	string[len--] = '\0';
	if (is_negative)
		string[0] = '-';
	while (len >= is_negative)
	{
		if (n == INT_MIN)
			string[len--] = '8';
		else
			string[len--] = (get_abs(n) % 10) + '0';
		n /= 10;
	}
	return (string);
}
