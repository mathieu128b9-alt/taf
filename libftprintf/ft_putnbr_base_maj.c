/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_maj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:35:02 by msuter            #+#    #+#             */
/*   Updated: 2025/10/18 21:37:06 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_maj(long nb)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nb < 0)
	{
		write (1, "-", 1);
		nb = -nb;
	}
	if (nb >= 16)
		ft_putnbr_base_maj(nb / 16);
	write(1, &base[nb % 16], 1);
}
