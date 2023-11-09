/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:37:59 by otodd             #+#    #+#             */
/*   Updated: 2023/11/09 16:22:42 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*mem;

	mem = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!mem)
		return (NULL);
	return (ft_strcpy(mem, s));
}
