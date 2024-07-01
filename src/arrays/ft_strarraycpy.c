/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarraycpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:07:32 by otodd             #+#    #+#             */
/*   Updated: 2024/06/20 14:51:04 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	**ft_strarraycpy(char **dest, char **src)
{
	unsigned int		index;
	unsigned const int	len = ft_strarraylen(src);

	index = 0;
	while (index < len)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = NULL;
	return (dest);
}
