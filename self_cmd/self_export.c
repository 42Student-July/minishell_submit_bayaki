#include "self_cmd.h"

int	exec_self_export(t_cmd *cmd, t_exec_attr *ea)
{
	const char	*argv_one = get_argv_one(cmd);
	bool		exit_stat;
	const bool	is_sharp = (argv_one != NULL && argv_one[0] == '#');

	exit_stat = true;
	// exportの第一引数が#から始まっている限り、なにが後ろにきたとしても、export(引数なし)と同じような実装になる。
	if (argv_one == NULL || is_sharp)
		print_all_export_lst(ea);
	else
		export_with_args(cmd, ea, &exit_stat);
	if (exit_stat)
		return (0);
	return (1);
}

int	check_export_arg(char **arg)
{
	// ちょっと全部は把握しきれていないが、KEYに_以外の記号がはいったらout
	if (is_invalid_name(arg[KEY]))
		return (INVALID_IDENTIFER);
	if (arg[VALUE] == NULL)
		return (NO_VALUE);
	return (10);
}

void	export_with_assign(t_exec_attr *ea, bool *exit_stat, char *arg)
{
	char	**kv;
	int		ret;

	kv = ft_separate(arg, '=');
	if (kv == NULL)
		abort_minishell(MALLOC_ERROR, ea);
	ret = check_export_arg(kv);
	if (ret == INVALID_IDENTIFER)
	{
		*exit_stat = false;
		print_error_msg_with_var(EXPORT, kv[KEY]);
	}
	else
	{
		// valueがnullだけど=が存在する場合、valueには\0を入れる。
		if (ret == NO_VALUE)
			kv[VALUE] = ft_xstrdup("");
		if (!store_arg_in_env(ea, kv[KEY], kv[VALUE]))
			abort_minishell_with(MALLOC_ERROR, ea, kv);
		if (!store_arg_in_export(ea, kv[KEY], kv[VALUE]))
			abort_minishell_with(MALLOC_ERROR, ea, kv);
	}
	free(kv[0]);
	free(kv[1]);
	free(kv);
}

void	export_with_args_single(t_exec_attr *ea, char *arg, bool *exit_stat)
{
	const bool	exists_equal = ft_strchr(arg, '=') != NULL;
	const bool	is_started_with_equal = ft_strchr(arg, '=') == arg;

	// ft_splitでは引数が"a="の場合と"a"の判別がつけられない実装になっている
	// そのため、strchrでまず引数に=があるか判定してから、各実装に入る
	// 先頭ポインタが"="だったとき、keyが存在しないのでerrorとする
	if ((!exists_equal && is_invalid_name(arg)) || is_started_with_equal)
	{
		print_error_msg_with_var(EXPORT, arg);
		*exit_stat = false;
	}
	else if (!exists_equal)
	{
		store_arg_in_export(ea, arg, NULL);
		store_arg_in_env(ea, arg, NULL);
	}
	else
		export_with_assign(ea, exit_stat, arg);
}

void	export_with_args(t_cmd *cmd, t_exec_attr *ea, bool *exit_stat)
{
	t_list	*lst;
	char	*arg;

	lst = cmd->args->next;
	while (lst != NULL)
	{
		arg = (char *)(lst->content);
		export_with_args_single(ea, arg, exit_stat);
		lst = lst->next;
	}
}
