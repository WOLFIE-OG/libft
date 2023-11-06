/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:40:46 by otodd             #+#    #+#             */
/*   Updated: 2023/11/06 17:31:12 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	index_2;

	index = 0;
	index_2 = 0;
	if (little[index] == '\0')
		return ((char *)big);
	while (index_2 < len && big[index_2])
	{
		index = 0;
		while (little[index] && big[index_2] && (little[index] == big[index_2]))
		{
			index++;
			index_2++;
		}
		if (little[index] == '\0')
			return ((char *)&big[index_2 - index]);
		index_2 = index_2 - index + 1;
	}
	return (NULL);
}
