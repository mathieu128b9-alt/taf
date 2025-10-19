/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_opti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:15:56 by msuter            #+#    #+#             */
/*   Updated: 2025/10/19 18:12:15 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr_base(unsigned long nb)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_putnbr_base(nb / 16);
		i++;
	}
	i++;
	write(1, &base[nb % 16], 1);
	return (i);
}
