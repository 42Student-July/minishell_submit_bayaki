/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_exec_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:45:50 by akito             #+#    #+#             */
/*   Updated: 2022/03/15 15:27:29 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

void	skip_to_null(t_list **lst, char	**literal)
{
	while (*lst)
	{
		literal = (*lst)->content;
		if (literal != NULL)
			break ;
		*lst = (*lst)->next;
	}
}

t_list	*copy_except_null(t_list *lst, t_list *now, char *literal)
{
	t_list	*res;
	t_list	*tmp;

	res = now;
	while (lst->next != NULL)
	{
		literal = lst->next->content;
		if (literal != NULL)
		{
			tmp = ft_lstnew(ft_xstrdup(literal));
			if (tmp == NULL)
			{
				ft_lstclear(&res, free);
				return (res);
			}
			now->next = tmp;
			now = now->next;
			lst = lst->next;
		}
		else
			lst = lst->next;
	}
	return (res);
}
