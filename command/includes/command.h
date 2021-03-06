/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/18 16:03:54 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include <sys/types.h>
# include <errno.h>
# include <fcntl.h>
# include <pthread.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h>
# include <sys/wait.h>
# include <dirent.h>

# include "libft.h"
# include "color.h"
# include "execute_struct.h"
# include "environ.h"
# include "self_cmd.h"
# include "error_handle.h"
# include "common.h"

# define MY_COMMAND_NUM 4
# define CMD_NAME 0
# define CMD_ARG 1
# define EQUAL 1
# define LF 1
# define PIPE_IN 0
# define PIPE_OUT 1
# define SLASH 1
# define IN 0
# define OUT 1
# define NO_PIPE 0
# define PIPE 1

// execute.c
int			execute_cmd(t_exec_attr *ea);
void		print_cmdv(char **cmdv);

// execute_self.c
bool		is_self_cmd(char *cmd);
void		execute_self_cmd(t_cmd	*c, t_exec_attr *ea, bool is_pipe);
void		create_cmd_from_arg(int argc, const char *argv[], t_exec_attr *ea);
void		exec_in_child_process(t_exec_attr *ea);
bool		exec_in_main_process(t_exec_attr *ea);

// execute_builtin.c
char		**convert_envlst_to_array(t_exec_attr *ea);
char		*create_env_line(char *key, char *value, bool is_end);
char		*create_env_line_non_value(char *key, bool is_end);

// create_cmd.c
bool		is_dollar(char *arg);
char		*convert_env_var(t_exec_attr *ea, char *arg);
char		*concat_path_and_cmd(char *path, char *command);
void		create_cmd_from_arg(int argc, const char **argv, t_exec_attr *ea);
char		*find_path(char *cmd_name, t_exec_attr *ea, size_t cmd_i);

// init.c
void		init(t_exec_attr **ea);
void		init_new(t_exec_attr **ea);

// convert_lst_to_argv.c
char		**convert_lst_to_argv(t_list *args);

// no_pipe_process.c
void		no_pipe_process(t_exec_attr *ea);
void		execute_ext_cmd(t_cmd *c, t_exec_attr *ea, char *cmd_path);
bool		is_path(char *cmd);

// pipe_process.c
void		pipe_process(t_exec_attr *ea, int pipe_count);

// free_pipe_attr.c
void		free_pipe_attr(t_pipe_attr *pa);

// cmd_utils.c
bool		is_dir(char *cmd_path);
bool		*malloc_has_not_permission(size_t size);
bool		is_path(char *cmd);
char		*create_cmd_path(t_cmd *c, t_exec_attr *ea);
// execve_error.c
void		execve_error(int cp_errno, char *cmd_path);
void		exit_with_err_msg(char *cmd, char *msg, int exit_status);

// create_cmd_utils.c
char		*create_cmd(char *path, char *command, DIR *dirp);
char		*concat_path_and_cmd(char *path, char *command);
bool		is_invalid_permission(\
	char *path, char *command, size_t cmd_i, t_exec_attr *ea);

// redirect_utils.c
void		redirect_dev_null(t_exec_attr *ea);
bool		open_files_in(t_cmd *cmd);
bool		open_files_out(t_cmd *cmd);
void		change_fd(t_list *files, bool is_in);

// pipe_process_utils.c
void		malloc_pipe_fd(t_pipe_attr *pa);
void		malloc_cpid_array(t_pipe_attr *pa);
void		make_pipe(t_pipe_attr *pa);
void		set_pipe_fd(t_pipe_attr *pa);
void		close_pipe(t_pipe_attr *pa);

#endif
