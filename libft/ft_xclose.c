#include "libft.h"
#include  <unistd.h>

void ft_xclose(int fd)
{
	if (close(fd) == -1)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
}
