/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:57:50 by msuter            #+#    #+#             */
/*   Updated: 2025/10/25 19:48:58 by msuter           ###   ########.fr       */
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
	t_list			*node;
	static t_list	*ligne;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		if (!buffer)
			return (NULL);
		buffer[BUFFER_SIZE] = '\0';
		node = ft_new_node(buffer);
		add_node(&ligne, node);
	}
}
/*int main (void)
{
	int fd = open("test.txt", O_RDWR);
	get_next_line(fd);
	
}*/
//gcc *.c -Wall -Werror -Wextra -D BUFFER_SIZE=1