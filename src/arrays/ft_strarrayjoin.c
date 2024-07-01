/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrayjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:03:18 by otodd             #+#    #+#             */
/*   Updated: 2024/05/16 17:27:10 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	**ft_strarrayjoin(char **a1, char **a2)
{
	char	**new_array;

	new_array = (char **)malloc((ft_strarraylen(a1)
				+ ft_strarraylen(a2) + 1) * sizeof(char *));
	return (ft_strarraycat(ft_strarraycpy(new_array, a1), a2));
}
