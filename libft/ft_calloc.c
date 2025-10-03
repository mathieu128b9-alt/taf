/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 03:25:51 by mathieu           #+#    #+#             */
/*   Updated: 2025/10/03 03:31:23 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;
	size_t	i;

	i = 0;
	tab = malloc(count * size);
	if (!tab)
		return (NULL);
	while (i < count * size)
	{
		((unsigned char *)tab)[i] = 0;
		i++;
	}
	return (tab);
}
