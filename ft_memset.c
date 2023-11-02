/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:01:43 by otodd             #+#    #+#             */
/*   Updated: 2023/10/31 12:30:55 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n-- > 0)
		*ptr++ = c;
	return (s);
}

int	main(void)
{
	char	test[] = "this is a test";
	char	test2[] = "this is a test";

	ft_memset(test, '-', 10);
	memset(test2, '-', 10);
	printf("ORIGINAL: %s | FT: %s\n", test, test2);
	printf("%d", strcmp(test, test2));
	return (0);
}
