/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:54:06 by msuter            #+#    #+#             */
/*   Updated: 2026/03/01 14:47:11 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	testing(t_token *token)
{
	int	i;

	i = 0;
	while (token[i].type != TOKEN_END)
	{
		printf("%s\n", token[i].content);
		printf("%d\n", token[i].type);
		i++;
	}
}

int	main(void)
{
	t_token	*token;
	char	*imput;
	int		verif_nb;

	while (1)
	{
		imput = readline("minishell>");
		verif_nb = how_many_tokens(imput);
		printf("TEST how_many_tokens retourne: %d\n", verif_nb);
		if (!imput)
			case_error(imput, NULL, "erreur lors du malloc du imput", verif_nb);
		token = lexing(imput, verif_nb);
		testing(token);
		if (token == NULL)
		{
			case_continue(imput, token, "erreur, il manque une quote");
			continue ;
		}
		if (ft_strncmp(token[0].content, "exit", 5) == 0)
			end_prog(imput, token, verif_nb);
		free_token(imput, token, verif_nb);
	}
}
