/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:19:27 by msuter            #+#    #+#             */
/*   Updated: 2026/03/02 11:35:38 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	arg_after_cmd(t_token *token, t_parser *parser, int *nb)
{
	
}

void	cmd_or_file(t_token *token, t_parser *parser, int *nb)
{
	if (*nb == 0)
	{
		parser->cmd = ft_strdup(token[*nb].content);
		(*nb)++;
	}
	else if (*nb - 1 >= 0)
	{
		if (is_redirect(token, (nb - 1)) == 0)
		{
			parser->cmd = ft_strdup(token[*nb].content);
			(*nb)++;
		}
	}
}

t_parser	*create_parser(t_token *token)
{
	int			nb;
	t_parser	*parser;

	nb = 0;
	while (token[nb].type != TOKEN_END)
	{
		
	}
}