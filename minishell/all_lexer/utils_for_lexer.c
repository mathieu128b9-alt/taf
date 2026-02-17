/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_lexer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:30:30 by msuter            #+#    #+#             */
/*   Updated: 2026/02/17 12:39:40 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	detect_pipes_or_signal(char *imput, int *count, int *i)
{
	//if(imput[*i] == '|')
	
}

int	how_many_tokens(char *imput)
{
	int	i;
	int	count;
	int	flag;

	count = 0;
	i = 0;
	flag = 1;
	while (imput[i])
	{
		if (flag == 0)
			count++;
		flag = 1;
		if (imput[i] == ' ')
		{
			if (imput[i + 1] == ' ')
				i++;
			else if (imput[i + 1] == '/' || imput[i + 1] == '>' || imput[i + 1] == '<')
			{
				i++;
				detect_pipes_or_signal(imput, count, i);
			}
			else
				flag = 0;
		}
		i++;
	}
	return (count + 1);
}

/*
	donc pour le moment, j'ai fait en sorte que a chaque fin de mot, je verifie si un nouveau commence,
	si oui, mon flag passe a 0 et je compte un mot de plus, ca skip les espaces en trop entre,
	et ya aussi le cas de rencontre d'un pipe, > ou <, si je rencontre ca, on entre dans la f du dessus,
	evidemment on i++ a chaque tour de verif, 
	mtn faut que je capte comment faire en sorte que a la rencontre d'un pipe, il compte un mot de plus,
	et qu'il restart pour le mot suivant, (avec et sans espaces entre mot-pipe)
*/