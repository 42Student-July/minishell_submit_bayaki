/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_cd_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:36:09 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/16 16:36:20 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

char	*create_str_removed_end(char *path)
{
	size_t	i;

	i = 0;
	while (path[i] != '\0')
		i++;
	path[i - 1] = '\0';
	return (ft_xstrdup(path));
}

size_t	count_rm_rel_path(char **split)
{
	long long	i;
	long long	new_split_len;
	long long	ddot_count;
	long long	dot_count;
	long long	blank_count;

	i = 0;
	new_split_len = 0;
	ddot_count = 0;
	dot_count = 0;
	blank_count = 0;
	while (split[i] != NULL)
	{
		if (is_same_str("", split[i]))
			blank_count++;
		if (is_same_str(".", split[i]))
			dot_count++;
		if (is_same_str("..", split[i]))
			ddot_count++;
		i++;
	}
	if (i - blank_count - dot_count - (ddot_count * 2) + 1 < 0)
		return (-1);
	new_split_len = i - blank_count - dot_count + 1;
	return (new_split_len);
}

bool	is_relative_exist(char *split_path)
{
	if (is_same_str("", split_path))
		return (true);
	if (is_same_str(".", split_path))
		return (true);
	if (is_same_str("..", split_path))
		return (true);
	return (false);
}

void	process_ddot(char *path, char **sp_rm_rel, size_t *j)
{
	if (!is_same_str("..", path))
		return ;
	if (*j != 0)
	{
		free(sp_rm_rel[*j - 1]);
		sp_rm_rel[*j - 1] = NULL;
		*j = *j - 1;
	}
}
