/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:55:11 by msuter            #+#    #+#             */
/*   Updated: 2025/10/15 17:28:57 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			if (format[i + 1] == '%')
			{
				ft_putchar('%');
				i++;
			}
			else if (format[i + 1] == 'd')
			{
				int	res;
				char *printable;
				
				res = va_arg(li, int);
				printable = ft_itoa(res);
				ft_putstr(printable);
				i++;
			}
			else if (format[i + 1] == 'c')
			{
				char	res;
				
				res = va_arg(li, unsigned int);
				ft_putchar(res);
				i++;
			}
			else if (format[i + 1] == 's')
			{
				char	*res;
				res = va_arg(li, char *);
				ft_putstr(res);
				i++;
			}
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(li);
}
