/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_cmd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/16 13:55:43 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "self_cmd.h"

bool	is_invalid_name(char *name)
{
	size_t	i;

	i = 0;
	if (ft_isdigit(name[i]))
		return (true);
	while (name[i] != '\0')
	{
		if (!(ft_isalnum(name[i]) || name[i] == '_'))
			return (true);
		i++;
	}
	return (false);
}

void	print_error_msg_with_var(char *cmd_name, char *var)
{
	ft_putstr_fd("bash: ", STDERR_FILENO);
	ft_putstr_fd(cmd_name, STDERR_FILENO);
	ft_putstr_fd(": `", STDERR_FILENO);
	ft_putstr_fd(var, STDERR_FILENO);
	ft_putstr_fd("': ", STDERR_FILENO);
	ft_putstr_fd(INVALID_IDENTIFER_MSG, STDERR_FILENO);
}

int	print_error(char *cmd, char *input)
{
	ft_putstr_fd("bash: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	perror(input);
	return (EXIT_FAILURE);
}

bool	has_caps(char *path)
{
	size_t	i;

	i = 0;
	while (path[i] != '\0')
	{
		if (ft_iscap_alpha(path[i]))
		{
			return (true);
		}
		i++;
	}
	return (false);
}
