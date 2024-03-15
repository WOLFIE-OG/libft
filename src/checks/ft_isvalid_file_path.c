/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid_file_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:23:51 by otodd             #+#    #+#             */
/*   Updated: 2024/03/15 13:40:12 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

bool	ft_isvalid_file_path(char *path)
{
	const int	fd = open(path, O_RDONLY);

	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}
