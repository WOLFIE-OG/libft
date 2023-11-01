/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:07:32 by otodd             #+#    #+#             */
/*   Updated: 2023/10/30 12:33:31 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;
	size_t	s_len;
	char	*proxy_s;

	index = 0;
	proxy_s = (char *)src;
	s_len = ft_strlen(proxy_s);
	if (!dest)
		return (0);
	if (!size)
		return (s_len);
	while (proxy_s[index] && index < size - 1)
	{
		dest[index] = proxy_s[index];
		index++;
	}
	dest[index] = '\0';
	return (s_len);
}
