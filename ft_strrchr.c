/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:17:45 by otodd             #+#    #+#             */
/*   Updated: 2023/11/07 18:07:13 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	*proxy_str;
	unsigned int	index;

	proxy_str = (unsigned char *)str;
	index = ft_strlen((char *)proxy_str);
	while (index-- > 0)
		if (proxy_str[index] == c)
			return ((char *)&proxy_str[index]);
	return (0);
}
