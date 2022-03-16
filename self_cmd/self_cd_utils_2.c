/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_cd_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:52:43 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/16 15:43:27 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "self_cmd.h"

char	*create_str_removed_end(char *path)
{
	size_t	i;

	i = 0;
	while (path[i] != '\0')
		i++;
	path[i - 1] = '\0';
	return (ft_xstrdup(path));
}

size_t	count_rm_rel_path(char **split)
{
	long long	i;
	long long	new_split_len;
	long long	ddot_count;
	long long	dot_count;
	long long	blank_count;

	i = 0;
	new_split_len = 0;
	ddot_count = 0;
	dot_count = 0;
	blank_count = 0;
	while (split[i] != NULL)
	{
		if (is_same_str("", split[i]))
			blank_count++;
		if (is_same_str(".", split[i]))
			dot_count++;
		if (is_same_str("..", split[i]))
			ddot_count++;
		i++;
	}
	if (i - blank_count - dot_count - (ddot_count * 2) + 1 < 0)
		return (-1);
	new_split_len = i - blank_count - dot_count + 1;
	return (new_split_len);
}

bool	is_blank_or_dot(char *split_path)
{
	if (is_same_str("", split_path))
		return (true);
	if (is_same_str(".", split_path))
		return (true);
	return (false);
}

bool	is_ddot(char *split_path)
{
	if (is_same_str("..", split_path))
		return (true);
	return (false);
}

char	**create_split_path_rm_rel(char **split_path, long long spath_len, size_t *new_str_len)
{
	char	**split_path_rm_rel;
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	split_path_rm_rel = (char **)ft_xmalloc(sizeof(char *) * spath_len);
	while (split_path[i] != NULL)
	{	
		if (is_blank_or_dot(split_path[i]))
			;
		else if (is_ddot(split_path[i]))
		{
			if (j != 0)
			{
				free(split_path_rm_rel[j - 1]);
				split_path_rm_rel[j - 1] = NULL;
				j--;
			}
		}
		else
		{
			split_path_rm_rel[j] = ft_strjoin("/", split_path[i]);
			*new_str_len += ft_strlen(split_path_rm_rel[j]);
			j++;
		}
		i++;
	}
	split_path_rm_rel[j] = NULL;
	return (split_path_rm_rel);
}



char *remove_relative(char *path, t_exec_attr *ea)
{
	char	**split_path;
	char	**split_path_rm_rel;
	char	*new_str;
	size_t	i;
	size_t	new_str_len;
	long long	split_path_len;

	i = 0;
	split_path = ft_xsplit(path, '/');
	split_path_len = count_rm_rel_path(split_path);
	if (split_path_len == -1)
	{
		free_char_dptr(split_path);
		return (ft_xstrdup("/"));
	}
	split_path_rm_rel = create_split_path_rm_rel(split_path, split_path_len, &new_str_len);
	new_str = (char *)ft_xcalloc(sizeof(char), new_str_len + 1);
	while (split_path_rm_rel[i] != NULL)
	{
		ft_strlcat(new_str, split_path_rm_rel[i], new_str_len + 1);
		i++;
	}
	if (is_end_of_slash(new_str))
	{
		path = create_str_removed_end(new_str);
		if (path == NULL)
			abort_minishell(MALLOC_ERROR, ea);
	}
	free_char_dptr(split_path);
	free_char_dptr(split_path_rm_rel);
	return (new_str);
}

bool	has_diff(char *path, t_exec_attr *ea)
{
	char		*cwd;
	char		*pwd;
	bool		flag;
	char		*pwd_del_dot;
	struct stat	buf;

	redirect_dev_null(ea);
	cwd = getcwd(NULL, 0);
	reset_stdfd(ea);
	if (*path == '/')
		pwd = path;
	else
		pwd = concat_new_pwd(ea->current_pwd, path);
	pwd_del_dot = remove_relative(pwd, ea);
	if (lstat(pwd_del_dot, &buf) == -1)
		flag = true;
	else
		flag = is_same_str(cwd, pwd_del_dot);
	if (*path != '/')
		free(pwd);
	free(pwd_del_dot);
	free(cwd);
	return (!flag);
}
