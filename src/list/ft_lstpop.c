/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:08:10 by otodd             #+#    #+#             */
/*   Updated: 2024/07/01 15:40:56 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list	*ft_lstpop(t_list *node)
{
	if (!node)
		return (NULL);
	if (node->next)
		node->next->previous = node->previous;
	if (node->previous)
		node->previous->next = node->next;
	return (node);
}
