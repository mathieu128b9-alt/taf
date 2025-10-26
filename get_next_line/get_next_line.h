/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:58:37 by msuter            #+#    #+#             */
/*   Updated: 2025/10/26 14:34:35 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
#include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct c_list
{
	void			*content;
	struct c_list	*next;
}					t_list;

char	*get_next_line(int fd);
t_list	*ft_new_node(void *content);
void	add_node(t_list **lst, t_list *new);
int		find_backslash(char *str);
char	*ft_strdup_before(const char *s1);

#endif