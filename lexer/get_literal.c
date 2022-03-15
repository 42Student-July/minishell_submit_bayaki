/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_literal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:45:50 by akito             #+#    #+#             */
/*   Updated: 2022/03/15 15:16:29 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "lexer.h"
#include "libft.h"

char	*get_literal(t_token *token)
{
	if (is_word_token(token->type))
		return (ft_xstrdup(token->literal));
	else
		exit(EXIT_FAILURE);
	return (NULL);
}
