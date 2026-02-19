/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:07:14 by msuter            #+#    #+#             */
/*   Updated: 2026/02/19 22:57:16 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	case_single_quote(char *imput, t_token *token, int *i, int *size_word)
{
	int temp;

	temp = *i + 1;
	while (imput[temp] && imput[temp] != '\'')
	{
		*size_word++;
		temp++;
		if (imput[temp] == '\'')
		{
			(*size_word)++;
			return (0);
		}
	}
	return (-1);
}

int	case_double_quote(char *imput, t_token *token, int *i, int *size_word)
{
	int temp;

	temp = *i + 1;
	while (imput[temp] && imput[temp] != '\"')
	{
		*size_word++;
		temp++;
		if (imput[temp] == '\"')
		{
			(*size_word)++;
			return (0);
		}
	}
	return (-1);
}

void	case_word(char *imput, t_token *token, int *i, int *size_word)
{
	if (imput[*i] == '\'')
	{
		*size_word++;
		if (case_single_quote(imput, token, i, size_word) == 0)
			return (0);
	}
	if (imput[*i] == '\"')
	{
		*size_word++;
		if (case_double_quote(imput, token, i, size_word) == 0)
			return (0);
	}
	return (-1);
}
