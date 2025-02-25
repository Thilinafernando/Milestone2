/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:38:50 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/25 20:00:28 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	if_alpha(char str)
{
	if (str >= 65 && str <= 90
		|| str >= 97 && str <=122)
		return (1);
	return (0);
}
int	if_word(char *str, int i)
{
	while(str)
	{
		if (if_alpha(str[i]) == 1)
			return (1);
		else
			i++;
	}
	return (0);
}

char	**count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str)
	{
		if (str[i] == 32)
		{
			if (i != 0 && if_alpha(str[i - 1]) == 1
			&& if_word(str, i))
				count++;
			while (str[i] == 32)
				i++;
		}
		else
			i++;
	}
	return (count + 1);
}
function matrix

function child

void	parent(int ac, char **av)
{
	int	i;
	char	*str;

	i = 0;
	while (av)
		i++;
	str = ft_strdup(av[i - 2]);
}

int	main(int ac, char **av)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	*str;

	if (ac == 5)
	{
		if (pipe(pipefd) == -1)
			return (perror("PIPE failed:"), 0);
		pid1 = fork();
		if(pid1 != 0)
			parent(ac, av);
	}
	return (0);
}
