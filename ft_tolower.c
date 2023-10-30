/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:32:49 by otodd             #+#    #+#             */
/*   Updated: 2023/10/30 12:33:56 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_tolower(char *str)
{
	char		*new_string;
	char const 	char_offset = ('a' - 'A');

	new_string = str;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += char_offset;
		str++;
	}
	return (new_string);
}
