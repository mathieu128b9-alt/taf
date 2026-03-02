/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:12:01 by msuter            #+#    #+#             */
/*   Updated: 2026/03/02 19:06:49 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_parser	*new_node(void)
{
	t_parser *parser;

	parser = malloc(sizeof(t_parser));
	if (!parser)
		return (NULL);
	parser = ft_memset(parser, 0, sizeof(t_parser));
	return (parser);
}

int	is_redirect(t_token *token, int	*nb)
{
	if (token[*nb].type == TOKEN_IN || token[*nb].type == TOKEN_OUT
		|| token[*nb].type == TOKEN_APPEND || token[*nb].type == TOKEN_HEREDOC)
		return (1);
	return (0);
}