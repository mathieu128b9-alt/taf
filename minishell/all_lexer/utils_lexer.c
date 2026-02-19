/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 21:06:52 by msuter            #+#    #+#             */
/*   Updated: 2026/02/19 10:10:27 by msuter           ###   ########.fr       */
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

void	case_error(char *imput, t_token *token, char *message_erroor)
{
	free(imput);
	free(token);
	printf("%s\n", message_erroor);
	exit(1);
}
