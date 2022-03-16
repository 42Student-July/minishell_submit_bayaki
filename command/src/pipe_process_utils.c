/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_process_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:18:03 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/16 14:46:53 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	malloc_pipe_fd(t_pipe_attr *pa)
{
	int	i;

	pa->pipe_fd = (int **)malloc(sizeof(int *) * pa->pipe_count);
	if (pa->pipe_fd == NULL)
	{
		printf("malloc error\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < pa->pipe_count)
	{
		pa->pipe_fd[i] = (int *)malloc(sizeof(int) * 2);
		if (pa->pipe_fd[i] == NULL)
		{
			printf("malloc error\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return ;
}

void	malloc_cpid_array(t_pipe_attr *pa)
{
	pa->cpid_array = (int *)malloc(sizeof(int *) * (pa->pipe_count + 1));
	if (pa->cpid_array == NULL)
	{
		printf("malloc error\n");
		exit(EXIT_FAILURE);
	}
}

void	make_pipe(t_pipe_attr *pa)
{
	if (pa->cmd_i != pa->pipe_count)
	{
		pipe(pa->pipe_fd[pa->cmd_i]);
	}
}

void	set_pipe_fd(t_pipe_attr *pa)
{
	if (pa->cmd_i == 0)
	{
		ft_xdup2(pa->pipe_fd[pa->cmd_i][PIPE_OUT], STDOUT_FILENO);
		close(pa->pipe_fd[pa->cmd_i][PIPE_IN]);
		close(pa->pipe_fd[pa->cmd_i][PIPE_OUT]);
	}
	else if (pa->cmd_i == pa->pipe_count)
	{
		ft_xdup2(pa->pipe_fd[pa->cmd_i - 1][PIPE_IN], STDIN_FILENO);
		close(pa->pipe_fd[pa->cmd_i - 1][PIPE_IN]);
		close(pa->pipe_fd[pa->cmd_i - 1][PIPE_OUT]);
	}
	else
	{
		ft_xdup2(pa->pipe_fd[pa->cmd_i - 1][PIPE_IN], STDIN_FILENO);
		ft_xdup2(pa->pipe_fd[pa->cmd_i][PIPE_OUT], STDOUT_FILENO);
		close(pa->pipe_fd[pa->cmd_i - 1][PIPE_IN]);
		close(pa->pipe_fd[pa->cmd_i - 1][PIPE_OUT]);
		close(pa->pipe_fd[pa->cmd_i][PIPE_IN]);
		close(pa->pipe_fd[pa->cmd_i][PIPE_OUT]);
	}
}

void	close_pipe(t_pipe_attr *pa)
{
	close(pa->pipe_fd[pa->cmd_i - 1][PIPE_IN]);
	close(pa->pipe_fd[pa->cmd_i - 1][PIPE_OUT]);
}
