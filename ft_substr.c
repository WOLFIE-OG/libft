/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:51:27 by otodd             #+#    #+#             */
/*   Updated: 2023/11/10 14:07:42 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_string;
	char	*proxy_s;

	proxy_s = (char *)s;
	new_string = malloc(sizeof(char *) * len);
	while (start != len)
		*new_string++ = proxy_s[start++];
	*new_string = '\0';
	return (new_string);
}
