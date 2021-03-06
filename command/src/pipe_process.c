/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/18 14:36:55 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "errno.h"

void	wait_process(t_pipe_attr *pa)
{
	int		status;
	int		i;
	pid_t	pid;
	bool	is_EINTR;

	i = 0;
	while (i < pa->pipe_count + 1)
	{
		is_EINTR = false;
		while (true)
		{
			pid = waitpid(pa->cpid_array[i], &status, 0);
			if (pid > 0)
				break ;
			if (errno == EINTR)
			{
				is_EINTR = true;
				continue ;
			}
			exit(EXIT_FAILURE);
		}
		if (!is_EINTR)
			g_exit_status = WEXITSTATUS(status);
		i++;
	}
}

char	*create_cmd_path_pipe(t_exec_attr *ea, t_pipe_attr *pa)
{
	char	*cmd_path;
	char	*cmd;

	cmd = pa->current_cmd->cmd;
	if (is_path(cmd))
		cmd_path = ft_xstrdup(cmd);
	else
	{
		cmd_path = find_path(cmd, ea, pa->cmd_i);
		if (cmd_path == NULL)
		{
			if (ea->has_not_permission[pa->cmd_i])
				exit_with_err_msg(cmd, "Permission denied", 126);
			else
				exit_with_err_msg(cmd, "command not found", 127);
		}
		if (is_dir(cmd_path))
			exit_with_err_msg(cmd, "is a directory", 126);
	}
	return (cmd_path);
}

void	process_pipe(t_exec_attr *ea, t_pipe_attr *pa)
{
	char	**cmdv;
	char	*cmd_path;
	char	**environ;

	cmdv = convert_lst_to_argv(pa->current_cmd->args);
	environ = convert_envlst_to_array(ea);
	if (has_redirect_file(pa->current_cmd))
		open_files_in_pipe(pa->current_cmd, ea);
	set_pipe_fd(pa);
	if (!is_self_cmd(pa->current_cmd->cmd))
		cmd_path = create_cmd_path_pipe(ea, pa);
	if (has_redirect_file(pa->current_cmd))
		redirect(pa->current_cmd, ea);
	if (is_self_cmd(pa->current_cmd->cmd))
		execute_self_cmd(pa->current_cmd, ea, PIPE);
	else
	{
		if (execve(cmd_path, cmdv, environ) == -1)
		{
			execve_error(errno, pa->current_cmd->cmd);
			exit(EXIT_FAILURE);
		}
	}
	free(cmd_path);
	exit(0);
}

void	exec_cmd(t_exec_attr *ea, t_pipe_attr *pa)
{
	int		pid;

	pid = fork();
	pa->cpid_array[pa->cmd_i] = pid;
	if (pid == -1)
	{
		printf("fork error\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		process_pipe(ea, pa);
	}
	else if (pa->cmd_i > 0)
	{
		close_pipe(pa);
	}
}

void	pipe_process(t_exec_attr *ea, int pipe_count)
{
	t_pipe_attr	pa;
	t_list		*tmp;

	pa.pipe_count = pipe_count;
	malloc_pipe_fd(&pa);
	malloc_cpid_array(&pa);
	ea->has_not_permission = malloc_has_not_permission(pa.pipe_count + 1);
	pa.cmd_i = 0;
	tmp = ea->cmd_lst;
	while (pa.cmd_i < pa.pipe_count + 1)
	{
		pa.current_cmd = tmp->content;
		make_pipe(&pa);
		exec_cmd(ea, &pa);
		pa.cmd_i++;
		tmp = tmp->next;
	}
	wait_process(&pa);
	free_pipe_attr(&pa);
	free(ea->has_not_permission);
}
