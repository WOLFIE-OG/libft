/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:35:27 by otodd             #+#    #+#             */
/*   Updated: 2024/02/14 18:52:48 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		if (n == INT_MIN)
		{
			ft_putchar('-');
			ft_putnbr((n / -10));
			ft_putchar('8');
		}
		else
		{
			ft_putchar('-');
			ft_putnbr(-n);
		}
	}
	else if (n < 10)
		ft_putchar((n + '0'));
	else
	{
		ft_putnbr((n / 10));
		ft_putnbr((n % 10));
	}
}
