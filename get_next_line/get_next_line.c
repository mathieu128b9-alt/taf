/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:57:50 by msuter            #+#    #+#             */
/*   Updated: 2025/10/26 14:49:08 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

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
		buffer[nb_bytes] = '\0';
		if ((i = find_backslash) != -1)
		{
			temp = ft_strdup_before(buffer);
		}
		
	}
	if (nb_bytes < 0)
	{
		free(buffer);
		return (NULL);
	}
	else if (nb_bytes == 0)
	{
		if ((char *)ligne->content == NULL)
			return (ligne);
		else
		{
			
		}
	}
}
/*int main (void)
{
	int fd = open("test.txt", O_RDWR);
	get_next_line(fd);
	
}*/
//gcc *.c -Wall -Werror -Wextra -D BUFFER_SIZE=1