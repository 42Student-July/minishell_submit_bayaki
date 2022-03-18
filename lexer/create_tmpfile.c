/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tmpfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:45:50 by akito             #+#    #+#             */
/*   Updated: 2022/03/18 16:42:07 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

char	*get_tmpfile_name(char *suffix)
{
	char	*tmp;

	tmp = ft_xstrjoin("/tmp/minishell-thd-", suffix);
	free(suffix);
	return (tmp);
}

void	write_tmpfile(char *tmpfile, char *buf)
{
	int	fd;
	int	ret;

	if (access("/tmp", F_OK) != 0)
	{
		perror("you should create tmp folder");
		exit(EXIT_FAILURE);
	}
	fd = open(tmpfile, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		exit(EXIT_FAILURE);
	if (buf != NULL)
	{
		ret = write(fd, buf, ft_strlen(buf));
		if (ret == -1)
			exit(EXIT_FAILURE);
	}
	ft_xclose(fd);
}

void	create_tmpfile(char *tmpfile)
{
	int	fd;

	if (access("/tmp", F_OK) != 0)
	{
		perror("you should create tmp folder");
		exit(EXIT_FAILURE);
	}
	fd = open(tmpfile, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		exit(EXIT_FAILURE);
	ft_xclose(fd);
}
