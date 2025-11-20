/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:56:28 by msuter            #+#    #+#             */
/*   Updated: 2025/11/20 16:08:10 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"

void	swap_a(int *tab_a, int *size_a);
void	swap_b(int *tab_b, int *size_b);
void	swap_both(int *tab_a, int *tab_b, int *size_a, int *size_b);
void	push_b(int *tab_a, int *size_a, int *tab_b, int *size_b);
void	push_a(int *tab_a, int *size_a, int *tab_b, int *size_b);
void	rotate_a(int *tab_a, int *size_a);
void	rotate_b(int *tab_b, int *size_b);
void	rotate_both(int *tab_a, int *tab_b, int size_a, int size_b);
void	reverse_rotate_b(int *tab_b, int *size_b);
void	rotate_reverse_a(int *tab_a, int *size_a);
void	rev_rot_both(int *tab_a, int *tab_b, int *size_a, int *size_b);
void	replace_to_indice(int *tab_a, int *size_a);
int		new_lis(int *tab_a, int size_a, int **lis);
void	is_in_lis(int *tab_a, int *size_a, int *tab_b, int *size_b);

#endif

//gcc -Wall -Wextra -Werror -I. -Ilibftprintf -Ilibftprintf/libft *.c utils/*.c libftprintf/libftprintf.a -o push_swap