/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrayappend2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:03:18 by otodd             #+#    #+#             */
/*   Updated: 2024/06/24 18:08:56 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	**ft_strarrayappend2(char **a, char *s)
{
	char	**new_array;
	char	**tmp;

	if (!a)
	{
		new_array = malloc(sizeof(char *) * 2);
		new_array[0] = s;
		new_array[1] = NULL;
		return (new_array);
	}
	new_array = (char **)malloc((ft_strarraylen(a) + 2) * sizeof(char *));
	tmp = ft_strarraycpy(new_array, a);
	free(a);
	return (ft_strarraystrcat(tmp, s));
}
