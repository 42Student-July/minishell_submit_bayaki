/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:45:50 by akito             #+#    #+#             */
/*   Updated: 2022/03/18 16:11:08 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include "sigaction.h"
#include <fcntl.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

void	replace_quoted_str(char **buffer, t_list *env_list)
{
	char	*tmp;

	tmp = expand_envvar_str(*buffer, env_list);
	free(*buffer);
	*buffer = tmp;
}

void
	read_heredoc_in_child_process( \
		t_lexer *lexer, t_list *env_list, bool has_quote, char *delimiter)
{
	char	*line;
	char	*buffer;

	buffer = NULL;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	line = readline("");
	while (line != NULL)
	{
		if (ft_strncmp(line, delimiter, ft_strlen(line)) == 0
			&& ft_strlen(line) == ft_strlen(delimiter))
		{
			free(line);
			line = NULL;
			break ;
		}
		join_line_to_buffer(&buffer, &line);
		line = readline("");
	}
	if (!has_quote)
		replace_quoted_str(&buffer, env_list);
	write_heredocs(lexer, buffer, delimiter);
	exit(EXIT_SUCCESS);
}

bool	is_heredoc_succeeded(pid_t	pid)
{
	pid_t	wait_ret;
	int		wstatus;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	while (true)
	{
		wait_ret = waitpid(pid, &wstatus, 0);
		if (wait_ret < 0)
		{
			return (false);
		}
		if (WIFSIGNALED(wstatus))
		{
			printf("\n");
			g_exit_status = WEXITSTATUS(wstatus);
			return (false);
		}
		if (wait_ret > 0)
			break ;
		exit(EXIT_FAILURE);
	}
	set_signal_handler_during_command();
	return (true);
}

bool
	read_heredoc_process( \
		t_lexer *lexer, t_list *env_list, bool has_quote, char *delimiter)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		printf("fork error\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		read_heredoc_in_child_process(lexer, env_list, has_quote, delimiter);
	else
	{
		if (!is_heredoc_succeeded(pid))
		{
			{
				delete_lexer(lexer);
				free(delimiter);
				return (false);
			}
		}
	}
	return (true);
}

bool	read_heredoc(t_lexer *lexer, t_list *env_list)
{
	char	*tmp;
	t_list	*heredoc_delimiter;
	char	*delimiter;
	bool	has_quote;

	heredoc_delimiter = ft_my_lstpop_front(&lexer->io_here_delimiters);
	delimiter = ft_xstrdup(heredoc_delimiter->content);
	ft_lstdelone(heredoc_delimiter, free);
	has_quote = ft_strchr(delimiter, '\'') != NULL || ft_strchr(delimiter,
			'"') != NULL;
	if (has_quote)
	{
		tmp = expand_quote_str(delimiter);
		free(delimiter);
		delimiter = tmp;
	}
	register_heredocs(lexer, delimiter);
	if (!read_heredoc_process(lexer, env_list, has_quote, delimiter))
		return (false);
	free(delimiter);
	return (true);
}
