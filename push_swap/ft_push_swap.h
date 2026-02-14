/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:56:28 by msuter            #+#    #+#             */
/*   Updated: 2026/02/14 15:26:33 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"
# include <limits.h>

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
int		srch_min_in_a(int *tab_a, int size_a);
void	start_rot(int *tab, int *size, int value);
void	start_rot_for_b(int *tab_b, int *size_b, int index);
void	who_push(int *tab_a, int *size_a, int *tab_b, int *size_b);
int		srch_max_in_a(int *tab_a, int size_a);
int		find_target_index(int *tab_a, int size_a, int value);
int		verif_double(int *tab_a, int size_a);
int		free_all(int *tab_a, int *tab_b);
int		min_max(long res);
int		valid_number(int argc, char **argv);
long	ft_atol(const char *str);
void	sort_stack(int *tab_a, int *tab_b, int *size_a, int *size_b);
void	reorganise_order_tab_a(int *tab_a, int size_a);

#endif