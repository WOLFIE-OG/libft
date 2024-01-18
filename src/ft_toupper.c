/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:32:49 by otodd             #+#    #+#             */
/*   Updated: 2024/01/18 17:06:07 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_toupper(int c)
{
	const unsigned char	char_offset = ('a' - 'A');

	if (c >= 'a' && c <= 'z')
		c -= char_offset;
	return (c);
}
