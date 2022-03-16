/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:15:04 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/16 17:16:01 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <stdio.h>
typedef enum e_stdio {
	STDIN = 0,
	STDOUT = 1,
	STDERR = 2
}						t_stdio;

extern int	g_exit_status;

#endif
