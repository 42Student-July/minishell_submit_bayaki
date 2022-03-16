/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigaction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:55:08 by akito             #+#    #+#             */
/*   Updated: 2022/03/16 15:55:09 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sigaction.h"

// debug function
void	print_exit_status_in_signal(void)
{
	if (g_exit_status == 0)
		printf("%d ", g_exit_status);
	else
		printf("%d ", g_exit_status);
}
