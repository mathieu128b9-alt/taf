/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:56:28 by msuter            #+#    #+#             */
/*   Updated: 2025/11/15 16:44:11 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP
#define FT_PUSH_SWAP

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"

void	convert_to_int(int argc, char **argv, int *tab_a);
void	swap_a(int *tab_a, int *size_a);
void	swap_b(int *tab_b, int *size_b);
void	swap_both(int *tab_a, int *tab_b, int *size_a, int *size_b);
void	push_b(int *tab_a, int *tab_b, int *size_a, int *size_b);
void	push_a(int *tab_a, int *tab_b, int *size_a, int *size_b);
void	rotate_a(int *tab_a, int *size_a);
void	rotate_b(int *tab_b, int *size_b);
void	rotate_both(int *tab_a, int *tab_b, int size_a, int size_b);
void	reverse_rotate_b(int *tab_b, int *size_b);
void	rotate_reverse_a(int *tab_a, int *size_a);
void	rev_rot_both(int *tab_a, int *tab_b, int *size_a, int *size_b);
void	replace_to_indice(int *tab_a, int *size_a);

#endif