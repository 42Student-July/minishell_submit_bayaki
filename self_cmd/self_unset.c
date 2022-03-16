/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/16 15:40:11 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "self_cmd.h"

int	exec_self_unset(t_cmd *cmd, t_exec_attr *ea)
{
	t_list	*lst;
	char	*arg;
	int		exit_status;

	exit_status = true;
	lst = cmd->args->next;
	while (lst != NULL)
	{
		arg = (char *)(lst->content);
		if (arg == NULL)
			return (1);
		if (is_invalid_name(arg))
		{
			exit_status = false;
			print_error_msg_with_var(UNSET, arg);
		}
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
		return (0);
	return (1);
}
