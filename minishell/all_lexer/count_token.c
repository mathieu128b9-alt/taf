/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:30:30 by msuter            #+#    #+#             */
/*   Updated: 2026/02/19 22:59:27 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	quotes(char *imput, int *i, int *flag)
{
	if (imput[*i] == '"')
	{
		(*i)++;
		while (imput[*i] && imput[*i] != '"')
			(*i)++;
		if (imput[*i] == '"')
		{
			*flag = 0;
			(*i)++;
			return (0);
		}
		printf("erreur, il manque une double quote");
		return (-1);
	}
}

static int	single_quotes(char *imput, int *i, int *flag)
{
	if (imput[*i] == '\'')
	{
		(*i)++;
		while (imput[*i] && imput[*i] != '\'')
			(*i)++;
		if (imput[*i] == '\'')
		{
			*flag = 0;
			(*i)++;
			return (0);
		}
		printf("erreur, il manque une double quote");
		return (-1);
	}
}

static void	after_space(char *imput, int *i, int *flag)
{
	if (imput[*i + 1] == '\0' || is_space(imput[*i + 1]) == 1)
		(*i)++;
	else if (imput[*i + 1] == '|'
		|| imput[*i + 1] == '>' || imput[*i + 1] == '<')
		(*i)++;
	else
	{
		*flag = 0;
		(*i)++;
	}
}

static int	mid_function(char *imput, int *count, int *i, int *flag)
{
	if (single_quotes(imput, i, flag) == -1 || quotes(imput, i, flag) == -1)
		return (-1);
	if (*flag == 0)
		(*count)++;
	*flag = 1;
	if (is_space(imput[*i]) == 1)
	{
		after_space(imput, i, flag);
		return (2);
	}
	if (((imput[*i - 1] == '|' || imput[*i - 1] == '<'
				|| imput[*i - 1] == '>') && is_space(imput[*i]) != 1)
		|| (imput[*i] == '|' || imput[*i] == '<' || imput[*i] == '>'))
		*flag = 0;
	return (0);
}

int	how_many_tokens(char *imput)
{
	int	i;
	int	count;
	int	flag;

	count = 0;
	i = 0;
	flag = 1;
	while (is_space(imput[i]) == 1)
		i++;
	while (imput[i])
	{
		if (mid_function(imput, &count, &i, &flag) == -1)
			return (-1);
		else if (mid_function(imput, &count, &i, &flag) == 2)
			continue ;
		i++;
	}
	return (count + 1);
}
//j'ai mis return -1 pask on peux avoir le cas d'un token et faut que ca fonctionne,
//donc mon -1 sert de retour d'erreur dans ma fonction principale