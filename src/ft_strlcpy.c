/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:07:32 by otodd             #+#    #+#             */
/*   Updated: 2024/01/18 17:06:05 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			index;
	size_t			s_len;
	unsigned char	*proxy_s;

	index = 0;
	proxy_s = (unsigned char *)src;
	s_len = ft_strlen((char *)proxy_s);
	if (!dst)
		return (0);
	if (!size)
		return (s_len);
	while (proxy_s[index] && index < size - 1)
	{
		dst[index] = proxy_s[index];
		index++;
	}
	dst[index] = '\0';
	return (s_len);
}
