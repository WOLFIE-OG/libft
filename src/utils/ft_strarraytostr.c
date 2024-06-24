/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarraytostr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:00:22 by otodd             #+#    #+#             */
/*   Updated: 2024/06/24 17:13:37 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strarraytostr(char **arr)
{
	size_t	t;
	size_t	i;
	char	*r;
	char	*h;

	t = 0;
	i = 0;

	while (arr[i])
		t += ft_strlen(arr[i++]);

	r = malloc(sizeof(char) * t + 1);
	if (!r)
		return (NULL);
	i = 0;
	h = r;
	while (arr[i])
	{
		t = ft_strlen(arr[i]);
		ft_memcpy(h, arr[i++], t);
		h += t;
	}
	*h = '\0';
	return (r);
}
