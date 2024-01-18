/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:17:45 by otodd             #+#    #+#             */
/*   Updated: 2024/01/18 17:06:06 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(char const *str, int c)
{
	char const	*last_found;

	last_found = NULL;
	while (*str)
	{
		if (*str == (char)c)
			last_found = str;
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return ((char *)last_found);
}
