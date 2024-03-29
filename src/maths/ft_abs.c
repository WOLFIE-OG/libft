/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:05:52 by otodd             #+#    #+#             */
/*   Updated: 2024/02/14 18:39:33 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_abs(int n)
{
	if (n == INT_MIN)
		return (INT_MAX);
	else if (n < 0)
		return (-n);
	else
		return (n);
}
