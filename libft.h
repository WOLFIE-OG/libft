/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:51:04 by otodd             #+#    #+#             */
/*   Updated: 2023/10/30 12:34:08 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <bsd/string.h>

char			*ft_strncpy(char *dest, char *src, size_t n);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strchr(char *str, char c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strdup(char *src);
char			*ft_tolower(char *str);
char			*ft_toupper(char *str);
size_t			ft_strlcat(char *dest, char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
int				ft_atoi(const char *c);
int				ft_strlen(char *str);
int				ft_strncmp(char *s1, char *s2, size_t n);
int				ft_isalpha(int c);
int				ft_isprint(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);


#endif
