/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:37:59 by otodd             #+#    #+#             */
/*   Updated: 2023/11/06 17:47:43 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	unsigned char	*mem;

	mem = malloc(sizeof(unsigned char *) * ft_strlen(src) + 1);
	return (ft_strcpy(mem, src));
}
