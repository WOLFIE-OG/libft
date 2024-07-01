/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_strarray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:30:54 by otodd             #+#    #+#             */
/*   Updated: 2024/07/01 17:37:00 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_is_in_strarray(char **a, char *s)
{
	static size_t	c = 0;

	while (*a)
	{
		if (ft_strcmp(*a, s) == 0)
			c++;
		a++;
	}
	return (c);
}
