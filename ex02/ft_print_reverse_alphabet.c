/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 01:18:48 by msuter            #+#    #+#             */
/*   Updated: 2025/08/20 01:29:01 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	p;

	p = 'z';
	while (p >= 'a')
	{
		write (1, &p, 1);
		p -= 1;
	}
}

int	main(void)
{
	ft_print_reverse_alphabet();
	return (0);
}
