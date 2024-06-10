/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarraycat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:20:33 by otodd             #+#    #+#             */
/*   Updated: 2024/05/16 16:33:29 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_strarraycat(char **dest, char **src)
{
	char **const	cat_array = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (cat_array);
}
