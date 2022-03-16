/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:59:34 by akito             #+#    #+#             */
/*   Updated: 2022/03/16 16:02:20 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <limits.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (size == 0 || nmemb == 0)
	{
		size = 1;
		nmemb = 1;
	}
	if (nmemb > (SIZE_MAX / size))
	{
		errno = ENOMEM;
		return (NULL);
	}
	res = (void *)malloc(nmemb * size);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, size * nmemb);
	return (res);
}
