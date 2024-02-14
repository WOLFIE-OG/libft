/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:33:24 by otodd             #+#    #+#             */
/*   Updated: 2024/02/14 18:57:01 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	*ft_range(int min, int max)
{
	int	index;
	int	*range;
	int	step;

	if (min == max)
		return (NULL);
	if (min < max)
		step = 1;
	else
		step = -1;
	range = malloc(sizeof(int) * (ft_abs(max - min) + 1));
	if (!range)
		return (NULL);
	index = 0;
	while (min != max)
	{
		range[index++] = min;
		min += step;
	}
	range[index] = INT_MAX;
	return (range);
}
