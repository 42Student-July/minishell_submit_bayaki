/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/17 17:14:18 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

bool	is_dir(char *cmd_path)
{
	DIR	*dir;

	dir = opendir(cmd_path);
	if (dir)
		return (true);
	return (false);
}

bool	*malloc_has_not_permission(size_t size)
{
	bool	*ret;
	size_t	i;

	i = 0;
	ret = (bool *)ft_xcalloc(sizeof(bool), size);
	while (i < size)
	{
		ret[0] = false;
		i++;
	}
	return (ret);
}

bool	is_path(char *cmd)
{
	size_t	i;

	i = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '/')
			return (true);
		i++;
	}
	return (false);
}

char	*create_cmd_path(t_cmd *c, t_exec_attr *ea)
{
	char	*cmd_path;

	if (is_path(c->cmd))
		cmd_path = ft_xstrdup(c->cmd);
	else
	{
		cmd_path = find_path(c->cmd, ea, 0);
		if (cmd_path == NULL)
		{
			if (ea->has_not_permission[0])
			{
				ft_put_cmd_error(c->cmd, "Permission denied");
				g_exit_status = 126;
			}
			else
			{
				ft_put_cmd_error(c->cmd, "command not found");
				g_exit_status = 127;
			}
			return (NULL);
		}
	}
	return (cmd_path);
}
