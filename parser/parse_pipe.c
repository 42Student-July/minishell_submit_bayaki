/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:45:50 by akito             #+#    #+#             */
/*   Updated: 2022/03/15 15:27:11 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "lexer.h"
#include "libft.h"
#include "parser.h"

static t_list	*parse_pipe_helper(t_list *token_list, t_list **heredocs);

t_list	*parse_pipe(t_list *token_list, t_list **heredocs)
{
	t_list	*result;

	result = parse_pipe_helper(token_list, heredocs);
	if (result == NULL)
		return (NULL);
	return (result);
}

static t_list	*invalid_cmd(void)
{
	t_cmd	*cmd;

	cmd = cmd_init();
	cmd->is_invalid_syntax = true;
	return (ft_xlstnew(cmd));
}

static t_list	*parse_pipe_helper(t_list *token_list, t_list **heredocs)
{
	t_list	*left_tokens;
	t_list	*right_tokens;
	t_token	*token;
	t_list	*lst;

	left_tokens = token_list;
	if (((t_token *)left_tokens->content)->type == TOKEN_EOF)
		return (invalid_cmd());
	while (token_list != NULL)
	{
		token = token_list->content;
		if (token->type == TOKEN_EOF)
			break ;
		if (token->type == TOKEN_PIPE)
		{
			right_tokens = token_list->next;
			lst = parse_pipe_helper(right_tokens, heredocs);
			if (((t_token *)right_tokens->content)->type == TOKEN_EOF)
				((t_cmd *)lst->content)->is_invalid_syntax = true;
			ft_lstadd_front(&lst, ft_xlstnew(parse_cmd(left_tokens, heredocs)));
			return (lst);
		}
		token_list = token_list->next;
	}
	return (ft_xlstnew(parse_cmd(left_tokens, heredocs)));
}
