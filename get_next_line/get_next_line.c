/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:57:50 by msuter            #+#    #+#             */
/*   Updated: 2025/10/24 09:46:50 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	*buffer;
	read(fd, buffer, BUFFER_SIZE);
	if (!ft_new_node(buffer))
		return (NULL);
	
}
/*int main (void)
{
	int fd = open("test.txt", O_RDWR);
	get_next_line(fd);
	
}*/
//gcc *.c -Wall -Werror -Wextra -D BUFFER_SIZE=1