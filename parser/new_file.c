/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:45:50 by akito             #+#    #+#             */
/*   Updated: 2022/03/15 15:17:21 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include "parser.h"
#include <stdbool.h>

t_file	*new_file(char *filename, bool is_double)
{
	t_file	*file;

	file = (t_file *)ft_xcalloc(sizeof(t_file), 1);
	if (filename != NULL)
		file->filename = ft_xstrdup(filename);
	else
		file->filename = NULL;
	file->is_double = is_double;
	return (file);
}
