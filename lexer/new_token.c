/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:45:50 by akito             #+#    #+#             */
/*   Updated: 2022/03/15 15:16:33 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include <stdio.h>

t_token	*new_token(t_tokentype type, char *literal)
{
	t_token	*token;

	token = (t_token *)ft_xmalloc(sizeof(t_token));
	if (token == NULL)
		exit(EXIT_FAILURE);
	token->type = type;
	token->literal = ft_xstrdup(literal);
	return (token);
}
