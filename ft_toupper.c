/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:32:49 by otodd             #+#    #+#             */
/*   Updated: 2023/10/30 12:34:02 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_toupper(char *str)
{
	char		*new_string;
	char const 	char_offset = ('a' - 'A');

	new_string = str;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= char_offset;
		str++;
	}
	return (new_string);
}
