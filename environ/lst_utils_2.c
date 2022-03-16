/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/16 20:51:48 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

bool	update_value(t_list *lst, char *key, char *new_v)
{
	t_list	*target;
	char	*tmp;

	if (new_v == NULL)
		return (true);
	target = get_lst_by_key(lst, key);
	if (target == NULL)
	{
		if (!ft_lstadd_back(&lst, \
			ft_xlstnew(ft_kvsnew(key, new_v))))
			return (false);
		return (true);
	}
	tmp = ft_xstrdup(new_v);
	ft_kvsreplace_value(target->content, tmp);
	return (true);
}

void	del_export_lst_by_key(t_list *lst, char *key, t_exec_attr *ea)
{
	t_list	*target;

	target = get_lst_by_key(lst, key);
	if (target == NULL)
		return ;
	ft_kvsdelete(target->content);
	if (lst == target)
	{
		ea->export_lst = target->next;
		free(target);
		return ;
	}
	ft_lstdel(lst, target);
}
