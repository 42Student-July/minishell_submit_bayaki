/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/16 10:57:15 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "self_cmd.h"

bool	check_arg(char *arg, bool *exit_status)
{
	if (arg == NULL)
		return (EXIT_FAILURE);
	if (is_invalid_name(arg))
	{
		*exit_status = false;
		print_error_msg_with_var(UNSET, arg);
	}
	return (EXIT_SUCCESS);
}

int	exec_self_unset(t_cmd *cmd, t_exec_attr *ea)
{
	t_list	*lst;
	char	*arg;
	bool	exit_status;

	exit_status = true;
	lst = cmd->args->next;
	while (lst != NULL)
	{
		arg = (char *)(lst->content);
		if (check_arg(arg, &exit_status))
			return (EXIT_FAILURE);
		del_env_lst_by_key(ea->env_lst, arg, ea);
		del_export_lst_by_key(ea->export_lst, arg, ea);
		if (is_same_str(arg, "PWD"))
		{
			free(ea->current_pwd);
			ea->current_pwd = ft_xstrdup("");
		}
		lst = lst->next;
	}
	if (exit_status)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
