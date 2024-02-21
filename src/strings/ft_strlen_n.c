/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:40:37 by otodd             #+#    #+#             */
/*   Updated: 2024/02/21 17:41:13 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlen_n(const char *s)
{
	size_t	length;

	length = 0;
	while (*s && *s++ != '\n')
		length++;
	return (length);
}
