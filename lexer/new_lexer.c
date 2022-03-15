/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:45:50 by akito             #+#    #+#             */
/*   Updated: 2022/03/15 15:16:42 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

t_lexer	*new_lexer(const char *input)
{
	t_lexer	*lexer;

	lexer = (t_lexer *)ft_xmalloc(sizeof(t_lexer));
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
