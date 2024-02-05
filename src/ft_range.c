/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:33:24 by otodd             #+#    #+#             */
/*   Updated: 2024/02/05 20:51:19 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	*ft_range(int min, int max)
{
	int	index;
	int	*range;

	if (min >= max)
		return (NULL);
	range = malloc(sizeof(int) * (max - min) + 1);
	if (!range)
		return (NULL);
	index = 0;
	while (min < max)
		range[index++] = min++;
	range[index++] = INT_MAX;
	return (range);
}
