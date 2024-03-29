/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isoperator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:10:37 by otodd             #+#    #+#             */
/*   Updated: 2024/03/13 15:13:08 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isoperator(int c)
{
	return (c == '-' || c == '+' || c == '*'
		|| c == '>' || c == '<' || c == '='
		|| c == '/' || c == '%' || c == '&' || c == '!');
}
