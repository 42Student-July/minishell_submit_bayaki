/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ident_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:45:50 by akito             #+#    #+#             */
/*   Updated: 2022/03/15 15:24:39 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

void	process_in_quote(t_lexer *lexer)
{
	char	c;

	c = lexer->ch;
	read_char(lexer);
	while (lexer->ch != c)
	{
		if (lexer->ch == '\0')
		{
			if (!join_new_line(lexer))
				exit(EXIT_FAILURE);
		}
		read_char(lexer);
	}
}

t_token	*new_ident_token(t_lexer *lexer)
{
	char	*ident;
	t_token	*token;
	size_t	pos;

	pos = lexer->position;
	while (!is_metachar(lexer->ch) && lexer->ch != '\0')
	{
		if (lexer->ch == '"' || lexer->ch == '\'')
			process_in_quote(lexer);
		read_char(lexer);
	}
	ident = ft_xsubstr(lexer->input, pos, lexer->position - pos);
	token = new_token(TOKEN_IDENT, ident);
	free(ident);
	ident = NULL;
	return (token);
}
