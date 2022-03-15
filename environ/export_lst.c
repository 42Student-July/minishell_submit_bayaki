/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/16 08:54:30 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

char	*create_export_value(char *value)
{
	char		*new_value;
	size_t		new_value_len;
	size_t		value_len;

	if (value == NULL)
		value_len = 0;
	else
		value_len = ft_strlen(value);
	new_value_len = (value_len + DQUOTE + NULL_CHAR);
	new_value = (char *)ft_xcalloc(sizeof(char), new_value_len);
	if (new_value == NULL)
		return (NULL);
	ft_strlcat(new_value, "\"", new_value_len);
	if (value != NULL)
		ft_strlcat(new_value, value, new_value_len);
	ft_strlcat(new_value, "\"", new_value_len);
	return (new_value);
}

void	store_allenv_in_export(t_exec_attr *ea, char **environ)
{
	size_t		i;
	char		**split;
	t_list		*export_lst;
	char		*value;

	export_lst = NULL;
	i = 0;
	while (environ[i] != NULL)
	{
		split = ft_separate(environ[i], '=');
		if (split == NULL)
			abort_minishell(MALLOC_ERROR, ea);
		value = create_export_value(split[VALUE]);
		if (value == NULL)
			abort_minishell_with(MALLOC_ERROR, ea, split);
		if (!ft_lstadd_back(&export_lst, \
				ft_lstnew(ft_kvsnew(split[KEY], value))))
			abort_minishell_with(MALLOC_ERROR, ea, split);
		free_char_dptr(split);
		free(value);
		i++;
	}
	sort_listkey_by_ascii(export_lst);
	ea->export_lst = export_lst;
}

bool	store_arg_in_export(t_exec_attr *ea, char *key, char *value)
{
	char	*export_value;
	t_list	*target;

	if (value != NULL)
		export_value = create_export_value(value);
	else
		export_value = NULL;
	target = get_lst_by_key(ea->export_lst, key);
	if (target != NULL)
	{
		if (!update_value(ea->export_lst, key, export_value))
			return (false);
	}
	else
	{
		if (!ft_lstadd_back(&ea->export_lst, \
			ft_lstnew(ft_kvsnew(key, export_value))))
			return (false);
	}
	free(export_value);
	sort_listkey_by_ascii(ea->export_lst);
	return (true);
}
