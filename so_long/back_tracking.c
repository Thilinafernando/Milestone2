/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:03:25 by tkurukul          #+#    #+#             */
/*   Updated: 2025/01/26 20:47:16 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_pos_x(t_check *check)
{
	check->y = 0;
	while (check->matrix[check->y])
	{
		check->x = 0;
		while(check->matrix[check->y][check->x])
		{
			if (check->matrix[check->y][check->x] == 'P')
			{
				return(check->x);
			}
			check->x++;
		}
		check->y++;
	}
	return(-1);
}
int	find_pos_y(t_check *check)
{

	check->y = 0;
	while (check->matrix[check->y])
	{
		check->x = 0;
		while(check->matrix[check->y][check->x])
		{
			if (check->matrix[check->y][check->x] == 'P')
			{
				return(check->y);
			}
			check->x++;
		}
		check->y++;
	}
	return(-1);
}
char	**dup_matrix(t_check *check)
{
	int		i;
	char	**new_matrix;

	i = 0;
	new_matrix = malloc((check->count + 1) * sizeof(char *));
	if(!new_matrix)
		return(NULL);
	while (i < check->count)
	{
		new_matrix[i] = ft_strdup(check->matrix[i]);
		if(!new_matrix[i])
			return(free_mat(new_matrix, i), NULL);
		i++;
	}
	new_matrix[check->count] = NULL;
	return(new_matrix);
}

int	validate_pos(char **nmatrix, int new_x, int new_y, t_check *check)
{
	if((new_y > (check->count - 1)) || (new_x > ((int)ft_strlen(nmatrix[0]) - 1)))
		return(-1);
	else if(nmatrix[new_y][new_x] == '1' || nmatrix[new_y][new_x] == 'M')
		return(-1);

	return(0);
}
int	ft_backtracking(char **nmatrix, int x, int y, t_check *check)
{
	if(nmatrix[y][x] == 'C')
		check->collect = check->collect + 1;
	if(nmatrix[y][x] == 'E')
		check->exit = check->exit + 1;
	nmatrix[y][x] = 'M';
	if(validate_pos(nmatrix, (x + 1), y, check) == 0)
		ft_backtracking(nmatrix,(x + 1), y,check);
	if(validate_pos(nmatrix, (x - 1), y, check) == 0)
		ft_backtracking(nmatrix,(x - 1), y,check);
	if(validate_pos(nmatrix, x, (y + 1), check) == 0)
		ft_backtracking(nmatrix, x ,(y + 1),check);
	if(validate_pos(nmatrix, x, (y - 1), check) == 0)
		ft_backtracking(nmatrix,x , (y - 1),check);
	return (0);
}
int	validate_map(char **nmatrix, t_check *check)
{
	if(check->collect != check->col || check->exit != '1')
		ft_backtracking(nmatrix, check->x, check->y, check);
	if(check->collect == check->col || check->exit == '1')
		return(free_mat(nmatrix, check->count), 0);
	ft_printf("INVALID MAP! BACKTRACKING");
	return(free_mat(nmatrix, check->count), -1);
}
