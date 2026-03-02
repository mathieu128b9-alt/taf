/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_chained.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:37:10 by msuter            #+#    #+#             */
/*   Updated: 2026/03/02 19:39:16 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_redir	*new_node(void)
{
	t_redir *redir;

	redir = malloc(sizeof(t_parser));
	if (!redir)
		return (NULL);
	redir = ft_memset(redir, 0, sizeof(t_parser));
	return (redir);
}