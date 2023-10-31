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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*str_start;
	int		index;

	index = 0;
	str_start = big;
	if (*little == '\0')
		return (big);
	while (*big)
	{
		str_start = big;
		while (*big && *little && (*big == *little) && )
		{
			big++;
			little++;
		}
		if (*little == '\0')
			return (str_start);
		big = str_start + 1;
	}
	return (NULL);
}
