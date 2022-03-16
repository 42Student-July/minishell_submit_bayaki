/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:30:06 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/16 14:59:44 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	redirect_dev_null(t_exec_attr *ea)
{
	int	fd;

	(void)ea;
	fd = open("/dev/null", O_WRONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	ft_xdup2(fd, STDOUT_FILENO);
	ft_xclose(fd);
}

bool	open_files_in(t_cmd *cmd)
{
	t_list	*current_filename;
	t_file	*f;
	int		fd;

	current_filename = cmd->filenames_in;
	while (current_filename != NULL)
	{
		f = (t_file *)current_filename->content;
		fd = open(f->filename, O_RDONLY);
		if (fd == -1)
		{
			perror(f->filename);
			g_exit_status = EXIT_FAILURE;
			return (false);
		}
		f->fd = fd;
		current_filename = current_filename->next;
	}
	return (true);
}

bool	open_files_out(t_cmd *cmd)
{
	t_list	*current_filename;
	t_file	*f;
	int		fd;

	current_filename = cmd->filenames_out;
	while (current_filename != NULL)
	{
		f = (t_file *)current_filename->content;
		if (f->is_double)
			fd = open(f->filename, \
						O_WRONLY | O_CREAT | O_APPEND, 0666);
		else
			fd = open(f->filename, \
					O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd == -1)
		{
			perror(f->filename);
			g_exit_status = EXIT_FAILURE;
			return (false);
		}
		f->fd = fd;
		current_filename = current_filename->next;
	}
	return (true);
}

void	change_fd(t_list *files, bool is_in)
{
	t_file	*f;
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = files;
	while (tmp != NULL)
	{
		f = (t_file *)tmp->content;
		if (is_in)
			ft_xdup2(f->fd, STDIN_FILENO);
		else
			ft_xdup2(f->fd, STDOUT_FILENO);
		ft_xclose(f->fd);
		tmp = tmp->next;
		i++;
	}
}
