/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:59:34 by akito             #+#    #+#             */
/*   Updated: 2022/03/16 16:08:07 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut_back(char *str, char c)
{
// 後ろから特定の文字を探し、存在した場合その文字を含めたそれ以降の文字をcutする
	char	*position;
	char	*tmp;
	size_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	tmp = str;
	position = ft_strrchr(str, c);
	if (position == NULL)
		return (NULL);
	while (tmp++ != position)
		i++;
	return (ft_substr(str, 0, i));
}
