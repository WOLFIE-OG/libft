/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:01:06 by otodd             #+#    #+#             */
/*   Updated: 2023/11/06 18:37:18 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*proxy_d;
	unsigned const char	*proxy_s = src;
	unsigned char		*end_d;
	unsigned char		*end_s;

	proxy_d = dest;
	if (proxy_d < proxy_s)
		while (n--)
			*proxy_d++ = *proxy_s++;
	else
	{
		end_d = proxy_d + (n - 1);
		end_s = (char *)proxy_s + (n - 1);
		while (n--)
			*end_d-- = *end_s--;
	}
	return (dest);
}
