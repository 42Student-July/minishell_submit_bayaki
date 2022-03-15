/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_line_to_buffer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:45:50 by akito             #+#    #+#             */
/*   Updated: 2022/03/15 15:23:10 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	join_line_to_buffer(char **buffer, char **line)
{
	char	*tmp;

	tmp = ft_xstrjoin(*buffer, *line);
	free(*buffer);
	free(*line);
	*line = NULL;
	*buffer = tmp;
	tmp = ft_xstrjoin(*buffer, "\n");
	free(*buffer);
	*buffer = tmp;
}
