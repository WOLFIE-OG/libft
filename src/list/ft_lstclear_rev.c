/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_rev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:21:21 by otodd             #+#    #+#             */
/*   Updated: 2024/06/28 14:10:18 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstclear_rev(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp_2;

	tmp = *lst;
	while (tmp)
	{
		tmp_2 = tmp->previous;
		ft_lstdelone(tmp, del);
		tmp = tmp_2;
	}
	*lst = NULL;
}
