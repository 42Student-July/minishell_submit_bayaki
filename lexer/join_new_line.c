/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_new_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:45:50 by akito             #+#    #+#             */
/*   Updated: 2022/03/15 15:23:14 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "lexer.h"
#include "libft.h"
#include <readline/readline.h>
#include <stdbool.h>

bool	join_new_line(t_lexer *lexer)
{
	char	*line;
	char	*tmp;

	tmp = ft_xstrjoin(lexer->input, "\n");
	free(lexer->input);
	lexer->input = tmp;
	line = readline("> ");
	if (line == NULL)
		return (false);
	tmp = ft_xstrjoin(lexer->input, line);
	free(lexer->input);
	free(line);
	lexer->input = tmp;
	return (true);
}
