/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:30:30 by msuter            #+#    #+#             */
/*   Updated: 2026/02/18 17:33:05 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

void	after_space(char *imput, int *count, int *i, int *flag)
{
	if (imput[*i + 1] == '\0' || is_space(imput[*i + 1]) == 1)
		(*i)++;
	else if (imput[*i + 1] == '|' || imput[*i + 1] == '>' || imput[*i + 1] == '<')
		(*i)++;
	else
	{
		*flag = 0;
		(*i)++;
	}
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
		if (flag == 0)
			count++;
		flag = 1;
		if (is_space(imput[i]) == 1)
		{
			after_space(imput, &count, &i, &flag);
			continue;
		}
		if (imput[i] == '|' || imput[i] == '<' || imput[i] == '>')
			flag = 0;
		if ((imput[i - 1] == '|' || imput[i - 1] == '<' || imput[i - 1] == '>') && is_space(imput[i]) != 1)
			flag = 0;
		i++;
	}
	return (count + 1);
}


int main(void)
{
	int test = how_many_tokens(" test | aaa");
	printf("%d\n", test);
}

/*
	ok, la logique marche plutot pas mal, mtn faut ajouter les quotes, juste une boucle qui avance tant que on
	a pas trouve la fin de quote, les single et double
*/

		