/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:29:27 by msuter            #+#    #+#             */
/*   Updated: 2025/10/06 16:17:06 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	mot(const char *chaine, char c)
{
	size_t	i;
	size_t	nbmot;

	if (!chaine)
		return (0);
	i = 0;
	nbmot = 0;
	while (chaine[i])
	{
		while (chaine[i] == c)
			i++;
		if (!chaine[i])
			break ;
		nbmot++;
		while (chaine[i] && chaine[i] != c)
			i++;
	}
	return (nbmot);
}

char	*assign(const char *s, char **final, char c, size_t i)
{
	size_t	len;
	size_t	start;
	size_t	j;

	j = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		len = i - start;
		final[j] = malloc(sizeof(char) * (len + 1));
		if (!final[j])
			return (NULL);
		ft_strlcpy(final[j], s + start, (len + 1));
		j++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**final;
	size_t	i;
	size_t	nb_mot;

	i = 0;
	nb_mot = mot(s, c);
	final = malloc(sizeof(char *) * (mot(s, c) + 1));
	if (!final)
		return (NULL);
	assign(s, final, c, i);
	if (s[i] == '\0')
	{
		final[nb_mot] = malloc(sizeof(char) * 1);
		final[nb_mot] = NULL;
	}
	return (final);
}
