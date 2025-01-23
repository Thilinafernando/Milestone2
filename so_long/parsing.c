/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:50:04 by tkurukul          #+#    #+#             */
/*   Updated: 2025/01/22 19:19:12 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(void)
{
	int	fd;
	int	i;
	size_t	j;
	char *line;

	i= 0;
	fd = open("txt.txt", O_RDONLY);
	if((line = get_next_line(fd)) != NULL)
	{
		j = ft_strlen(line);
		i++;
		free(line);
	}
	while((line = get_next_line(fd)) != NULL)
	{
		if (ft_strlen(line) != j)
		{
			ft_printf("INVALID_MAP\n");
			return(free(line), -1);
		}
			i++;
			free(line);
	}
	close(fd);
	return(i);
}
void	free_mat(char **matrix, int j)
{
	while(j >= 0)
	{
		free(matrix[j]);
		j--;
	}
	return;
}
char	**store(int count)
{
	char	**matrix;
	int		fd;
	int		i;

	i = 0;
	fd = open("txt.txt", O_RDONLY);
	matrix = malloc((count + 1) * sizeof(char *));
	if(!matrix)
		return(close(fd), NULL);
	while(i < count)
	{
		matrix[i] = get_next_line(fd);
		if (!matrix[i])
		{
			free_mat(matrix, i);
			return(NULL);
		}
		i++;
	}
	matrix[count] = NULL;
	close(fd);
	return(matrix);
}

int	main(void)
{
	all_check();
	return(0);
}

