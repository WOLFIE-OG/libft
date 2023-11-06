/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:43:34 by otodd             #+#    #+#             */
/*   Updated: 2023/11/06 17:30:28 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_valid_operator(char c)
{
	return (c == '+' || c == '-');
}

static int	ft_is_invalid_char(char c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(const char *c)
{
	int	value;
	int	operation;

	operation = 1;
	value = 0;
	while (ft_is_invalid_char(*c))
		c++;
	while (ft_is_valid_operator(*c))
	{
		if (*c == '-')
			operation *= -1;
		c++;
	}
	while (ft_isdigit(*c))
	{
		value = (value * 10) + (*c - '0');
		c++;
	}
	return (value * operation);
}
