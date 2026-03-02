/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 10:54:35 by msuter            #+#    #+#             */
/*   Updated: 2026/03/02 10:37:53 by msuter           ###   ########.fr       */
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

typedef enum e_token
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_IN,
	TOKEN_OUT,
	TOKEN_APPEND,
	TOKEN_HEREDOC,
	TOKEN_END,
}	t_enum_token;

typedef struct t_token
{
	t_enum_token	type;
	char			*content;
}	t_token;

typedef struct t_contexte
{
	int	i;
	int	size_word;
	int	nb;
}	t_contexte;

typedef enum t_enum_redir
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC,
}	t_enum_redir;

typedef struct t_redir
{
	int		type;
	char	*file;
	t_redir	*r_next;
}	t_redir;

typedef struct t_parser
{
	char		*cmd;
	char		**arg;
	t_redir		*redir;
	t_parser	*next;
}	t_parser;

int		is_space(char c);
int		how_many_tokens(char *imput);
void	case_error(char *imput, t_token *token,
			char *message_erroor, int nb_token);
int		case_word(char *imput, t_contexte *c);
t_token	*lexing(char *imput, int verif_nb);
void	case_in_or_heredoc(char *imput, t_contexte *c, t_token *token);
void	case_out_or_happend(char *imput, t_contexte *c, t_token *token);
void	case_continue(char *imput, t_token *token, char *message_erroor);
void	end_prog(char *imput, t_token *token, int nb_token);
void	free_token(char *imput, t_token *token, int nb_token);

#endif