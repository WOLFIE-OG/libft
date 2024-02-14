/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:40:46 by otodd             #+#    #+#             */
/*   Updated: 2024/02/14 18:55:58 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	char	*sub_string;

	sub_string = to_find;
	while (*str)
	{
		if (*to_find == '\0')
			return (str - ft_strlen(sub_string));
		while (*str == *to_find)
			to_find++;
		str++;
	}
	return (0);
}
