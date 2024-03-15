/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_extension.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:10:31 by otodd             #+#    #+#             */
/*   Updated: 2024/03/15 13:15:14 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_file_extension(char *str)
{
	char	**split;
	char	*ext;
	
	if (!ft_strlen(str))
		return (NULL);
	split = ft_split(str, '.');
	if (!split)
		return (NULL);
	if (!ft_strarraylen(split))
		return (NULL);
	ext = ft_strjoin(".", split[ft_strarraylen(split) - 1]);
	if (!ext)
		return (NULL);
	ft_free_array(split, ft_strarraylen(split));
	free(split);
	return (ext);
}
