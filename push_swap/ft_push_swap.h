/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:56:28 by msuter            #+#    #+#             */
/*   Updated: 2025/11/07 22:24:32 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP
#define FT_PUSH_SWAP

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"

void	convert_to_int(int argc, char **argv, int *tab_a);
int		count_tab(int *tab);
void	reatribute(int *tab, int *tab_temp, int *size, int start);
void	malloc_and_verif(int *tab, int size);
void	swap_a(int *tab_a, int *size_a);
void	swap_b(int *tab_b, int *size_b);
void	swap_both(int *tab_a, int *tab_b, int *size_a, int *size_b);

#endif