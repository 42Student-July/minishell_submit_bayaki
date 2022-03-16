/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:59:34 by akito             #+#    #+#             */
/*   Updated: 2022/03/16 16:03:07 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_lstdel(t_list *lst, t_list *target)
{
	if (lst == NULL || target == NULL)
		return (false);
	while (lst->next != NULL)
	{
		if (lst->next == target)
		{
			lst->next = target->next;
			free(target);
			return (true);
		}
		lst = lst->next;
	}
	return (false);
}
