/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:08:10 by otodd             #+#    #+#             */
/*   Updated: 2024/08/15 15:36:53 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstinsert(t_list *node, t_list *target_node)
{
	if (!node || !target_node)
		return ;
	node->next = target_node;
	node->previous = target_node->previous;
	if (target_node->previous)
		target_node->previous->next = node;
	target_node->previous = node;
	return ;
}
