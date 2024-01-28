/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:13:47 by otodd             #+#    #+#             */
/*   Updated: 2024/01/26 19:22:17 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_binary(unsigned char c)
{
	int				index;
	int				bit;
	unsigned char	character;
	char			*result;

	index = 0;
	bit = 8;
	result = ft_calloc(bit + 1, sizeof(char));
	character = c;
	while (bit > 0)
	{
		bit--;
		character = c >> bit;
		if (character % 2 == 0)
			result[index] = '0';
		else
			result[index] = '1';
		index++;
	}
	return (result);
}