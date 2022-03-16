/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kvsget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:59:34 by akito             #+#    #+#             */
/*   Updated: 2022/03/16 15:59:34 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_kvsget(t_list *lst, char *key)
{
	t_list	*ret;

	ret = lst;
	while (ret != NULL)
	{
		if (ft_streq(ft_kvsget_key(ret->content), key))
			return (((t_kvs *)ret->content)->value);
		ret = ret->next;
	}
	return (NULL);
}
