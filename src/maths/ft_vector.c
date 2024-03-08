/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:47:39 by otodd             #+#    #+#             */
/*   Updated: 2024/03/07 19:53:13 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_vector2	*vector2(int x, int y)
{
	t_vector2	*tmp;

	tmp = malloc(sizeof(t_vector2));
	if (!tmp)
		return (NULL);
	tmp->x = 0;
	tmp->y = 0;
	if (x)
		tmp->x = x;
	if (y)
		tmp->y = y;
	return (tmp);
}

t_vector3	*vector3(int x, int y, int z)
{
	t_vector3	*tmp;

	tmp = malloc(sizeof(t_vector3));
	if (!tmp)
		return (NULL);
	tmp->x = 0;
	tmp->y = 0;
	tmp->z = 0;
	if (x)
		tmp->x = x;
	if (y)
		tmp->y = y;
	if (z)
		tmp->z = z;
	return (tmp);
}

t_vector4	*vector4(int x, int y, int z, int w)
{
	t_vector4	*tmp;

	tmp = malloc(sizeof(t_vector4));
	if (!tmp)
		return (NULL);
	tmp->x = 0;
	tmp->y = 0;
	tmp->z = 0;
	tmp->w = 0;
	if (x)
		tmp->x = x;
	if (y)
		tmp->y = y;
	if (z)
		tmp->z = z;
	if (w)
		tmp->w = w;
	return (tmp);
}
