/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:20:32 by otodd             #+#    #+#             */
/*   Updated: 2023/10/30 12:33:51 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((n - 1) != 0 && *s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}

int	main(void)
{
	char	test[] = "tes";
	char	test2[] = "test";

	printf("Original: %d | FT: %d", strncmp(test, test2, 4), ft_strncmp(test, test2, 4));
}
