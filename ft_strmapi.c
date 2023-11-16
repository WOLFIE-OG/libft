/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wolfie <wolfie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:46:56 by wolfie            #+#    #+#             */
/*   Updated: 2023/11/16 15:29:38 by wolfie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_string;
	size_t const	len = ft_strlen(s);
	size_t			index;

	if (!s)
		return (ft_strdup(""));
	index = 0;
	new_string = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_string)
		return (NULL);
	while (index < len)
	{
		new_string[index] = f(index, s[index]);
		index++;
	}
	new_string[index] = 0;
	return (new_string);
}
