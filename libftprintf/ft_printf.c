/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:55:11 by msuter            #+#    #+#             */
/*   Updated: 2025/10/17 16:46:41 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void decimal_char_percent_integer(va_list li, const char *frmt, size_t *i) {
	if (frmt[*i + 1] == 'd' || frmt[*i + 1] == 'i')
	{
		int res;
		char *printable;

		res = va_arg(li, int);
		printable = ft_itoa(res);
		ft_putstr(printable);
		(*i)++;
	}
	else if (frmt[*i + 1] == 'c') 
	{
		char res;

		res = va_arg(li, unsigned int);
		ft_putchar(res);
		(*i)++;
	}
	else 
	{
		ft_putchar('%');
		(*i)++;
	}
}

static void string_pointer(va_list li, const char *frmt, size_t *i) {
	if (frmt[*i + 1] == 's')
	{
		char *res;

		res = va_arg(li, char *);
		ft_putstr(res);
		(*i)++;
	}
	else if (frmt[*i + 1] == 'p')
	{
		long	res;

		res = va_arg(li, long);
		
	}
}

int ft_printf(const char *format, ...)
{
	va_list li;
	size_t i;

	i = 0;
	va_start(li, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'd' || format[i + 1] == 'c' || format[i + 1] == '%' || format[i + 1] == 'i')
				decimal_char_percent_integer(li, format, &i);
			else if (format[i + 1] == 's' || format[i + 1] == 'p')
			string_pointer(li, format, &i);
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(li);
	return (i);
}

int main(void)
{
	ft_printf("bonjour, je m'apelle %s, j'ai %d, mon char presere est le %c", "mathieu", 23, 'a');
}