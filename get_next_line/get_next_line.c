/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:57:50 by msuter            #+#    #+#             */
/*   Updated: 2025/11/10 19:57:22 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*after_backslash(char *stash)
{
	int		i;
	char	*new;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
	{
		i++;
		new = ft_substr(stash, i, ft_strlen(stash) - i);
		free(stash);
		if (!new || new[0] == '\0')
		{
			free(new);
			return (NULL);
		}
		return (new);
	}
	free(stash);
	return (NULL);
}

static char	*free_and_return(char *buf, char *stash)
{
	free(buf);
	free(stash);
	return (NULL);
}

static char	*fill_stash(int fd, char *stash)
{
	char	*buf;
	char	*tmp;
	int		nb;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free_and_return(buf, stash));
	nb = 1;
	while (nb > 0)
	{
		nb = read(fd, buf, BUFFER_SIZE);
		if (nb <= 0)
			break ;
		buf[nb] = '\0';
		tmp = stash;
		stash = ft_strjoin(stash, buf);
		free(tmp);
		if (!stash || ft_strchr(buf, '\n'))
			break ;
	}
	if (nb < 0)
		return (free_and_return(buf, stash));
	free(buf);
	return (stash);
}

static char	*create_line(char *stash)
{
	int		i;
	char	*line;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr(stash, 0, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd == -1)
	{
		if (stash)
			free(stash);
		return (NULL);
	}
	stash = fill_stash(fd, stash);
	line = create_line(stash);
	stash = after_backslash(stash);
	return (line);
}

//#include "stdio.h"
//int main(void)
//{
//	int fd = open("get_next_line.c", O_RDONLY);
//	char *res;

//	while ((res = get_next_line(fd)) != NULL)
//	{
//	printf("%s", res);
//		free(res);
//	}
//	close(fd);
//}