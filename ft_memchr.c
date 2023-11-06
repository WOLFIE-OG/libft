#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
	char	*proxy_s;
	size_t	index;

	index = 0;
	proxy_s = (char *)s;
	while (proxy_s[index] && index < n)
		if (proxy_s[index++] == c)
			return ((void *)&proxy_s[index]);
	return (0);
}
