/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/15 20:33:30 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

int	execute_cmd(t_exec_attr *ea)
{
	int	pipe_count;

	if (ea->cmd_lst == NULL)
		return (0);
	pipe_count = ft_lstsize(ea->cmd_lst) - 1;
	if (pipe_count == 0)
	{
		no_pipe_process(ea);
	}
	else
	{
		pipe_process(ea, pipe_count);
	}
	return (0);
}
