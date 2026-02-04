/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:56:04 by msuter            #+#    #+#             */
/*   Updated: 2026/01/26 15:22:37 by msuter           ###   ########.fr       */
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
	char	**path;
	char	**cmd;
	char	*test;
	char	*final;

}	t_global;

int		create_all(t_global *gl, int argc);
int		error_message(char *error_type);
void	search_path(char **envp, char *exec, t_global *gl);
void	free_all(t_global *gl);

#endif