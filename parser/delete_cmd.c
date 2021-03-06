/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:45:50 by akito             #+#    #+#             */
/*   Updated: 2022/03/15 14:45:50 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	delete_cmd(t_cmd **cmd)
{
	if (cmd == NULL || *cmd == NULL)
		return ;
	free((*cmd)->cmd);
	(*cmd)->cmd = NULL;
	if ((*cmd)->args != NULL)
		ft_lstclear(&(*cmd)->args, &free);
	(*cmd)->args = NULL;
	ft_lstclear(&(*cmd)->filenames_in, delete_file);
	(*cmd)->filenames_in = NULL;
	ft_lstclear(&(*cmd)->filenames_out, delete_file);
	(*cmd)->filenames_out = NULL;
	free(*cmd);
	(*cmd) = NULL;
}

void	delete_pipe(void *cmd)
{
	t_cmd	*redirect_cmd;

	redirect_cmd = (t_cmd *)cmd;
	delete_cmd(&redirect_cmd);
}
