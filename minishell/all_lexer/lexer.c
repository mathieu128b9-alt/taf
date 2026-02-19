/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:02:49 by msuter            #+#    #+#             */
/*   Updated: 2026/02/19 14:08:07 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	which_case(char *imput, t_token *token, int *i, int *nb)
{
	if (imput[*i] == '|')
		case_pipe();
	else if (imput[*i] == '>')
		case_in_or_happend();
	else if (imput[*i] == '<')
		case_out_or_heredoc();
	else
		case_word(imput, token, i, nb);
}

void	lexing(t_token *token)
{
	char	*imput;
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	imput = readline("minishell>");
	if (!imput)
		case_error(imput, NULL, "erreur lors du malloc du imput");
	token = malloc(sizeof(t_token) * how_many_tokens(imput));
	if(!token)
		case_error(imput, token, "erreur lors du malloc du token");
	while (imput[i])
	{
		which_case(imput, token, &i, &nb);
	}
	free(imput);
}

/* 
! alors, la le but ca va etre de faire en sorte que je puisse faire le compte de mon mot,
! pour ca j'ai cree une variable count_word, et je fais pas avancer mon i reel, pour pas
! perdre le debut de mon mot, quans j'ai trouve, je dois malloc, et copier le mot,
! en cas de soucis on retourne une erreur, il manque forcement une quote, pask j'ai secur
! le reste avec des return

*/