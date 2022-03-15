/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:29:53 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/15 16:31:41 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

char	*concat_path_and_cmd(char *path, char *command)
{
	char			*new_cmd;
	size_t			new_cmd_len;

	new_cmd_len = ft_strlen(path) + SLASH + ft_strlen(command) + NULL_CHAR;
	new_cmd = (char *)ft_xcalloc(sizeof(char), (new_cmd_len));
	ft_strlcat(new_cmd, path, new_cmd_len);
	ft_strlcat(new_cmd, "/", new_cmd_len);
	ft_strlcat(new_cmd, command, new_cmd_len);
	return (new_cmd);
}

bool	is_invalid_permission(\
	char *path, char *command, size_t cmd_i, t_exec_attr *ea)
{
	char		*cmd_path;
	struct stat	stat_buf;
	bool		invalid_flag;

	cmd_path = concat_path_and_cmd(path, command);
	invalid_flag = false;
	if (stat(cmd_path, &stat_buf) == -1)
		exit(EXIT_FAILURE);
	if ((stat_buf.st_mode & S_IXUSR) != S_IXUSR)
		invalid_flag = true;
	if ((stat_buf.st_mode & S_IRUSR) != S_IRUSR)
		invalid_flag = true;
	if (invalid_flag)
		ea->has_not_permission[cmd_i] = true;
	free(cmd_path);
	return (invalid_flag);
}

char	*create_cmd(char *path, char *command, DIR *dirp)
{
	char	*cmd;

	cmd = concat_path_and_cmd(path, command);
	closedir(dirp);
	return (cmd);
}
