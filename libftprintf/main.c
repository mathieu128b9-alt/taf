/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:28:10 by msuter            #+#    #+#             */
/*   Updated: 2025/11/04 17:28:28 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	li;
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	va_start(li, format);
	while (format[i] != '\0')
		case_percent(&li, format, &i, &count);
	va_end(li);
	return (count);
}
