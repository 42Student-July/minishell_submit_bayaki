/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_attribute_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:31:09 by mhirabay          #+#    #+#             */
/*   Updated: 2022/02/15 14:09:55 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

t_cmd	*get_cmd(t_exec_attr *ea)
{
	return ((t_cmd *)ea->cmd_lst->content);
}

// コマンド名をgetする
char	*get_cmd_name(t_list *cmd_lst)
{
	t_cmd	*cmd;

	cmd = cmd_lst->content;
	return (cmd->cmd);
}

char	**get_args(t_list *cmd_lst, t_exec_attr *ea)
{
	t_cmd	*cmd;
	char	**args;

	cmd = cmd_lst->content;
	args = convert_lst_to_argv(cmd->args);
	if (args == NULL)
		abort_minishell(MALLOC_ERROR, ea);
	return (args);
}

char	*get_cmd_arg(t_list *cmd_lst, t_exec_attr *ea)
{
	char	**args;

	args = get_args(cmd_lst, ea);
	return (args[CMD_ARG]);
}