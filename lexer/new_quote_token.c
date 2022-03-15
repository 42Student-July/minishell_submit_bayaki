/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_quote_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:45:50 by akito             #+#    #+#             */
/*   Updated: 2022/03/15 15:24:47 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

t_token	*new_quote_token(t_lexer *lexer, t_tokentype type)
{
	char			*quote;
	t_token			*token;
	const size_t	pos = lexer->position;

	read_char(lexer);
	while (lexer->ch != type)
	{
		if (lexer->ch == '\0')
			if (!join_new_line(lexer))
				exit(EXIT_FAILURE);
		read_char(lexer);
	}
	quote = ft_xsubstr(lexer->input, pos + 1, lexer->position - pos - 1);
	token = new_token(type, quote);
	free(quote);
	quote = NULL;
	lexer->skip_whitespace = false;
	return (token);
}
