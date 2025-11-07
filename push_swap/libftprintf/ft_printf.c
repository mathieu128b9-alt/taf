/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:55:11 by msuter            #+#    #+#             */
/*   Updated: 2025/11/04 17:35:07 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	d_c_p_i(va_list *li, const char *frmt, size_t *i, int *count)
{
	int		result;
	char	*printable;
	char	res;

	if (frmt[*i] == 'd' || frmt[*i] == 'i')
	{
		result = va_arg(*li, int);
		printable = ft_itoa(result);
		*count += ft_putstr(printable);
		free(printable);
	}
	else if (frmt[*i] == 'c')
	{
		res = va_arg(*li, int);
		*count += ft_putchar(res);
	}
	else
		*count += ft_putchar('%');
}

static void	s_p(va_list *li, const char *frmt, size_t *i, int *count)
{
	char	*res;
	void	*result;

	if (frmt[*i] == 's')
	{
		res = va_arg(*li, char *);
		*count += ft_putstr(res);
	}
	else if (frmt[*i] == 'p')
	{
		result = va_arg(*li, void *);
		if (result == NULL)
		{
			write(1, "(nil)", 5);
			*count += 5;
			return ;
		}
		write(1, "0x", 2);
		*count += ft_putnbr_base((unsigned long)result) + 2;
	}
}

static void	u_xmaj_x(va_list *li, const char *frmt, size_t *i, int *count)
{
	unsigned int	res;
	unsigned int	result;

	if (frmt[*i] == 'u')
	{
		res = va_arg(*li, unsigned int);
		*count += modif_putnbr(res);
	}
	else if (frmt[*i] == 'x')
	{
		result = va_arg(*li, unsigned int);
		*count += ft_putnbr_base(result);
	}
	else if (frmt[*i] == 'X')
	{
		result = va_arg(*li, unsigned int);
		*count += ft_putnbr_base_maj(result);
	}
}

/* fusion end + '%%' + dispatch après '%' */
static void	percent_flow(va_list *li, const char *fmt, size_t *i, int *count)
{
	if (fmt[*i + 1] == '\0')
	{
		(*i)++;
		return ;
	}
	if (fmt[*i + 1] == '%')
	{
		*count += ft_putchar('%');
		*i += 2;
		return ;
	}
	(*i)++;
	if (fmt[*i] == 'd' || fmt[*i] == 'c' || fmt[*i] == 'i' || fmt[*i] == '%')
		d_c_p_i(li, fmt, i, count);
	else if (fmt[*i] == 's' || fmt[*i] == 'p')
		s_p(li, fmt, i, count);
	else if (fmt[*i] == 'u' || fmt[*i] == 'x' || fmt[*i] == 'X')
		u_xmaj_x(li, fmt, i, count);
	(*i)++;
}

int	case_percent(va_list *li, const char *fmt, size_t *i, int *count)
{
	if (fmt[*i] != '%')
	{
		ft_putchar(fmt[*i]);
		(*count)++;
		(*i)++;
		return (1);
	}
	percent_flow(li, fmt, i, count);
	return (1);
}
