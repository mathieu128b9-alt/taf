/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:55:11 by msuter            #+#    #+#             */
/*   Updated: 2025/10/19 18:23:36 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	d_c_p_i(va_list *li, const char *frmt, size_t *i, int *count)
{
	int		result;
	char	*printable;
	char	res;

	if (frmt[*i + 1] == 'd' || frmt[*i + 1] == 'i')
	{
		result = va_arg(*li, int);
		printable = ft_itoa(result);
		*count += ft_putstr(printable);
	}
	else if (frmt[*i + 1] == 'c')
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

	if (frmt[*i + 1] == 's')
	{
		res = va_arg(*li, char *);
		*count += ft_putstr(res);
	}
	else if (frmt[*i + 1] == 'p')
	{
		result = va_arg(*li, void *);
		if (result == NULL)
		{
			write (1, "(nil)", 5);
			*count += 5;
			return ;
		}
		write (1, "0x", 2);
		*count += ft_putnbr_base((unsigned long)result) + 2;
	}
}

static void	u_xmaj_x(va_list *li, const char *frmt, size_t *i, int *count)
{
	unsigned int	res;
	unsigned int	result;

	if (frmt[*i + 1] == 'u')
	{
		res = va_arg(*li, unsigned int);
		*count += modif_putnbr(res);
	}
	else if (frmt[*i + 1] == 'x')
	{
		result = va_arg(*li, unsigned int);
		*count += ft_putnbr_base(result);
	}
	else if (frmt[*i + 1] == 'X')
	{
		result = va_arg(*li, unsigned int);
		*count += ft_putnbr_base_maj(result);
	}
}

static void	case_percent(va_list *li, const char *format, size_t *i, int *count)
{
	if (format[*i] == '%')
	{
		if (format[*i + 1] == 'd' || format[*i + 1] == 'c'
			|| format[*i + 1] == '%' || format[*i + 1] == 'i')
			d_c_p_i(li, format, i, count);
		else if (format[*i + 1] == 's' || format[*i + 1] == 'p')
			s_p(li, format, i, count);
		else if (format[*i + 1] == 'u' || format[*i + 1] == 'x'
			|| format[*i + 1] == 'X')
			u_xmaj_x(li, format, i, count);
		*i += 2;
	}
	else
	{
		ft_putchar(format[*i]);
		(*count)++;
		(*i)++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	li;
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	va_start(li, format);
	while (format[i] != '\0')
	{
		case_percent(&li, format, &i, &count);
	}
	va_end(li);
	return (count);
}

/*#include <stdio.h>
int main (void)
{
	int i = -1;
	ft_printf(" %p\n ", &i);
	printf(" %p ", &i);
}*/