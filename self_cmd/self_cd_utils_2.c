/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_cd_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:52:43 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/16 20:52:46 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "self_cmd.h"

char	**create_rm_rel_split( \
	char **split, long long spath_len, size_t *str_len)
{
	char	**split_path_rm_rel;
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	split_path_rm_rel = (char **)ft_xmalloc(sizeof(char *) * spath_len);
	while (split[i] != NULL)
	{	
		if (is_relative_exist(split[i]))
			process_ddot(split[i], split_path_rm_rel, &j);
		else
		{
			split_path_rm_rel[j] = ft_xstrjoin("/", split[i]);
			*str_len += ft_strlen(split_path_rm_rel[j]);
			j++;
		}
		i++;
	}
	split_path_rm_rel[j] = NULL;
	return (split_path_rm_rel);
}

char	*concat_new_path(char **split, size_t new_str_len)
{
	size_t	i;
	char	*new_str;

	i = 0;
	new_str = (char *)ft_xcalloc(sizeof(char), new_str_len + 1);
	while (split[i] != NULL)
	{
		ft_strlcat(new_str, split[i], new_str_len + 1LL);
		i++;
	}
	return (new_str);
}

char	*remove_relative(char *path)
{
	size_t		new_str_len;
	long long	split_path_len;
	char		**split_path;
	char		**split_path_rm_rel;
	char		*new_str;

	new_str_len = 0;
	split_path = ft_xsplit(path, '/');
	split_path_len = count_rm_rel_path(split_path);
	if (split_path_len == -1)
	{
		free_char_dptr(split_path);
		return (ft_xstrdup("/"));
	}
	split_path_rm_rel = create_rm_rel_split(\
		split_path, split_path_len, &new_str_len);
	new_str = concat_new_path(split_path_rm_rel, new_str_len);
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
	pwd_del_dot = remove_relative(pwd);
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
