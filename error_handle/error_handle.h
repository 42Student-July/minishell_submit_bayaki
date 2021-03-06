/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:54 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/16 14:47:26 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLE_H
# define ERROR_HANDLE_H

# include <errno.h>
# include <stdio.h>
# include <unistd.h>

# include "execute_struct.h"

# define MALLOC_ERROR "malloc failed\n"
# define FORK_ERROR "fork error\n"
# define WAIT_ERROR "wait error\n"
# define INVALID_IDENTIFER_MSG "not an identifier\n"
# define OPENDIR_ERROR "opendir error\n"
# define OPEN_ERROR "open error\n"
# define GETCWD_ERROR "getcwd error"

# define INVALID_IDENTIFER 0
# define NO_VALUE 1

// error_handle.c
void		free_exec_attr(t_exec_attr *ea);
void		free_char_dptr(char **split);
void		abort_minishell(char *msg, t_exec_attr *ea);
void		abort_minishell_with(char *msg, t_exec_attr *ea, char **split);
void		free_lst(t_list *lst);

// error_handle_2.c
void		free_all_kvs(t_kvs *kvs);

// debug.c
void		print_command_debug(t_exec_attr *ea);
void		print_array(char **array);

// print_cmd.c
void		print_files(char *name, t_list *list);
void		print_lists(char *name, t_list *list);
void		print_cmd(const t_cmd *cmd);
void		print_cmds(t_list *cmd);

#endif
