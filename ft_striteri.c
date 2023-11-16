/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wolfie <wolfie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:33:46 by wolfie            #+#    #+#             */
/*   Updated: 2023/11/16 15:40:17 by wolfie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t			index;
	size_t const	len = ft_strlen(s);

	if (!s)
		return ;
	index = 0;
	while (index < len)
	{
		(*f)(index, s + index);
		index++;
	}
}
