/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:50:23 by msuter            #+#    #+#             */
/*   Updated: 2026/03/27 19:12:20 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	verif(const char *str, int *i)
{
	if (str[*i] == '+' || str[*i] == '-' || str[*i] == '0')
	{
		if (str[*i] == '-' || str[*i] == '0')
		{
			printf("veuillez entrer un nombre positif");
			exit (1);
		}
		(*i)++;
	}
}

long	ft_atoi_c(const char *str)
{
	int		i;
	long	total;

	i = 0;
	total = 0;
	verif (str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
	{
		printf("erreur dans un argument, veuillez recommencer");
		exit(1);
	}
	return (total);
}
