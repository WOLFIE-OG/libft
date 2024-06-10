/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:57:29 by otodd             #+#    #+#             */
/*   Updated: 2024/02/14 18:51:14 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_itoa(int n)
{
	const int	is_negative = ft_isnegative(n);
	int			len;
	char		*string;

	if (n == INT_MIN)
		return ("-2147483648");
	if (n == INT_MAX)
		return ("2147483647");
	n = ft_abs(n);
	len = ft_numlen(ft_abs(n)) + is_negative;
	string = (char *)malloc(sizeof(char) * (len + 1));
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
