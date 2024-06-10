/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:03:18 by otodd             #+#    #+#             */
/*   Updated: 2024/02/14 18:55:33 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;

	new_string = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	return (ft_strcat(ft_strcpy(new_string, (char *)s1), (char *)s2));
}
