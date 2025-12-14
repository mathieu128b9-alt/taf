/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:22:10 by msuter            #+#    #+#             */
/*   Updated: 2025/12/14 18:25:37 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	create_all(t_global *gl, int argc)
{
	if (argc != 5)
	{
		ft_printf("le nombre d'arguments est incorrect");
		exit(1);
	}
	if (pipe(gl->pipe_fd) == -1)
	{
		ft_printf("erreur lord de la creation du pipe");
		exit(1);
	}
	return (0);
}

int	error_message(char *error_type)
{
	ft_printf("%s", error_type);
	return (1);
}

int first_prog(t_global *gl, char **argv)
{
	gl->fd_in = open(argv[1], O_RDONLY);
	if (gl->fd_in == -1)
	{
		perror("erreur d'ouverture du fichier 1");
		exit(1);
	}
	dup2(gl->pipe_fd[1], STDOUT_FILENO);
}

int main(int argc, char **argv)
{
	t_global gl;

	create_all(&gl, argc);
	gl.pid1 = fork();
	if (gl.pid1 == -1)
		return (error_message("erreur lord du fork 1"));
	if (gl.pid1 == 0)
		first_prog(&gl, *argv);
}