/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:20:33 by otodd             #+#    #+#             */
/*   Updated: 2023/10/30 12:33:41 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	index;
	size_t	result;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	index = 0;
	result = 0;
	if (size > d_len)
		result = s_len + d_len;
	else
		result = s_len + size;
	while (src[index] && (d_len + 1) < size)
		dest[d_len++] = src[index++];
	dest[d_len] = '\0';
	return (result);
}
