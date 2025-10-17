/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_hexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:48:09 by msuter            #+#    #+#             */
/*   Updated: 2025/10/17 18:15:51 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	algo(long nb)
{
	char *str;
	int i = 0;
	while (nb > 16)
	{
		if (nb % 16 == 10)
			str[i] = 'a';
		else if (nb % 16 == 11)
			str[i] = 'b';
		else if (nb % 16 == 12)
			str[i] = 'c';
		else if (nb % 16 == 13)
			str[i] = 'd';
		else if (nb % 16 == 14)
			str[i] = 'e';
		else if (nb % 16 == 15)
			str[i] = 'f';
		else
			str[i] = (nb % 16) + '0';
		i++;
		nb = nb / 16;
	}
	str[i] = nb + '0';
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
}

int main (void)
{
    algo(47239479347329);
}