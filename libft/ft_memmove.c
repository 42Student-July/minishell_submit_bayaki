/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:59:34 by akito             #+#    #+#             */
/*   Updated: 2022/03/16 16:03:51 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*to;
	const unsigned char	*from;

	if (dest == NULL && src == NULL)
		return (NULL);
	to = (unsigned char *)dest;
	from = (unsigned const char *)src;
	if (from > to)
		ft_memcpy(dest, src, n);
	else
	{
		i = n;
		while (i > 0)
		{
			to[i - 1] = from[i - 1];
			i--;
		}
	}
	return (dest);
}
