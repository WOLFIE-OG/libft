/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:20:32 by otodd             #+#    #+#             */
/*   Updated: 2024/02/12 15:19:45 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*p_s1 - *p_s2);
}
