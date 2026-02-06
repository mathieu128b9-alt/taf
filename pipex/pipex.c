/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:22:10 by msuter            #+#    #+#             */
/*   Updated: 2026/02/06 13:49:19 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	first_prog(t_global *gl, char **argv, char **envp)
{
	gl->fd_in = open(argv[1], O_RDONLY);
	if (gl->fd_in == -1)
	{
		perror("erreur d'ouverture du fichier 1");
		exit(1);
	}
	dup2(gl->fd_in, STDIN_FILENO);
	dup2(gl->pipe_fd[1], STDOUT_FILENO);
	close(gl->pipe_fd[0]);
	close(gl->fd_in);
	close(gl->pipe_fd[1]);
	search_path(envp, argv[2], gl);
	execve(gl->final, gl->cmd, envp);
	perror("execve failed");
	free_all(gl);
	exit(1);
	return (0);
}

int	sec_prog(t_global *gl, char **argv, char **envp)
{
	gl->fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(gl->pipe_fd[0], STDIN_FILENO);
	dup2(gl->fd_out, STDOUT_FILENO);
	close(gl->pipe_fd[1]);
	close(gl->fd_out);
	close(gl->pipe_fd[0]);
	search_path(envp, argv[3], gl);
	execve(gl->final, gl->cmd, envp);
	perror("execve failed");
	free_all(gl);
	exit(1);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_global	gl;

	create_all(&gl, argc);
	gl.pid1 = fork();
	if (gl.pid1 == -1)
		return (error_message("erreur lord du fork 1"));
	if (gl.pid1 == 0)
		first_prog(&gl, argv, envp);
	gl.pid2 = fork();
	if (gl.pid2 == -1)
		return (error_message("erreur lord du fork 2"));
	if (gl.pid2 == 0)
		sec_prog(&gl, argv, envp);
	close(gl.pipe_fd[0]);
	close(gl.pipe_fd[1]);
	wait(NULL);
	wait(NULL);
	return (0);
}
