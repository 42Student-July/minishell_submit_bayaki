/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/18 15:42:57 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "self_cmd.h"
#include <stdbool.h>

bool	is_n_option(char *str)
{
	int	i;

	if (str == NULL || str[0] != '-')
		return (false);
	i = 1;
	while (str[i])
	{
		if (ft_strchr("n", str[i]) == NULL)
			return (false);
		i++;
	}
	if (str[1] == '\0' || str[i] != '\0')
		return (false);
	return (true);
}

bool	check_n_option(t_list *args)
{
	size_t	i;
	bool	display_return;
	char	*str;

	display_return = false;
	while (args != NULL)
	{
		str = args->content;
		if (!is_n_option(str))
			break ;
		i = 1;
		while (str[i] != '\0')
		{
			if (str[i] == 'n')
				display_return = true;
			i++;
		}
		args = args->next;
	}
	return (display_return);
}

int	exec_self_echo(t_cmd *cmd, t_exec_attr *ea)
{
	t_list	*args;
	char	*str;
	bool	display_return;

	str = NULL;
	args = cmd->args->next;
	(void)ea;
	display_return = check_n_option(args);
	while (args != NULL && is_n_option(args->content))
		args = args->next;
	while (args != NULL)
	{
		str = args->content;
		if (str == NULL)
			break ;
		args = args->next;
		ft_putstr_fd(str, STDOUT_FILENO);
		if (args != NULL)
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
	if (!display_return)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}
