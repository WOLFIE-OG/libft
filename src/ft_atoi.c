/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:43:34 by otodd             #+#    #+#             */
/*   Updated: 2024/01/18 17:05:43 by otodd            ###   ########.fr       */
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
	while ((*c == ' ') || (*c == '\t')
		|| (*c == '\v') || (*c == '\r') || (*c == '\n') || (*c == '\f'))
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
