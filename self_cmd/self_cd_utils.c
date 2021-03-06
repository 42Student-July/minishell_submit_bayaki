/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_cd_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 08:58:27 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/16 20:53:42 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "self_cmd.h"

char	*create_pwd(t_list *pwdlst, t_exec_attr *ea)
{
	char	*pwd;

	if (pwdlst == NULL)
		pwd = ft_xstrdup("");
	else
	{
		if (ft_strlen(ft_kvsget_value(pwdlst->content)) == 0)
			pwd = ft_xstrdup("");
		else
			pwd = ft_xstrdup(ea->current_pwd);
	}
	return (pwd);
}

void	update_all_environ(char *new_pwd, t_exec_attr *ea)
{
	char	*export_new_pwd;
	char	*export_pwd;
	char	*pwd;
	t_list	*pwdlst;

	pwdlst = get_lst_by_key(ea->env_lst, "PWD");
	pwd = create_pwd(pwdlst, ea);
	free(ea->current_pwd);
	ea->current_pwd = ft_xstrdup(new_pwd);
	export_pwd = create_export_value(pwd);
	if (pwdlst != NULL)
	{
		export_new_pwd = create_export_value(new_pwd);
		update_value(ea->env_lst, "PWD", new_pwd);
		update_value(ea->export_lst, "PWD", export_new_pwd);
		free(export_new_pwd);
	}
	update_value(ea->env_lst, "OLDPWD", pwd);
	update_value(ea->export_lst, "OLDPWD", export_pwd);
	free(pwd);
	free(export_pwd);
}

char	*concat_new_pwd(char *pwd, char *path)
{
	char	*new_value;
	size_t	new_value_len;
	size_t	path_len;
	size_t	pwd_len;

	pwd_len = ft_strlen(pwd);
	path_len = ft_strlen(path);
	if (pwd[pwd_len - 1] == '/')
		new_value_len = (pwd_len + path_len + NULL_CHAR);
	else
		new_value_len = (pwd_len + SLASH + path_len + NULL_CHAR);
	new_value = (char *)ft_xcalloc(sizeof(char), new_value_len);
	ft_strlcat(new_value, pwd, new_value_len);
	if (pwd[pwd_len - 1] != '/')
		ft_strlcat(new_value, "/", new_value_len);
	ft_strlcat(new_value, path, new_value_len);
	return (new_value);
}

bool	is_end_of_slash(char *path)
{
	size_t	i;

	i = 0;
	if (ft_strlen(path) == 1)
		return (false);
	while (path[i] != '\0')
		i++;
	if (path[i - 1] == '/')
		return (true);
	return (false);
}
