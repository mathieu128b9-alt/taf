/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   each_case_for_lexing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:07:14 by msuter            #+#    #+#             */
/*   Updated: 2026/02/19 14:53:43 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	case_single_quote(char *imput, t_token *token, int *i, int *nb)
{
	int	temp;
	int	size_word;

	temp = *i + 1;
	size_word = 1;
	while (imput[temp] && imput[temp] != '\'')
	{
		size_word++;
		temp++;
		if (imput[temp] == '\'')
		{
			(token[*nb]).content = malloc(sizeof(char) * size_word + 2);
			if (!(token[*nb]).content)
				case_error(imput, token, "erreur lors du malloc d'un token");
			ft_strlcpy((token[*nb].content), imput + *i, size_word + 2);
			(*i) = (*i) + size_word + 1;
			return ((*nb)++);
		}
	}
	return (1);
}

int	case_double_quote(char *imput, t_token *token, int *i, int *nb)
{
	int	temp;
	int	size_word;

	temp = *i + 1;
	size_word = 1;
	while (imput[temp] && imput[temp] != '\"')
	{
		size_word++;
		temp++;
		if (imput[temp] == '\"')
		{
			(token[*nb]).content = malloc(sizeof(char) * size_word + 2);
			if (!(token[*nb]).content)
				case_error(imput, token, "erreur lors du malloc d'un token");
			ft_strlcpy((token[*nb].content), imput + *i, size_word + 2);
			(*i) = (*i) + size_word + 1;
			return ((*nb)++);
		}
	}
	return (1);
}

void	case_word(char *imput, t_token *token, int *i, int *nb)
{
	if (imput[*i] == '\'')
	{
		case_single_quote(imput, token, i, nb);
	}
	if (imput[*i] == '\"')
	{
		
	}
	while (imput[*i] && imput[*i] != ' ')
	{
		
	}
	printf("erreur, il manque une quote");
	exit(1);
}

/* 
	manque a gerer les cas ou je trouve jamais de deuxieme quote,
	le cas ou ya du texte colle a ma deuxieme qute(pris en compte)
*/