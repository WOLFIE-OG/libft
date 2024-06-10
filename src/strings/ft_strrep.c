/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:17:45 by otodd             #+#    #+#             */
/*   Updated: 2024/05/21 15:10:45 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strrep(char const *str, int chr)
{
	size_t	count;
	bool	found;

	count = 0;
	found = false;
	while (*str)
	{
		if (*str == chr && !found)
			found = true;
		if (found)
		{
			if (*str == chr)
				count++;
			else
				return (count);
		}
		str++;
	}
	return (count);
}
