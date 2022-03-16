/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/16 11:14:41 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "self_cmd.h"

int	exec_self_export(t_cmd *cmd, t_exec_attr *ea)
{
	char	*argv_one;
	bool	exit_stat;

	exit_stat = true;
	argv_one = get_argv_one(cmd);
	if (argv_one == NULL || is_sharp(argv_one))
		print_all_export_lst(ea);
	else
		export_with_args(cmd, ea, &exit_stat);
	if (exit_stat)
		return (0);
	return (1);
}

bool	addlst_sort_by_ascii(t_list **export_lst, char **arg)
{
	bool	flag;

	flag = ft_lstadd_back(export_lst, \
			ft_lstnew(ft_kvsnew(arg[KEY], \
				create_export_value(arg[VALUE]))));
	if (!flag)
		return (false);
	sort_listkey_by_ascii(*export_lst);
	return (true);
}

int	check_export_arg(char **arg)
{
	if (is_invalid_name(arg[KEY]))
		return (INVALID_IDENTIFER);
	if (arg[VALUE] == NULL)
		return (NO_VALUE);
	return (10);
}

void	store_arg(char *arg, t_exec_attr *ea, bool *exit_stat)
{
	char		**kv;
	int			ret;

	kv = ft_separate(arg, '=');
	ret = check_export_arg(kv);
	if (ret == INVALID_IDENTIFER)
	{
		*exit_stat = false;
		print_error_msg_with_var(EXPORT, kv[KEY]);
	}
	else
	{
		if (ret == NO_VALUE)
			kv[VALUE] = ft_xstrdup("");
		if (!store_arg_in_env(ea, kv[KEY], kv[VALUE]))
			abort_minishell_with(MALLOC_ERROR, ea, kv);
		if (!store_arg_in_export(ea, kv[KEY], kv[VALUE]))
			abort_minishell_with(MALLOC_ERROR, ea, kv);
	}
	free(kv[0]);
	free(kv[1]);
	free(kv);
}

void	export_with_args(t_cmd *cmd, t_exec_attr *ea, bool *exit_stat)
{
	char		*arg;
	t_list		*lst;

	lst = cmd->args->next;
	while (lst != NULL)
	{
		arg = (char *)(lst->content);
		if (ft_strchr(arg, '=') == NULL)
		{
			if (is_invalid_name(arg))
			{
				export_print_err(arg, exit_stat);
				lst = lst->next;
				continue ;
			}
			store_arg_in_export(ea, arg, NULL);
			store_arg_in_env(ea, arg, NULL);
		}
		else if (ft_strchr(arg, '=') == arg)
			export_print_err(arg, exit_stat);
		else
			store_arg(arg, ea, exit_stat);
		lst = lst->next;
	}
}
