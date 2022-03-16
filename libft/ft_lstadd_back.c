/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:59:34 by akito             #+#    #+#             */
/*   Updated: 2022/03/16 16:03:01 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_lstadd_back(t_list **lst, t_list *new_elm)
{
	t_list	*list;

	if (lst == NULL || new_elm == NULL)
		return (false);
	if (*lst == NULL)
		*lst = new_elm;
	else
	{
		list = ft_lstlast(*lst);
		list->next = new_elm;
	}
	return (true);
}
