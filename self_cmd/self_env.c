/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/16 10:20:41 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "self_cmd.h"

int	exec_self_env(t_cmd *cmd, t_exec_attr *ea)
{
	(void)cmd;
	print_all_env_lst(ea);
	return (0);
}

void	print_all_env_lst(t_exec_attr *ea)
{
	t_content_f	f;

	f = print_env_kvs;
	ft_lstiter(ea->env_lst, f);
}

void	print_env_kvs(void *content)
{
	t_kvs	*kvs;

	kvs = (t_kvs *)content;
	if (kvs->value != NULL)
		printf("%s=%s\n", kvs->key, kvs->value);
}
