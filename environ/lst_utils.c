/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/16 08:36:52 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

bool	swap_lst_content(t_list *a, t_list *b)
{
	void	*tmp;

	if (a == NULL || b == NULL)
		return (false);
	if (a->content == b->content)
	{
		return (true);
	}
	tmp = a->content;
	a->content = b->content;
	b->content = tmp;
	return (true);
}

void	sort_listkey_by_ascii(t_list *lst)
{
	t_list	*min;

	if (lst == NULL)
		return ;
	while (lst->next != NULL)
	{
		min = get_list_by_min_ascii_key(lst);
		swap_lst_content(lst, min);
		lst = lst->next;
	}
}

t_list	*get_lst_by_key(t_list *lst, char *key)
{
	t_list	*ret;

	ret = lst;
	while (ret != NULL)
	{
		if (is_same_str(ft_kvsget_key(ret->content), key))
			return (ret);
		ret = ret->next;
	}
	return (NULL);
}

t_list	*get_list_by_min_ascii_key(t_list *lst)
{
	t_list	*tmp;
	char	*min_key;
	char	*next_key;

	tmp = lst;
	while (lst->next != NULL)
	{
		min_key = ft_kvsget_key(tmp->content);
		next_key = ft_kvsget_key(lst->next->content);
		if (is_lvalue_bigger_ascii(min_key, next_key))
			tmp = lst->next;
		lst = lst->next;
	}
	return (tmp);
}

void	del_env_lst_by_key(t_list *lst, char *key, t_exec_attr *ea)
{
	t_list	*target;

	target = get_lst_by_key(lst, key);
	if (target == NULL)
		return ;
	ft_kvsdelete(target->content);
	if (lst == target)
	{
		ea->env_lst = target->next;
		free(target);
		return ;
	}
	ft_lstdel(lst, target);
}
