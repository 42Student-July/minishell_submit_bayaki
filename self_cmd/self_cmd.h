/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_cmd.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/16 16:54:15 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELF_CMD_H
# define SELF_CMD_H

# include <errno.h>
# include <limits.h>
# include <sys/stat.h>

# include "libft.h"
# include "error_handle.h"
# include "environ.h"
# include "execute_struct.h"
# include "common.h"

# define CD "cd"
# define ECHO "echo"
# define PWD "pwd"
# define EXIT "exit"
# define ENV "env"
# define EXPORT "export"
# define UNSET "unset"
# define CMD_ARG 1
# define SLASH 1

// self_pwd.c
int			exec_self_pwd(t_cmd *cmd, t_exec_attr *ea);

// self_cd.c
int			exec_self_cd(t_cmd *cmd, t_exec_attr *ea);
char		*concat_new_pwd(char *pwd, char *path);
bool		is_symlink(char *path, t_exec_attr *ea);
bool		is_end_of_slash(char *path);

// self_cd_utils.c
void		update_all_environ(char *new_pwd, t_exec_attr *ea);

// self_cd_utils_2.c
bool		has_diff(char *path, t_exec_attr *ea);
char		*remove_relative(char *path);

// self_cd_utils_3.c
char		*create_str_removed_end(char *path);
size_t		count_rm_rel_path(char **split);
bool		is_relative_exist(char *split_path);
void		process_ddot(char *path, char **sp_rm_rel, size_t *j);

// self_echo.c
int			exec_self_echo(t_cmd *cmd, t_exec_attr *ea);

// self_exit.c
int			exec_self_exit(t_cmd *cmd, bool is_pipe);

// self_env.c
int			exec_self_env(t_cmd *cmd, t_exec_attr *ea);
void		print_all_env_lst(t_exec_attr *ea);
void		print_env_kvs(void *content);

// self_unset.c
int			exec_self_unset(t_cmd *cmd, t_exec_attr *ea);

// self_export.c
int			exec_self_export(t_cmd *cmd, t_exec_attr *ea);
void		store_arg_only_export(t_exec_attr *ea, char *key);
int			check_export_arg(char **arg);
void		export_with_args(t_cmd *cmd, t_exec_attr *ea, bool *exit_stat);
bool		addlst_sort_by_ascii(t_list **export_lst, char **arg);

// self_export_utils.c
void		print_export_kvs(void *content);
void		sort_listkey_by_ascii(t_list *export_lst);
void		print_all_export_lst(t_exec_attr *ea);
void		export_print_err(char *arg, bool *exit_stat);
bool		is_sharp(char *arg);

// self_cmd_utils.c
bool		is_invalid_name(char *name);
void		print_error_msg_with_var(char *cmd_name, char *var);
int			print_error(char *cmd, char *input);
bool		has_caps(char *path);

#endif
