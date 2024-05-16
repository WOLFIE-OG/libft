/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:43:34 by otodd             #+#    #+#             */
/*   Updated: 2024/05/16 16:40:32 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

long	ft_atol(const char *n)
{
	long	value;
	int		operation;
	char	*c;

	c = (char *)n;
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
		value = (value * 10) + (*c++ - '0');
	return (value * operation);
}
