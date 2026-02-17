/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:02:49 by msuter            #+#    #+#             */
/*   Updated: 2026/02/17 11:30:01 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	which_case(char *imput)
{
	
}

void	lexing(char **lex)
{
	char	*imput;
	int		i;

	i = 0;
	imput = readline("minishell>");
	if (!imput)
	{
		free(imput);
		printf("erreur lors du malloc (lexing)");
		exit(1);
	}
	while (imput[i])
	{
		
	}
	free(imput);
}