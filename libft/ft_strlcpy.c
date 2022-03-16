/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:59:34 by akito             #+#    #+#             */
/*   Updated: 2022/03/16 16:05:11 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	if (dst == NULL || src == NULL)
		return (0);
	src_len = ft_strlen(src);
	if (src_len + 1 < size)
	{
		ft_memmove(dst, src, src_len + 1);
	}
	else if (size > 0)
	{
		ft_memmove(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (src_len);
}
