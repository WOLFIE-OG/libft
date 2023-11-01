/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:37:02 by otodd             #+#    #+#             */
/*   Updated: 2023/10/31 15:25:27 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>
#include <string.h>
#include <assert.h>
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*proxy_d;
	const char	*proxy_s = src;

	proxy_d = dest;
	while (n--)
		*proxy_d++ = *proxy_s++;
	return (dest);
}
/*
int main() {
    // Test Case 1: Test copying from src to dest (non-overlapping)
    char src1[] = "Hello, World!";
    char dest1[15];
    ft_memcpy(dest1, src1, strlen(src1) + 1);
    assert(strcmp(dest1, "Hello, World!") == 0);

    // Test Case 2: Test copying from src to dest (non-overlapping)
    char src2[] = "Testing non-overlapping";
    char dest2[15];
    ft_memcpy(dest2, src2, 14);
    assert(strcmp(dest2, "Testing non") == 0);

    // Test Case 3: Test copying from src to dest (non-overlapping)
    char src3[] = "12345";
    char dest3[15];
    ft_memcpy(dest3, src3, 5);
    assert(strcmp(dest3, "12345") == 0);

    // Test Case 4: Test copying from src to dest (non-overlapping)
    char src4[] = "No change";
    char dest4[15];
    ft_memcpy(dest4, src4, strlen(src4) + 1);
    assert(strcmp(dest4, "No change") == 0);

    printf("All non-overlapping tests passed!\n");

    return 0;
}
*/