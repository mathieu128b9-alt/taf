/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:30:30 by msuter            #+#    #+#             */
/*   Updated: 2026/02/24 14:28:09 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	case_d_quote(char *imput, t_contexte *c)
{
	c->i++;
	while (imput[c->i] && imput[c->i] != '\"')
		c->i++;
	if (imput[c->i] == '\"')
	{
		c->i++;
		while (imput[c->i] && !is_space(imput[c->i]) 
			&& imput[c->i] != '|' && imput[c->i] != '<' && imput[c->i] != '>')
			c->i++;
		return (0);
	}
	return (-1);
}

int	case_quote(char *imput, t_contexte *c)
{
	c->i++;
	while (imput[c->i] && imput[c->i] != '\'')
		c->i++;
	if (imput[c->i] == '\'')
	{
		c->i++;
		while (imput[c->i] && !is_space(imput[c->i]) 
			&& imput[c->i] != '|' && imput[c->i] != '<' && imput[c->i] != '>')
			c->i++;
		return (0);
	}
	return (-1);
}

int	how_many_tokens(char *imput)
{
	t_contexte	c;

	c.i = 0;
	c.nb = 0;
	while(imput[c.i])
	{
		while (is_space(imput[c.i]) == 1)
			c.i++;
		if (imput[c.i] == '\0')
			break ;
		if (imput[c.i] == '\'')
		{
			if (case_quote(imput, &c) == -1)
				return (-1);
		}
		else if (imput[c.i] == '\"')
		{
			if (case_d_quote(imput, &c) == -1)
				return (-1);
		}
		else if (imput[c.i] == '|' || imput[c.i] == '<' || imput[c.i] == '>')
			c.i++;
		else
			while (imput[c.i] && !is_space(imput[c.i]) 
			&& imput[c.i] != '|' && imput[c.i] != '<' && imput[c.i] != '>')
				c.i++;
		c.nb++;
	}
	return(c.nb);
}
