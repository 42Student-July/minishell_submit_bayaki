/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/16 10:17:38 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "self_cmd.h"

void	check_option(t_list *args, bool *display_return)
{
	size_t	i;
	char	*str;

	while (args != NULL)
	{
		str = args->content;
		if (str == NULL || str[0] != '-')
			break ;
		i = 1;
		while (str[i])
		{
			if (ft_strchr("n", str[i]) == NULL)
				break ;
			i++;
		}
		if (str[1] == '\0' || str[i] != '\0')
			break ;
		i = 1;
		while (str[i] != '\0')
		{
			if (str[i] == 'n')
				*display_return = true;
			i++;
		}
		args = args->next;
	}
}

int	exec_self_echo(t_cmd *cmd, t_exec_attr *ea)
{
	t_list	*args;
	char	*str;
	bool	display_return;

	args = cmd->args->next;
	(void)ea;
	display_return = false;
	check_option(args, &display_return);
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
