/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:04:32 by otodd             #+#    #+#             */
/*   Updated: 2024/09/12 13:08:57 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strappend(char *s, char c)
{
	char	*str;

	if (!s)
	{
		s = malloc(sizeof(char));
		if (!s)
			return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(s) + 2));
	if (!str)
		return (NULL);
	ft_strcpy(str, s);
	str[ft_strlen(s)] = c;
	str[ft_strlen(s) + 1] = '\0';
	free(s);
	return (str);
}
