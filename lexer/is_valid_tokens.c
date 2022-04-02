/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:45:50 by akito             #+#    #+#             */
/*   Updated: 2022/04/02 16:49:46 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	is_valid_tokens(t_list *token_list)
{
	t_list	*prev;

	prev = NULL;
	while (token_list != NULL)
	{
		if (((t_token *)token_list->content)->type == TOKEN_ILLEGAL)
			return (false);
		if (prev != NULL && ((t_token *)prev->content)->type == TOKEN_HEREDOC
			&& ((t_token *)token_list->content)->type != TOKEN_IDENT)
			return (false);
		prev = token_list;
		token_list = token_list->next;
	}
	return (true);
}
