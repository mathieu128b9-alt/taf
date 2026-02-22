/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:54:06 by msuter            #+#    #+#             */
/*   Updated: 2026/02/22 01:15:31 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int main(void)
{
	t_token *token;
	char *imput;

	imput = readline("minishell>");
	if (!imput)
		case_error(imput, NULL, "erreur lors du malloc du imput");
	token = lexing(imput);

	int i = 0;
	while (token[i].type != TOKEN_END)
	{
		printf("%d\n", token[i].type);
		i++;
	}
}