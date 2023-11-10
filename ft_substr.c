/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:51:27 by otodd             #+#    #+#             */
/*   Updated: 2023/11/10 18:15:30 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_string;
	size_t	index;

	index = 0;
	new_string = malloc(sizeof(char *) * len);
	while (index != len)
	{
		new_string[index] = s[start];
		index++;
		start++;
	}
	new_string[index] = '\0';
	return (new_string);
}