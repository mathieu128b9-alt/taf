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

static void	dec_char_perc_int(va_list *li, const char *frmt, size_t *i)
{
	int		result;
	char	*printable;
	char	res;

	if (frmt[*i + 1] == 'd' || frmt[*i + 1] == 'i')
	{
		result = va_arg(*li, int);
		printable = ft_itoa(result);
		ft_putstr(printable);
		(*i)++;
	}
	else if (frmt[*i + 1] == 'c')
	{
		res = va_arg(*li, unsigned int);
		ft_putchar(res);
		(*i)++;
	}
	else
	{
		ft_putchar('%');
		(*i)++;
	}
}

static void	string_pointer(va_list *li, const char *frmt, size_t *i)
{
	char	*res;
	void	*result;

	if (frmt[*i + 1] == 's')
	{
		res = va_arg(*li, char *);
		ft_putstr(res);
		(*i)++;
	}
	else if (frmt[*i + 1] == 'p')
	{
		write (1, "ox", 2);
		result = va_arg(*li, void *);
		ft_putnbr_base((long)result);
		(*i)++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	li;
	size_t	i;

	i = 0;
	va_start(li, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'd' || format[i + 1] == 'c'
				|| format[i + 1] == '%' || format[i + 1] == 'i')
				dec_char_perc_int(&li, format, &i);
			else if (format[i + 1] == 's' || format[i + 1] == 'p')
				string_pointer(&li, format, &i);
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(li);
	return (i);
}
#include <stdio.h>
int main (void)
{
	char *p = NULL;
	ft_printf("%p je m'apelle %s j'ai %d, et mon char prefere %% est %c\n", &p, "mathieu", 23, 'a');
	printf("%p je m'apelle %s j'ai %d, et mon char prefere %% est %c\n", &p, "mathieu", 23, 'a');

}
