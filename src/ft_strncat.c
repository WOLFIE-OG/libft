/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:20:33 by otodd             #+#    #+#             */
/*   Updated: 2024/01/24 11:33:21 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	d_len;
	unsigned int	index;

	index = 0;
	d_len = ft_strlen(dest);
	while (index < nb && src[index] != '\0')
	{
		dest[d_len + index] = src[index];
		index++;
	}
	dest[d_len + index] = '\0';
	return (dest);
}
