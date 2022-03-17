/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:45:50 by akito             #+#    #+#             */
/*   Updated: 2022/03/17 17:15:13 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

t_lexer	*new_lexer(const char *input)
{
	t_lexer	*lexer;

	lexer = (t_lexer *)ft_xcalloc(sizeof(t_lexer), 1);
	lexer->input = ft_xstrdup(input);
	lexer->position = 0;
	lexer->read_position = 0;
	lexer->ch = '\0';
	lexer->skip_whitespace = true;
	lexer->io_here_delimiters = NULL;
	lexer->heredocs = NULL;
	read_char(lexer);
	return (lexer);
}
