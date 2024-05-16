/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrayappend.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:03:18 by otodd             #+#    #+#             */
/*   Updated: 2024/05/16 17:01:23 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	**ft_strarrayappend(char **a, char *s)
{
	char	**new_array;

	new_array = (char **)malloc((ft_strarraylen(a) + 2) * sizeof(char *));
	return (ft_strarraystrcat(ft_strarraycpy(new_array, a), s));
}
