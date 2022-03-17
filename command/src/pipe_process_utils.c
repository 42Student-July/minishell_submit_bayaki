/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_process_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:18:03 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/17 17:14:41 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	malloc_pipe_fd(t_pipe_attr *pa)
{
	int	i;

	pa->pipe_fd = (int **)ft_xcalloc(sizeof(int *), pa->pipe_count);
	i = 0;
	while (i < pa->pipe_count)
	{
		pa->pipe_fd[i] = (int *)ft_xcalloc(sizeof(int), 2);
		i++;
	}
	return ;
}

void	malloc_cpid_array(t_pipe_attr *pa)
{
	pa->cpid_array = (int *)ft_xcalloc(sizeof(int *), (pa->pipe_count + 1));
}

void	make_pipe(t_pipe_attr *pa)
{
	if (pa->cmd_i != pa->pipe_count)
	{
		ft_xpipe(pa->pipe_fd[pa->cmd_i]);
	}
}

void	set_pipe_fd(t_pipe_attr *pa)
{
	if (pa->cmd_i == 0)
	{
		ft_xdup2(pa->pipe_fd[pa->cmd_i][PIPE_OUT], STDOUT_FILENO);
		ft_xclose(pa->pipe_fd[pa->cmd_i][PIPE_IN]);
		ft_xclose(pa->pipe_fd[pa->cmd_i][PIPE_OUT]);
	}
	else if (pa->cmd_i == pa->pipe_count)
	{
		ft_xdup2(pa->pipe_fd[pa->cmd_i - 1][PIPE_IN], STDIN_FILENO);
		ft_xclose(pa->pipe_fd[pa->cmd_i - 1][PIPE_IN]);
		ft_xclose(pa->pipe_fd[pa->cmd_i - 1][PIPE_OUT]);
	}
	else
	{
		ft_xdup2(pa->pipe_fd[pa->cmd_i - 1][PIPE_IN], STDIN_FILENO);
		ft_xdup2(pa->pipe_fd[pa->cmd_i][PIPE_OUT], STDOUT_FILENO);
		ft_xclose(pa->pipe_fd[pa->cmd_i - 1][PIPE_IN]);
		ft_xclose(pa->pipe_fd[pa->cmd_i - 1][PIPE_OUT]);
		ft_xclose(pa->pipe_fd[pa->cmd_i][PIPE_IN]);
		ft_xclose(pa->pipe_fd[pa->cmd_i][PIPE_OUT]);
	}
}

void	close_pipe(t_pipe_attr *pa)
{
	ft_xclose(pa->pipe_fd[pa->cmd_i - 1][PIPE_IN]);
	ft_xclose(pa->pipe_fd[pa->cmd_i - 1][PIPE_OUT]);
}
