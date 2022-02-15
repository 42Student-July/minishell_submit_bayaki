/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigaction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:18:41 by tkirihar          #+#    #+#             */
/*   Updated: 2022/02/13 01:23:55 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sigaction.h"

int g_exit_status = 0;

void interactive_sigint(int sig)
{
	(void)sig;
	printf("\n");
	rl_replace_line("", 0); // プロンプトのバッファをクリア
	rl_on_new_line();       // プロンプトを次の行に移動したいことを伝える？
	rl_redisplay();         // プロンプトを再描画
}

void	dfl_sigint(int sig)
{
	(void)sig;
	g_exit_status = 1;
}

void	dfl_sigquit(int sig)
{
	(void)sig;
	printf("Quit: 3\n");
}