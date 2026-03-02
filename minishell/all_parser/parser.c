/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:19:27 by msuter            #+#    #+#             */
/*   Updated: 2026/03/02 19:52:28 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	arg_after_cmd(t_token *token, t_parser *parser, int *nb)
{
	int	temp;
	int	count;

	count = 0;
	temp = *nb;
	while (token[temp].type == TOKEN_WORD)
	{
		temp++;
		count++;
	}
	parser->arg = malloc(sizeof(char *) * (count + 2));
	if (!parser->arg)
		return ;
	count = 0;
	parser->arg[count] = ft_strdup(parser->cmd);
	count++;
	while(*nb != temp)
	{
		parser->arg[count] = ft_strdup(token[*nb].content);
		count++;
		(*nb)++;
	}
	parser->arg[count] = NULL;
}

void	cmd_or_file(t_token *token, t_parser *parser, int *nb)
{
	if (*nb == 0)
	{
		parser->cmd = ft_strdup(token[*nb].content);
		(*nb)++;
		arg_after_cmd(token, parser, nb);
	}
	else if (*nb - 1 >= 0)
	{
		if (is_redirect(token, ((*nb) - 1)) == 0)
		{
			parser->cmd = ft_strdup(token[*nb].content);
			(*nb)++;
			arg_after_cmd(token, parser, nb);
		}
	}
}

t_parser	*create_parser(t_token *token)
{
	int			nb;
	t_parser	*parser;
	t_parser	*current;

	parser = new_node();
	current = parser;
	nb = 0;
	while (token[nb].type != TOKEN_END)
	{
		if (token[nb].type == TOKEN_WORD)
			cmd_or_file(token, current, &nb);
		else if (is_redirect(token, &nb) == 1)
		{
			
		}
	}
}