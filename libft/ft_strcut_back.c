/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:59:34 by akito             #+#    #+#             */
/*   Updated: 2022/03/16 17:18:10 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut_back(char *str, char c)
{
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
