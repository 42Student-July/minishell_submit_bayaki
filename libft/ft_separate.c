/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:59:34 by akito             #+#    #+#             */
/*   Updated: 2022/03/16 17:18:44 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_strcdup(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != c && str[len] != '\0')
		len++;
	return (ft_xsubstr(str, 0, len));
}

char	**ft_separate(char *str, char separator)
{
	char	*sep_ptr;
	char	**array;

	if (str == NULL)
		return (NULL);
	sep_ptr = ft_strchr(str, separator);
	if (sep_ptr == NULL)
		return (NULL);
	array = (char **)ft_xmalloc(sizeof(char *) * (2 + 1));
	if (*(sep_ptr + 1) == '\0')
	{
		array[0] = ft_strcdup(str, separator);
		array[1] = NULL;
		array[2] = NULL;
		return (array);
	}
	array[0] = ft_strcdup(str, separator);
	array[1] = ft_xstrdup(++sep_ptr);
	array[2] = NULL;
	return (array);
}
