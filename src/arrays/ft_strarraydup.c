/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarraydup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:37:59 by otodd             #+#    #+#             */
/*   Updated: 2024/05/16 16:34:29 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	**ft_strarraydup(char **a)
{
	char	**mem;

	mem = malloc(sizeof(char *) * (ft_strarraylen(a) + 1));
	if (!mem)
		return (NULL);
	return (ft_strarraycpy(mem, a));
}
