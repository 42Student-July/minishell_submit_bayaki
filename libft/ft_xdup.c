#include "libft.h"
#include <unistd.h>

int	ft_xdup(int fd)
{
	const int	dup_fd = dup(fd);

	if (dup_fd == -1)
	{
		perror("dup");
		exit(EXIT_FAILURE);
	}
	return (dup_fd);
}
