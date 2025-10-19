/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_maj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:35:02 by msuter            #+#    #+#             */
/*   Updated: 2025/10/19 18:11:52 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_maj(unsigned long nb)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_putnbr_base_maj(nb / 16);
		i++;
	}
	i++;
	write(1, &base[nb % 16], 1);
	return (i);
}
