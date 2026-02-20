/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:54:06 by msuter            #+#    #+#             */
/*   Updated: 2026/02/20 01:45:58 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
	t_token *token;
	char *imput;

	imput = readline("minishell>");
	if (!imput)
		case_error(imput, NULL, "erreur lors du malloc du imput");
	token = lexing(&token, imput);
}