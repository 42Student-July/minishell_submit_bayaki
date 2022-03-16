/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:59:34 by akito             #+#    #+#             */
/*   Updated: 2022/03/16 16:08:32 by akito            ###   ########.fr       */
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
	return (ft_substr(str, 0, len));
}

char	**ft_separate(char *str, char separator)
{
	char	*sep_ptr;
	char	**array;

	// 最初にでてきたseparate文字で文字列を分解する
	if (str == NULL)
		return (NULL);
	sep_ptr = ft_strchr(str, separator);
	if (sep_ptr == NULL)
		return (NULL);
	// 文字数 + NULL
	array = (char **)ft_xmalloc(sizeof(char *) * (2 + 1));
	// separator文字の後が'\0'の場合、array[1]はNULLとする。
	if (*(sep_ptr + 1) == '\0')
	{
		array[0] = ft_strcdup(str, separator);
		array[1] = NULL;
		array[2] = NULL;
		return (array);
	}
	array[0] = ft_strcdup(str, separator);
	//separatorの次の文字から'\0'までの文字列をstrdupする
	array[1] = ft_strdup(++sep_ptr);
	array[2] = NULL;
	return (array);
}
