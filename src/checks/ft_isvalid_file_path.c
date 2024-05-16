/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid_file_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:23:51 by otodd             #+#    #+#             */
/*   Updated: 2024/05/16 16:40:44 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

bool	ft_isvalid_file_path(char *p)
{
	const int	fd = open(p, O_RDONLY);

	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}
