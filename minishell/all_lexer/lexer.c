/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:02:49 by msuter            #+#    #+#             */
/*   Updated: 2026/02/20 03:11:37 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	which_case(char *imput, int *i, int *size_word)
{
	if (imput[*i] == '|')
		case_pipe();
	else if (imput[*i] == '>')
		case_in_or_happend();
	else if (imput[*i] == '<')
		case_out_or_heredoc();
	else
		case_word(imput, i, size_word);
}

t_token	*lexing(char *imput)
{
	int		size_word;
	t_token *token;
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	token = malloc(sizeof(t_token) * how_many_tokens(imput));
	if(!token)
		case_error(imput, token, "erreur lors du malloc du token");
	while (imput[i])
	{
		while (is_space(imput[i]))
			i++;
		which_case(imput, &i, &size_word);
		if (imput[i + size_word] == '\0' || imput[i + size_word] == ' ' || imput[i + size_word] == '|'
			|| imput[i + size_word] == '<' || imput[i + size_word] == '>')
		{
			token[nb].content = malloc(sizeof(char) * size_word + 1);
			ft_strlcpy(token[nb].content, imput + i, size_word + 1);
			nb++;
			i += size_word;
			size_word = 0;
		}
	}
	free(imput);
	return (token);
}
