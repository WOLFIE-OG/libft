/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_overflow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:41:33 by otodd             #+#    #+#             */
/*   Updated: 2024/02/12 16:15:51 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_check_overflow(void *var, size_t type)
{
	if (type == sizeof(int))
	{
		if (*((int *)var) > INT_MAX || *((int *)var) < INT_MIN)
			return (1);
	}
	else if (type == sizeof(long))
	{
		if (*((long *)var) > LONG_MAX || *((long *)var) < LONG_MIN)
			return (1);
	}
	return (0);
}
