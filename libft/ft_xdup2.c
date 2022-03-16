#include "libft.h"

void	ft_xdup2(int fd, int fd2)
{
	if (dup2(fd, fd2) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
}
