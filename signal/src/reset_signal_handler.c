/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_signal_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:55:14 by akito             #+#    #+#             */
/*   Updated: 2022/03/16 15:55:15 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sigaction.h"

static void	set_sigint_handler_default(void)
{
	signal(SIGINT, SIG_DFL);
}

static void	set_sigquit_handler_default(void)
{
	signal(SIGQUIT, SIG_DFL);
}

void	reset_signal_handler(void)
{
	set_sigint_handler_default();
	set_sigquit_handler_default();
}
