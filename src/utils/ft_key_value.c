/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:09 by otodd             #+#    #+#             */
/*   Updated: 2024/07/18 17:12:39 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static char	**ft_create_key_value(char *key, char *value)
{
	char		**final;

	final = malloc(sizeof(char *) * 3);
	final[0] = key;
	final[1] = value;
	final[2] = NULL;
	return (final);
}

char	**ft_key_value(char const *s, char c)
{
	const char	*delim_pos = ft_strchr(s, c);
	char		*key;
	char		*value;
	int			len_p1;

	if (delim_pos)
	{
		len_p1 = delim_pos - s;
		key = malloc(len_p1 + 1);
		if (!key)
			return (NULL);
		key[len_p1] = '\0';
		ft_strncpy(key, s, len_p1);
		value = ft_strdup(delim_pos + 1);
		if (!value)
			return (NULL);
	}
	else
	{
		key = ft_strdup(s);
		if (!key)
			return (NULL);
		value = NULL;
	}
	return (ft_create_key_value(key, value));
}
