/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:51:27 by otodd             #+#    #+#             */
/*   Updated: 2023/11/14 15:33:46 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_string;
	size_t	index;

	if (!s)
		return (NULL);
	index = 0;
	new_string = (char *)malloc((len + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	while (start < ft_strlen(s) && index < len)
		new_string[index++] = s[start++];
	new_string[index] = '\0';
	return (new_string);
}
