/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:17:09 by msuter            #+#    #+#             */
/*   Updated: 2025/10/01 17:18:03 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	if (*s == '\0')
		return ((char *)s);
	while (*s)
		s++;
	while (*s >= 0)
	{
		if (*s == a)
		{
			return ((char *)s);
		}
		s--;
	}
	return (NULL);
}
