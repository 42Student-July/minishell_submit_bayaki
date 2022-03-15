/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/15 15:28:21 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/command.h"

bool	is_not_exec_path(const char *command)
{
	size_t	i;

	i = 0;
	while (command[i] != '\0')
	{
		if (command[i] == '/')
			return (false);
		i++;
	}
	return (true);
}

char	*create_env_line_non_value(char *key, bool is_end)
{
	size_t	key_size;
	size_t	line_size;
	char	*line;

	key_size = ft_strlen(key);
	if (is_end)
		line_size = key_size + EQUAL + NULL_CHAR;
	else
		line_size = key_size + EQUAL + LF + NULL_CHAR;
	line = (char *)ft_xcalloc(sizeof(char), line_size);
	ft_strlcat(line, key, line_size);
	ft_strlcat(line, "=", line_size);
	if (is_end)
		ft_strlcat(line, "\n", line_size);
	return (line);
}

char	**convert_envlst_to_array(t_exec_attr *ea)
{
	char	**array;
	size_t	env_lst_size;
	size_t	i;
	t_list	*tmp;

	i = 0;
	tmp = ea->env_lst;
	env_lst_size = ft_lstsize(tmp);
	array = (char **)ft_xmalloc(sizeof(char *) * (env_lst_size + NULL_CHAR));
	while (i < env_lst_size)
	{
		if (i == env_lst_size - 1)
		{
			if (ft_kvsget_value(tmp->content) == NULL)
			{
				array[i] = create_env_line_non_value(ft_kvsget_key(tmp->content), true);
			}
			else
			{
				array[i] = create_environ_line(\
					ft_kvsget_key(tmp->content), ft_kvsget_value(tmp->content), true);
			}
		}
		else
		{
			if (ft_kvsget_value(tmp->content) == NULL)
			{
				array[i] = create_env_line_non_value(ft_kvsget_key(tmp->content), false);
			}
			else
			{
				array[i] = create_environ_line(\
					ft_kvsget_key(tmp->content), ft_kvsget_value(tmp->content), false);
			}
		}
		tmp = tmp->next;
		i++;
	}
	array[i] = NULL;
	// print_array(array);
	return (array);
}


char	*create_environ_line(char *key, char *value, bool is_end)
{
	size_t	key_size;
	size_t	value_size;
	size_t	line_size;
	char	*line;

	key_size = ft_strlen(key);
	value_size = ft_strlen(value);
	if (is_end)
		line_size = key_size + EQUAL + value_size + NULL_CHAR;
	else
		line_size = key_size + EQUAL + value_size + LF + NULL_CHAR;
	line = (char *)ft_xcalloc(sizeof(char), line_size);
	ft_strlcat(line, key, line_size);
	ft_strlcat(line, "=", line_size);
	ft_strlcat(line, value, line_size);
	if (is_end)
		ft_strlcat(line, "\n", line_size);
	return (line);
}
