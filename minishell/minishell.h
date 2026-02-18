/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 10:54:35 by msuter            #+#    #+#             */
/*   Updated: 2026/02/18 16:13:46 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/types.h>
# include <dirent.h>
# include <string.h>
# include <sys/ioctl.h>
# include "libft/libft.h"

typedef enum e_redir
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC,
}	e_redir;

typedef enum e_token
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_APPEND,
	TOKEN_REDIR_HEREDOC,
	TOKEN_END,
}	e_token;

typedef	struct t_token
{
	e_token	type;
	char	*content;
}	t_token;

typedef struct t_redir
{
	int		type;
	char	*file;
}	t_redir;

// typedef struct t_cmd
// {
// 	char	**commande;
// 	t_redir	redirection;
// 	int		nb_redirection;
// 	t_cmd	*next;
// }	t_cmd;
void	lexing(char **lex);

#endif