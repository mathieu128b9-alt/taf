/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:19:27 by msuter            #+#    #+#             */
/*   Updated: 2026/03/14 18:05:14 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_redir	*which_type(t_token *token, t_parser *current, int *nb)
{
	if (token[*nb].type == TOKEN_IN)
		current->redir->type = REDIR_IN;
	else if (token[*nb].type == TOKEN_OUT)
		current->redir->type = REDIR_OUT;
	else if (token[*nb].type == TOKEN_APPEND)
		current->redir->type = REDIR_APPEND;
	else
		current->redir->type = REDIR_HEREDOC;
	(*nb)++;
	current->redir->file = ft_strdup(token->content);
	(*nb)++;
}

void	arg_after_cmd(t_token *token, t_parser *current, int *nb)
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
	current->arg = malloc(sizeof(char *) * (count + 2));
	if (!current->arg)
		return ;
	count = 0;
	current->arg[count] = ft_strdup(current->cmd);
	count++;
	while(*nb != temp)
	{
		current->arg[count] = ft_strdup(token[*nb].content);
		count++;
		(*nb)++;
	}
	current->arg[count] = NULL;
}

void	cmd_or_file(t_token *token, t_parser *current, int *nb)
{
	if (*nb == 0)
	{
		current->cmd = ft_strdup(token[*nb].content);
		(*nb)++;
		arg_after_cmd(token, current, nb);
	}
	else if (*nb - 1 >= 0)
	{
		if (is_redirect(token, ((*nb) - 1)) == 0)
		{
			current->cmd = ft_strdup(token[*nb].content);
			(*nb)++;
			arg_after_cmd(token, current, nb);
		}
	}
}

t_parser	*create_parser(t_token *token)
{
	int			nb;
	t_parser	*parser;
	t_parser	*current;
	t_redir		*current_redir;

	parser = new_node();
	current = parser;
	
	nb = 0;
	while (token[nb].type != TOKEN_END)
	{
		if (token[nb].type == TOKEN_WORD)
			cmd_or_file(token, current, &nb);
		else if (is_redirect(token, &nb) == 1)
		{
			if (current->redir == NULL)
			{
				parser->redir = which_type(token, current, &nb);
				parser->redir->r_next = current->redir;
			}
			else
			{
				current_redir = which_type(token, current, &nb);
			}
		}
	}
}