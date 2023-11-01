#include "libft.h"


int	main(void)
{
	char t_str_src[] = "THIS";
	char t_str_dest[] = "THIS IS A TEST";

	char t_str_src_2[] = "THIS";
	char t_str_dest_2[] = "THIS IS A TEST";

	char t_str_src_3[] = "THIS";
	char t_str_dest_3[] = "THIS IS A TEST";

	char t_str_src_4[] = "THIS";
	char t_str_dest_4[] = "THIS IS A TEST";

	char t_str_src_5[] = "THIS IS A TEST";

	char t_str_src_6[] = "THIS";
	char t_str_dest_6[] = "THIS IS A TEST";

	char t_str_src_7[] = "THIS";
	char t_str_dest_7[] = "THIS IS A TEST";

	char t_str_src_8[] = "THIS IS A TEST";

	char t_str_src_9[] = "THIS IS A TEST";

	char t_str_src_10[] = "THIS";
	char t_str_dest_10[] = "THIS IS A TEST";

	char t_str_src_11[] = "THIS";
	char t_str_dest_11[] = "THIS IS A TEST";

	char t_str_src_12[] = "THIS";
	char t_str_dest_12[] = "THIS IS A TEST";

	char t_str_src_13[] = "THIS IS A TEST";
	char t_str_dest_13[] = "THIS";

	char t_str_src_14[] = "THIS IS A TEST";
	char t_str_dest_14[] = "THIS";

	char t_str_src_15[] = "THIS";

	char t_str_src_16[] = "THIS";

	char	test = 'b';
	printf("atoi 	| Original: %d		| FT: %d\n", atoi("1234"), ft_atoi("1234"));
	printf("isalpha | Original: %d		| FT: %d\n", isalpha(test), ft_isalpha(test));
	printf("isascii | Original: %d		| FT: %d\n", isascii(test), ft_isascii(test));
	printf("isdigit | Original: %d		| FT: %d\n", isdigit(test), ft_isdigit(test));
	printf("isprint | Original: %d		| FT: %d\n", isprint(test), ft_isprint(test));
	printf("strncpy | Original: %s		| FT: %s\n", strncpy(t_str_dest, t_str_src, 5), ft_strncpy(t_str_dest_2, t_str_src_2, 5));
	printf("strcpy 	| Original: %s		| FT: %s\n", strcpy(t_str_dest_3, t_str_src_3), ft_strcpy(t_str_dest_4, t_str_src_4));
	printf("strdup 	| Original: %s		| FT: %s\n", strdup(t_str_src_5), ft_strdup(t_str_src_5));
	printf("strlcat | Original: %zu		| FT: %zu\n", strlcat(t_str_dest_6, t_str_src_6, 3), ft_strlcat(t_str_dest_7, t_str_src_7, 3));
	printf("strlen 	| Original: %lu		| FT: %d\n", strlen(t_str_src_8), ft_strlen(t_str_src_8));
	printf("strchr 	| Original: %s		| FT: %s\n", strchr(t_str_src_9, 'A'), ft_strchr(t_str_src_9, 'A'));
	printf("strncmp | Original: %d		| FT: %d\n", strncmp(t_str_src_10, t_str_dest_10, 4), ft_strncmp(t_str_src_10, t_str_dest_10, 4));
	printf("strlcpy | Original: %zu		| FT: %zu\n", strlcpy(t_str_src_11, t_str_dest_11, 3), ft_strlcpy(t_str_src_12, t_str_dest_12, 3));
	printf("strnstr | Original: %s		| FT: %s\n", strnstr(t_str_src_13, t_str_dest_13, ft_strlen(t_str_src_13)), ft_strnstr(t_str_src_14, t_str_dest_14, ft_strlen(t_str_src_14)));
	printf("strchr 	| Original: %s		| FT: %s\n", strchr(t_str_src_15, 'T'), ft_strchr(t_str_src_16, 'T'));
	/*printf(" | Original: % | FT: %\n");
	printf(" | Original: % | FT: %\n");*/
	return (0);
}