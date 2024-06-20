/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarraystrcat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:20:33 by otodd             #+#    #+#             */
/*   Updated: 2024/06/20 14:52:00 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	**ft_strarraystrcat(char **a, char *s)
{
	char **const	cat_array = a;

	while (*a)
		a++;
	*a++ = s;
	*a = NULL;
	return (cat_array);
}
