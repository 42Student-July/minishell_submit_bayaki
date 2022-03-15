/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/15 20:38:39 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/command.h"

bool	has_redirect_file(t_cmd *cmd)
{
	if (cmd->filenames_in != NULL || cmd->filenames_out != NULL)
		return (true);
	return (false);
}

void	redirect(t_cmd *cmd, t_exec_attr *ea)
{
	(void)ea;
	if (cmd->filenames_in != NULL)
		change_fd(cmd->filenames_in, true);
	if (cmd->filenames_out != NULL)
		change_fd(cmd->filenames_out, false);
}

void	reset_stdfd(t_exec_attr *ea)
{
	dup2(ea->stdfd[0], STDIN_FILENO);
	dup2(ea->stdfd[1], STDOUT_FILENO);
	dup2(ea->stdfd[2], STDERR_FILENO);
}

bool	open_files(t_cmd *cmd, t_exec_attr *ea)
{
	(void)ea;
	if (!open_files_in(cmd))
		return (false);
	if (!open_files_out(cmd))
		return (false);
	return (true);
}

bool	open_files_in_pipe(t_cmd *cmd, t_exec_attr *ea)
{
	(void)ea;
	if (!open_files_in(cmd))
		exit(EXIT_FAILURE);
	if (!open_files_out(cmd))
		exit(EXIT_FAILURE);
	return (true);
}
