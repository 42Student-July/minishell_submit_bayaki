/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/15 20:28:48 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

static bool	can_exit(char *cmd_path)
{
	struct stat	stat_buf;

	if (stat(cmd_path, &stat_buf) == -1)
		exit(EXIT_FAILURE);
	if ((stat_buf.st_mode & S_IXUSR) != S_IXUSR)
		return (false);
	if ((stat_buf.st_mode & S_IRUSR) != S_IRUSR)
		return (false);
	return (true);
}

void	execve_error(int cp_errno, char *cmd_path)
{
	int	exit_status;

	if (cp_errno == ENOENT)
		exit_status = 127;
	else
		exit_status = 126;
	if (cp_errno == ENOEXEC && !can_exit(cmd_path))
		cp_errno = EACCES;
	else if (cp_errno == ENOEXEC)
		exit(EXIT_SUCCESS);
	ft_put_cmd_error(cmd_path, strerror(cp_errno));
	exit(exit_status);
}
