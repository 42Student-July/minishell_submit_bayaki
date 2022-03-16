/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_export_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/16 11:14:15 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "self_cmd.h"

void	print_all_export_lst(t_exec_attr *ea)
{
	t_content_f	f;

	f = print_export_kvs;
	ft_lstiter(ea->export_lst, f);
}

void	print_export_kvs(void *content)
{
	t_kvs	*kvs;

	kvs = (t_kvs *)content;
	if (kvs->value == NULL)
		printf("declare -x %s\n", kvs->key);
	else
		printf("declare -x %s=%s\n", kvs->key, kvs->value);
}

void	export_print_err(char *arg, bool *exit_stat)
{
	print_error_msg_with_var(EXPORT, arg);
	*exit_stat = false;
}

bool	is_sharp(char *arg)
{
	if (arg == NULL)
		return (false);
	if (*arg == '#')
		return (true);
	return (false);
}
