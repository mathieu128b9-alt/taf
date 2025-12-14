/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:56:04 by msuter            #+#    #+#             */
/*   Updated: 2025/12/14 18:24:42 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <wait.h>
# include <stdio.h>

typedef struct t_global
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		fd_in;
	int		fd_out;

}	t_global;

#endif