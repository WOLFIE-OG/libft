/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:43:34 by otodd             #+#    #+#             */
/*   Updated: 2024/02/12 13:22:41 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_atoi(const char *nptr)
{
	int		value;
	int		operation;
	char	*c;

	c = (char *)nptr;
	operation = 1;
	value = 0;
	while (ft_iswhitespace(*c))
		c++;
	if (*c == '+' || *c == '-')
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
