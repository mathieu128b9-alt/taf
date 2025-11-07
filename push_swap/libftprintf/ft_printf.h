/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:42:59 by msuter            #+#    #+#             */
/*   Updated: 2025/11/04 17:27:51 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr_base(unsigned long nb);
int		modif_putnbr(unsigned long n);
int		ft_putnbr_base_maj(unsigned long nb);
int		ft_printf(const char *format, ...);
int		case_percent(va_list *li, const char *fmt, size_t *i, int *count);
#endif
