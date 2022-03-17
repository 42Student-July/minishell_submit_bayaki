/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:45:50 by akito             #+#    #+#             */
/*   Updated: 2022/03/17 17:15:22 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include <stdio.h>

t_token	*token_dup(t_token *token)
{
	t_token	*token_new;

	token_new = (t_token *)ft_xcalloc(sizeof(t_token), 1);
	if (token_new == NULL)
		exit(EXIT_FAILURE);
	token_new->type = token->type;
	token_new->literal = ft_xstrdup(token->literal);
	return (token_new);
}
