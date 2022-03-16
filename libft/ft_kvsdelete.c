/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kvsdelete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:59:34 by akito             #+#    #+#             */
/*   Updated: 2022/03/16 15:59:34 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_kvsdelete(void *elm)
{
	t_kvs	*kvs;

	kvs = (t_kvs *)elm;
	free(kvs->key);
	kvs->key = NULL;
	free(kvs->value);
	kvs->value = NULL;
	free(kvs);
	kvs = NULL;
}
