/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito     <akito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:45:50 by akito             #+#    #+#             */
/*   Updated: 2022/03/15 14:45:50 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "lexer.h"
#include <stdbool.h>

void	delete_file(void *file_ptr)
{
	t_file	*file;

	file = (t_file *)file_ptr;
	free(file->filename);
	file->filename = NULL;
	free(file);
}
