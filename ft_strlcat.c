/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:20:33 by otodd             #+#    #+#             */
/*   Updated: 2023/11/06 17:31:06 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	index;
	size_t	result;

	d_len = ft_strlen(dest);
	s_len = ft_strlen((char *)src);
	index = 0;
	result = 0;
	if (size <= d_len)
		result = s_len + size;
	else
	{
		result = s_len + d_len;
		while (src[index] && d_len < size - 1)
			dest[d_len++] = src[index++];
	}
	dest[d_len] = '\0';
	return (result);
}

