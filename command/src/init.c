/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/17 17:13:32 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	init_oldpwd(t_exec_attr *ea)
{
	del_env_lst_by_key(ea->env_lst, "OLDPWD", ea);
	del_export_lst_by_key(ea->export_lst, "OLDPWD", ea);
	del_env_lst_by_key(ea->env_lst, "PWD", ea);
	del_export_lst_by_key(ea->export_lst, "PWD", ea);
	store_arg_in_export(ea, "OLDPWD", NULL);
	store_arg_in_env(ea, "OLDPWD", NULL);
	ea->current_pwd = getcwd(NULL, 0);
	store_arg_in_export(ea, "PWD", ea->current_pwd);
	store_arg_in_env(ea, "PWD", ea->current_pwd);
}

void	store_stdfd(t_exec_attr *ea)
{
	ea->stdfd[0] = ft_xdup(STDIN_FILENO);
	ea->stdfd[1] = ft_xdup(STDOUT_FILENO);
	ea->stdfd[2] = ft_xdup(STDERR_FILENO);
}

void	init_new(t_exec_attr **ea)
{
	extern char	**environ;

	*ea = (t_exec_attr *)ft_xcalloc(sizeof(t_exec_attr), 1);
	store_allenv_in_envlst(*ea, environ);
	store_allenv_in_export(*ea, environ);
	store_stdfd(*ea);
	init_oldpwd(*ea);
}
