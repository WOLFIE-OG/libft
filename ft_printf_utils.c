/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wolfie <wolfie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:26:54 by wolfie            #+#    #+#             */
/*   Updated: 2024/01/17 14:42:43 by wolfie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_get_abs(int n, int base)
{
	if (base > 10)
		return (n);
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

int	ft_printf_is_negative_num(int n, int base)
{
	if (base == 10)
		if (n < 0)
			return (1);
	return (0);
}

char	*ft_printf_strchr(char const *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}
