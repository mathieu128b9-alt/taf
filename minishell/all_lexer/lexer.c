/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:02:49 by msuter            #+#    #+#             */
/*   Updated: 2026/02/22 01:10:45 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	which_case(char *imput, t_contexte *c, t_token *token)
{
	int	verif_quote;

	verif_quote = 0;
	if (imput[c->i] == '|')
	{
		token[c->nb].type = TOKEN_PIPE;
		token[c->nb].content = NULL;
		c->nb++;
		c->i++;
	}
	else if (imput[c->i] == '>')
		 case_out_or_happend(imput ,c, token);
	else if (imput[c->i] == '<')
		case_in_or_heredoc(imput ,c, token);
	else
		verif_quote = case_word(imput, c);
	return (verif_quote);
}

t_token	*lexing(char *imput)
{
	t_contexte	c;
	t_token *token;

	c.nb = 0;
	c.i = 0;
	c.size_word = 0;
	token = malloc(sizeof(t_token) * how_many_tokens(imput) + 1);
	if(!token)
		case_error(imput, token, "erreur lors du malloc du token");
	while (imput[c.i])
	{
		while (is_space(imput[c.i]))
			c.i++;
		which_case(imput, &c, token);
		if (imput[c.i + c.size_word] == '\0' || imput[c.i + c.size_word] == ' ' || imput[c.i + c.size_word] == '|'
			|| imput[c.i + c.size_word] == '<' || imput[c.i + c.size_word] == '>')
		{
			token[c.nb].content = malloc(sizeof(char) * c.size_word + 1);
			ft_strlcpy(token[c.nb].content, imput + c.i, c.size_word + 1);
			token[c.nb].type = TOKEN_WORD;
			c.nb++;
			c.i += c.size_word;
			c.size_word = 0;
		}
	}
	token[c.nb].type = TOKEN_END;
	free(imput);
	return (token);
}
