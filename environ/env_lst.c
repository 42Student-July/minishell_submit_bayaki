/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/16 20:51:10 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

void	store_allenv_in_envlst(t_exec_attr *ea, char **environ)
{
	size_t		i;
	char		**split;
	t_list		*env_lst;
	char		*tmp;

	i = 0;
	env_lst = NULL;
	while (environ[i] != NULL)
	{
		split = ft_separate(environ[i], '=');
		if (split[VALUE] == NULL)
		{
			tmp = ft_xstrdup("");
			ft_lstadd_back(&env_lst, ft_xlstnew(ft_kvsnew(split[KEY], tmp)));
			free(tmp);
		}
		else
			ft_lstadd_back(&env_lst, \
				ft_xlstnew(ft_kvsnew(split[KEY], split[VALUE])));
		i++;
		free_char_dptr(split);
	}
	ea->env_lst = env_lst;
}

bool	store_arg_in_env(t_exec_attr *ea, char *key, char *value)
{
	t_list	*target;

	target = get_lst_by_key(ea->env_lst, key);
	if (target != NULL)
	{
		if (!update_value(ea->env_lst, key, value))
			return (false);
	}
	else
	{
		ft_lstadd_back(&ea->env_lst, \
			ft_xlstnew(ft_kvsnew(key, value)));
	}
	return (true);
}
