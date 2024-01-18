/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:37:02 by otodd             #+#    #+#             */
/*   Updated: 2024/01/18 17:07:04 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*proxy_d;
	const unsigned char		*proxy_s = src;

	if (!dest && !src)
		return (NULL);
	proxy_d = dest;
	while (n--)
		*proxy_d++ = *proxy_s++;
	return (dest);
}
