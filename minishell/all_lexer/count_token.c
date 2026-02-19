/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:30:30 by msuter            #+#    #+#             */
/*   Updated: 2026/02/19 09:37:38 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	quotes(char *imput, int *i, int *flag)
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
			return ;
		}
		printf("erreur, il manque une double quote");
		exit(1);
	}
}

static void	single_quotes(char *imput, int *i, int *flag)
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
			return ;
		}
		printf("erreur, il manque une double quote");
		exit(1);
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
	single_quotes(imput, i, flag);
	quotes(imput, i, flag);
	if (*flag == 0)
		(*count)++;
	*flag = 1;
	if (is_space(imput[*i]) == 1)
	{
		after_space(imput, i, flag);
		return (1);
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
		if (mid_function(imput, &count, &i, &flag) == 1)
			continue ;
		i++;
	}
	return (count + 1);
}
