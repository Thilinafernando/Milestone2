/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:03:25 by tkurukul          #+#    #+#             */
/*   Updated: 2025/01/23 18:10:39 by tkurukul         ###   ########.fr       */
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
			if (check->matrix[check->y][check->x] != 'P')
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
			if (check->matrix[check->y][check->x] != 'P')
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
		if(!new_matrix)
			return(free_mat(new_matrix, i), NULL);
		i++;
	}
	new_matrix[check->count] = NULL;
	return(new_matrix);
}

int	validate_pos(char **nmatrix, int new_x, int new_y, t_check *check)
{
	if((new_y > (check->count - 1)) || (new_x > ((int)ft_strlen(nmatrix[0]))))
		return(-1);
	else if(nmatrix[new_y][new_x] == '1' || nmatrix[new_y][new_x] == 'M')
		return(-1);

	return(0);
}
int	ft_backtracking(char **nmatrix, t_check *check)
{
	if(nmatrix[check->y][check->x] == 'C')
		check->collect = check->collect + 1;
	if(nmatrix[check->y][check->x] == 'E')
		check->exit = check->exit + 1;
	nmatrix[check->y][check->x] = 'M';
	if(validate_pos(nmatrix, (check->x + 1), check->y, check) == 0)
		{
		check->x += 1;
		ft_backtracking(nmatrix, check);
		check->x -= 1;
		}
	if(validate_pos(nmatrix, (check->x - 1), check->y, check) == 0)
	{
		check->x -= 1; // Move left
		ft_backtracking(nmatrix, check);
		check->x += 1; // Backtrack
    }
	if(validate_pos(nmatrix, check->x, (check->y + 1), check) == 0)
	{
		check->y += 1; // Move down
		ft_backtracking(nmatrix, check);
		check->y -= 1; // Backtrack
	}
	if(validate_pos(nmatrix, check->x, (check->y - 1), check) == 0)
		{
		check->y -= 1; // Move up
		ft_backtracking(nmatrix, check);
		check->y += 1; // Backtrack
    }
	return (0);
}
int	validate_map(char **nmatrix, t_check *check)
{
	check->collect = 0;
	check->exit = 0;

	ft_backtracking(nmatrix, check);
	if(check->collect != check->col || check->exit != '1')
	{
		ft_printf("VALID MAP! BACKTRACKINGH");
		return(0);
	}
	ft_printf("INVALID MAP! BACKTRACKING");
	return(-1);
}
