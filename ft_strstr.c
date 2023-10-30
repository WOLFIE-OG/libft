/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:40:46 by otodd             #+#    #+#             */
/*   Updated: 2023/10/18 11:23:04 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	char	*str_start;

	str_start = str;
	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		str_start = str;
		while (*str && *to_find && *str == *to_find)
		{
			str++;
			to_find++;
		}
		if (*to_find == '\0')
			return (str_start);
		str = str_start + 1;
	}
	return (NULL);
}
