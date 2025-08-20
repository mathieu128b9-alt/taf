/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 08:51:40 by mathieu           #+#    #+#             */
/*   Updated: 2025/08/20 09:21:04 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(void)
{
	int		t;
	char	p;
	char	n;

	t = 0;
	p = 'P';
	n = 'N';
	if (t >= 0)
	{
		write(1, &p, 1);
	}
	else
	{
		write(1, &n, 1);
	}
}

int	main(void)
{
	ft_is_negative ();
	return (0);
}
