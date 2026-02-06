/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:36:29 by msuter            #+#    #+#             */
/*   Updated: 2026/02/06 12:32:31 by msuter           ###   ########.fr       */
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

void	search_path(char **envp, char *exec, t_global *gl)
{
	int i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break;
		i++;
	}
	gl->path = ft_split(envp[i] + 5, ':');
	gl->cmd = ft_split(exec, ' ');
	i = 0;
	while (gl->path[i] != NULL)
	{
		gl->test = ft_strjoin(gl->path[i], "/");
		gl->final = ft_strjoin(gl->test, gl->cmd[0]);
		free(gl->test);
		if (access(gl->final, X_OK) == 0)
			return(free_all(gl));
		free(gl->final);
		i++;
	}
	printf("erreur, le chemin d'acces n'est pas valide");
	exit(1);
}

void	free_all(t_global *gl)
{
	int	i;

	i = 0;
	//free(gl->final);
	while (gl->cmd[i])
	{
		free(gl->cmd[i]);
		i++;
	}
	free(gl->cmd);
	i = 0;
	while(gl->path[i])
	{
		free(gl->path[i]);
		i++;
	}
	free(gl->path);
	return ;
}