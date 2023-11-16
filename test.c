#include "libft.h"
#include <fcntl.h>

int	main(void)
{
	int	file_descriptor = open("example.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

	ft_putnbr_fd(1233, file_descriptor);
	close(file_descriptor);
}