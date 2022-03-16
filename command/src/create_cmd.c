/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/16 20:48:16 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/command.h"

char	*create_cmd_from_path(\
	char *cmd, char **path, t_exec_attr *ea, size_t cmd_i)
{
	DIR				*dirp;
	struct dirent	*dp;

	while (*path != NULL)
	{
		dirp = opendir(*path);
		if (dirp != NULL)
		{
			dp = readdir(dirp);
			while (dp != NULL)
			{
				if (is_same_str(dp->d_name, cmd))
				{
					if (is_invalid_permission(*path, cmd, cmd_i, ea))
						break ;
					return (create_cmd(*path, cmd, dirp));
				}
				dp = readdir(dirp);
			}
			closedir(dirp);
		}
		path++;
	}
	return (NULL);
}

char	*replace_colon_to_currentdir(char *env_path)
{
	char	*ret;
	char	*tmp;

	if (env_path[0] == ':')
	{
		ret = ft_xstrjoin(".", env_path);
		free(env_path);
		return (ret);
	}
	ret = ft_replace_str(env_path, "::", ":.:");
	if (env_path[ft_strlen(env_path) - 1] == ':')
	{
		tmp = ft_xstrjoin(ret, ".");
		free(ret);
		ret = tmp;
	}
	return (ret);
}

char	*find_path(char *cmd_name, t_exec_attr *ea, size_t cmd_i)
{
	char			*env_path;
	char			**path;
	char			*new_cmd;
	t_list			*lst;

	lst = get_lst_by_key(ea->env_lst, "PATH");
	if (lst == NULL)
		return (NULL);
	env_path = ft_kvsget_value(lst->content);
	if (env_path == NULL)
		return (NULL);
	env_path = replace_colon_to_currentdir(env_path);
	path = ft_xsplit(env_path, ':');
	new_cmd = create_cmd_from_path(cmd_name, path, ea, cmd_i);
	free_char_dptr(path);
	free(env_path);
	if (new_cmd == NULL)
		return (NULL);
	return (new_cmd);
}
