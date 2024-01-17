/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wolfie <wolfie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:36:11 by otodd             #+#    #+#             */
/*   Updated: 2024/01/17 15:03:16 by wolfie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>

//Bonus
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Core Functions
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);

// Secondary Functions
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// Bonus functions
t_list	*ft_lstnew(void *content);

// ft_printf
int		ft_printf(const char *in, ...);
size_t	ft_printf_char(char c);
size_t	ft_printf_str(char *s);
size_t	ft_printf_arth(unsigned int n, int base, int is_upper);
size_t	ft_printf_arth_u(unsigned int n);
size_t	ft_printf_ptr(uintptr_t n_ptr);
char	*ft_printf_strchr(char const *s, int c);
int		ft_printf_get_abs(int n, int base);
int		ft_printf_is_negative_num(int n, int base);

// get_next_line

char	*ft_get_next_line(int fd);
char	*ft_g_strjoin(char *store, char *buffer);
size_t	ft_g_strl(const char *s, int type);
char	*ft_g_strchr(char const *s, int c);
char	*ft_g_read_from_buffer(int fd, char *store);
char	*ft_g_read_line(char *store);
char	*ft_g_read_after_newline(char *store);

#endif