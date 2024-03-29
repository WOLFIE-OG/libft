/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:36:11 by otodd             #+#    #+#             */
/*   Updated: 2024/03/15 13:34:01 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <stdbool.h>
# include <fcntl.h>
# include "colour_codes.h"
# if __has_include("../src/modules/ft_printf/include/ft_printf.h")
#  include "../src/modules/ft_printf/include/ft_printf.h"
# endif
# if __has_include("../src/modules/ft_get_next_line/include/ft_get_next_line.h")
#  include "../src/modules/ft_get_next_line/include/ft_get_next_line.h"
# endif

// Bonus

# include "list.h"

// Maths

typedef struct s_vector2
{
	int	x;
	int	y;
}	t_vector2;

typedef struct s_vector3
{
	int	x;
	int	y;
	int	z;
}	t_vector3;

typedef struct s_vector4
{
	int	x;
	int	y;
	int	z;
	int	w;
}	t_vector4;

// Check Functions

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_ismath(int c);
int			ft_isnegative(int n);
int			ft_ischeck_str(char *str, int (*f)(int));
int			ft_islower(int c);
int			ft_isupper(int c);
int			ft_check_overflow(void *var, size_t type);
int			ft_iswhitespace(int c);
int			ft_isprime(int nb);
int			ft_isoperator(int c);
int			ft_isvalid_numstr(char *str);
bool		ft_isvalid_file_path(char *path);

// Converter Functions

int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_atoi(const char *nptr);
char		*ft_itoa(int n);
long		ft_atol(const char *nptr);
char		*ft_binary(unsigned char c);

// IO Functions

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putendl(char *s);
void		ft_putnbr(int n);
void		ft_putchar(char c);
void		ft_putstr(char *str);

// List functions

t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new_l);
void		ft_lstadd_front(t_list **lst, t_list *new_l);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int			ft_lstsize(t_list *lst);

// Math Functions

int			ft_abs(int n);
int			ft_sqrt(int nb);
t_vector2	*vector2(int x, int y);
t_vector3	*vector3(int x, int y, int z);
t_vector4	*vector4(int x, int y, int z, int w);

// Memory Functions

void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_swap(int *a, int *b);
void		*ft_calloc(size_t nmemb, size_t size);

// String Functions

size_t		ft_strlen(const char *s);
size_t		ft_strlen_n(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strdup(const char *s);
char		*ft_strndup(const char *s, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strcat(char *dest, char *src);
char		*ft_strncat(char *dest, char *src, unsigned int nb);
char		*ft_strstr(char *str, char *to_find);
int			ft_strcmp(const char *s1, const char *s2);

// Util functions

int			ft_numlen(int n);
int			*ft_range(int min, int max);
int			ft_max(int *tab, unsigned int len);
void		ft_free_array(char **array, size_t len);
size_t		ft_strarraylen(char **array);
char		*ft_file_extension(char *str);

#endif