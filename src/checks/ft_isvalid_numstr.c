/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid_numstr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:07:54 by otodd             #+#    #+#             */
/*   Updated: 2024/03/13 15:24:08 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_isvalid_numstr(char *str)
{
	if (*str == '-' && *(str + 1))
		str++;
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}
