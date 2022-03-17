/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/17 17:14:29 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/command.h"

char	*create_env_oneline(t_list *tmp, size_t i, size_t lst_size)
{
	char	*key;
	char	*value;
	char	*ret;

	key = ft_kvsget_key(tmp->content);
	value = ft_kvsget_value(tmp->content);
	if (i == lst_size - 1)
	{
		if (value == NULL)
			ret = create_env_line_non_value(key, true);
		else
			ret = create_env_line(key, value, true);
	}
	else
	{
		if (value == NULL)
			ret = create_env_line_non_value(key, false);
		else
			ret = create_env_line(key, value, false);
	}
	return (ret);
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
	array = (char **)ft_xcalloc(sizeof(char *), (env_lst_size + NULL_CHAR));
	while (i < env_lst_size)
	{
		array[i] = create_env_oneline(tmp, i, env_lst_size);
		tmp = tmp->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	*create_env_line(char *key, char *value, bool is_end)
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
