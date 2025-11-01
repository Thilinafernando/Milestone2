/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:50:04 by tkurukul          #+#    #+#             */
/*   Updated: 2025/01/27 20:30:10 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	tryread(t_check *c)
{
	int	fd;

	fd = open(c->arg, O_RDONLY);
	if (fd == -1)
		return (ft_printf("ERROR\nMAP NOT FOUND"), -1);
	return (0);
}

int	count_line(t_check	*c)
{
	int		fd;
	size_t	j;
	char	*line;

	(c->count) = 0;
	fd = open(c->arg, O_RDONLY);
	line = get_next_line(fd);
	if (line != NULL)
	{
		j = ft_strlen(line);
		c->count += 1;
		free(line);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strlen(line) != j)
			return (close(fd), free(line), -1);
		c->count += 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (c->count);
}

void	free_mat(char **matrix)
{
	int	i;

	i = 0;
	if (matrix == NULL)
		return (free(matrix));
	while (matrix[i] != NULL)
		i++;
	if (matrix[i] == NULL)
		i--;
	while (i >= 0)
	{
		free(matrix[i]);
		i--;
	}
	free(matrix);
	return ;
}

char	**store(t_check *c)
{
	int		fd;
	int		i;

	i = 0;
	if (count_line(c) <= 2)
		return (NULL);
	fd = open(c->arg, O_RDONLY);
	c->matrix = malloc((c->count + 1) * sizeof(char *));
	if (!c->matrix)
		return (close(fd), NULL);
	while (i < c->count)
	{
		c->matrix[i] = get_next_line(fd);
		if (!c->matrix[i])
		{
			free_mat(c->matrix);
			close(fd);
			return (NULL);
		}
		i++;
	}
	c->matrix[c->count] = NULL;
	close(fd);
	return (c->matrix);
}
