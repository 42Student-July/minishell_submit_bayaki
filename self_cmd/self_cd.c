/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/16 14:04:13 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "self_cmd.h"

bool	is_current_dir_exist(t_exec_attr *ea)
{
	char	*pwd;

	(void)ea;
	redirect_dev_null(ea);
	pwd = getcwd(NULL, 0);
	reset_stdfd(ea);
	free(pwd);
	if (pwd == NULL)
		return (false);
	return (true);
}

int	create_virtual_path(char *path, t_exec_attr *ea)
{
	char	*pwd;
	char	*new_pwd;

	pwd = ea->current_pwd;
	redirect_dev_null(ea);
	new_pwd = getcwd(NULL, 0);
	reset_stdfd(ea);
	if (new_pwd == NULL)
	{
		new_pwd = concat_new_pwd(pwd, path);
		ft_putstr_fd("cd: error retrieving current directory: ", STDERR_FILENO);
		ft_putstr_fd("getcwd: cannot access parent directories", STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	}
	update_all_environ(new_pwd, ea);
	free(new_pwd);
	return (EXIT_FAILURE);
}



char	*get_new_pwd(char *path, t_exec_attr *ea)
{
	char	*tmp;
	char	*new_pwd;

	if (has_diff(path, ea))
	{
		tmp = concat_new_pwd(ea->current_pwd, path);
		new_pwd = remove_relative(tmp, ea);
		free(tmp);
	}
	else
	{
		redirect_dev_null(ea);
		new_pwd = getcwd(NULL, 0);
		reset_stdfd(ea);
		if (new_pwd == NULL)
			return (NULL);
	}
	return (new_pwd);
}

int	x_chdir(char *arg, t_exec_attr *ea)
{
	char	*new_pwd;
	char	*path;

	if (chdir(arg) == -1)
		return (print_error(CD, arg));
	if (!is_current_dir_exist(ea))
		return (create_virtual_path(arg, ea));
	if (is_end_of_slash(arg))
		path = create_str_removed_end(arg);
	else
		path = ft_xstrdup(arg);
	new_pwd = get_new_pwd(path, ea);
	if (new_pwd == NULL)
		return (print_error(PWD, path));
	update_all_environ(new_pwd, ea);
	free(path);
	free(new_pwd);
	return (0);
}

int	exec_self_cd(t_cmd *cmd, t_exec_attr *ea)
{
	char	*argv_one;
	int		status;

	argv_one = get_argv_one(cmd);
	if (argv_one == NULL)
		return (1);
	status = x_chdir(argv_one, ea);
	return (status);
}
