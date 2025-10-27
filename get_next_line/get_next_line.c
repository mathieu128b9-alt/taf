/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:57:50 by msuter            #+#    #+#             */
/*   Updated: 2025/10/27 13:48:00 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static char	*fill_stash(int fd, char *stash)
{
	char	*buffer;
	int		nb;
	char	*temp;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	nb = 1;
	while (nb > 0)
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		if (nb < 0)
		{
			free (buffer);
			free (stash);
			return (NULL);
		}
		else if (nb == 0)
			break ;
		else
		{
			temp = stash;
			stash = (ft_strjoin(stash, buffer));
			free(temp);
			if (ft_strchr(stash, '\n') != NULL)
				break;
		}
	}
	free (buffer);
	return (stash);
}

static char *create_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	while (stash)
	{
		if (stash[i] == '\n')
		{
			break ;
		}
		i++;
	}
	line = ft_substr(stash, 0, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	//char		*temp;

	if (BUFFER_SIZE <= 0 || fd == -1)
	{
		if (stash)
			free(stash);
		return (NULL);
	}
	stash = fill_stash(fd, stash);
	line = create_line(stash);
	return (line);
}

/*int main (void)
{
	int fd = open("test", O_RDWR);
	get_next_line(fd);
}*/
//valgrind