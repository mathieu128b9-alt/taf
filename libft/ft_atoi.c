/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 01:17:15 by mathieu           #+#    #+#             */
/*   Updated: 2025/10/07 19:10:40 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_negatif(char t, int negat)
{
	if (t == '+')
		return (negat);
	else if (t == '-')
		return (-negat);
	else
		return (negat);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	total;

	i = 0;
	sign = 1;
	total = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = is_negatif(str[i], sign);
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10;
		total = total + (str[i] - '0');
		i++;
	}
	return (total * sign);
}
