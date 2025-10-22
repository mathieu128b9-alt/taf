/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:57:50 by msuter            #+#    #+#             */
/*   Updated: 2025/10/22 17:57:10 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	**get_next_line(int fd)
{
	int			count;
	static char	*tab;
	char		buffer[BUFFER_SIZE];
	
	count = 0;
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		
	}
}

int main (void)
{
	int fd = open("test.txt", O_RDWR);
	get_next_line(fd);
	
}

//gcc *.c -Wall -Werror -Wextra -D BUFFER_SIZE=1