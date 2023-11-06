/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:37:02 by otodd             #+#    #+#             */
/*   Updated: 2023/11/06 17:30:57 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*proxy_d;
	const char	*proxy_s = src;

	proxy_d = dest;
	while (n--)
		*proxy_d++ = *proxy_s++;
	return (dest);
}
