/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipe_attr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/15 20:26:38 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

static void	free_pipe_fd(t_pipe_attr *pa)
{
	int	i;

	i = 0;
	while (i < pa->pipe_count)
	{
		free(pa->pipe_fd[i]);
		i++;
	}
	free(pa->pipe_fd);
}

void	free_pipe_attr(t_pipe_attr *pa)
{
	free_pipe_fd(pa);
	free(pa->cpid_array);
}
