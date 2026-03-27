/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:50:23 by msuter            #+#    #+#             */
/*   Updated: 2026/03/27 23:10:03 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	verif(const char *str, int *i)
{
	if (str[*i] == '+' || str[*i] == '-' || str[*i] == '0')
	{
		if (str[*i] == '-' || str[*i] == '0')
		{
			printf("veuillez entrer un nombre positif\n");
			exit (1);
		}
		(*i)++;
		if (str[*i] == '\0')
		{
			printf ("veuillez entrer un nombre valide\n");
			exit (1);
		}
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
		printf("erreur dans un argument, veuillez recommencer\n");
		exit(1);
	}
	if (total < 2147483647)
		return (total);
	printf ("veuillez entrer un nombre inferieur, la limite est 2147483647\n");
	exit (1);
}
