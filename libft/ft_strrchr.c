/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:17:09 by msuter            #+#    #+#             */
/*   Updated: 2025/10/13 16:36:40 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	a;
	int				i;

	a = (unsigned char)c;
	if (!s)
		return (NULL);
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == a)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
