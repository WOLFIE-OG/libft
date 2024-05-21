/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarraychr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:17:45 by otodd             #+#    #+#             */
/*   Updated: 2024/05/21 15:13:09 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strarraychr(char **a, char **c)
{
	int	index;
	int	subindex;

	index = 0;
	while (a[index] != NULL)
	{
		subindex = 0;
		while (c[subindex] != NULL)
		{
			if (ft_strcmp(a[index], c[subindex]) == 0)
				return (a[index]);
			subindex++;
		}
		index++;
	}
	return (NULL);
}
