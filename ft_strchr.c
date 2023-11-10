/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:17:45 by otodd             #+#    #+#             */
/*   Updated: 2023/11/10 13:43:09 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*proxy_str;

	proxy_str = (char *)s;
	while (*proxy_str)
		if (*proxy_str++ == c)
			return (--proxy_str);
	return (NULL);
}
