/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:57:50 by msuter            #+#    #+#             */
/*   Updated: 2025/10/27 11:27:28 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dest, const char *src1, const char *src2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src1[i])
	{
		dest[i] = src1[i];
		i ++;
	}
	while (src2[j])
	{
		dest[i + j] = src2[j];
		j++;
	}
	dest[i + j] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	size_t	i;

	i = ft_strlen(s1) + ft_strlen(s2);
	final = malloc((i + 1) * sizeof(char));
	if (!final)
		return (NULL);
	ft_strcpy(final, s1, s2);
	return (final);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static t_list	*ligne;
	int				nb_bytes;
	int				i;
	char 			*temp;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
			return (NULL);
	while ((nb_bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		i = 0;
		buffer[nb_bytes] = '\0';
		temp = ft_strdup_before(buffer);
		add_node(&ligne, ft_new_node(temp));
		if ((i = find_backslash(buffer)) != 0)
		{
			i++;
			temp = ft_strdup_before(buffer + i);
			add_node(&ligne, ft_new_node(temp + i));
		}
	}
	if (nb_bytes < 0)
	{
		free(buffer);
		return (NULL);
	}
	else if (nb_bytes == 0)
	{
		if ((char *)ligne == NULL ||(char *)ligne->content == NULL)
			return (NULL);
	}
}
int main (void)
{
	int fd = open("test.txt", O_RDWR);
	get_next_line(fd);
	
}
//gcc *.c -Wall -Werror -Wextra -D BUFFER_SIZE=1