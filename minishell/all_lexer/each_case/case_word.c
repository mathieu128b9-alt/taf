/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:07:14 by msuter            #+#    #+#             */
/*   Updated: 2026/02/20 02:54:26 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	case_single_quote(char *imput, int *i, int *size_word)
{
	int temp;

	temp = *i + *size_word;
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

int	case_double_quote(char *imput, int *i, int *size_word)
{
	int temp;

	temp = *i + *size_word;
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

int	case_no_quotes(char *imput, int *i, int *size_word)
{
	int	temp;

	temp = *i + *size_word;
	while(imput[temp] && imput[temp] != ' ' && imput[temp] != '|'
		&& imput[temp] != '<' && imput[temp] != '>')
	{
		*size_word++;
		temp++;
	}
	return (0);
}

int	case_word(char *imput, int *i, int *size_word)
{
	int	temp;

	temp = *i + *size_word;
	if (imput[temp] == '\'')
	{
		*size_word++;
		if (case_single_quote(imput, i, size_word) == 0)
			return (0);
	}
	else if (imput[temp] == '\"')
	{
		*size_word++;
		if (case_double_quote(imput, i, size_word) == 0)
			return (0);
	}
	else
	{
		case_no_quotes(imput, i, size_word);
		return (0);
	}
	return (-1);
}
