/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:03:25 by tkurukul          #+#    #+#             */
/*   Updated: 2025/01/27 20:06:04 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_pos_x(t_check *c)
{
	c->y = 0;
	while (c->matrix[c->y])
	{
		c->x = 0;
		while (c->matrix[c->y][c->x])
		{
			if (c->matrix[c->y][c->x] == 'P')
			{
				return (c->x);
			}
			c->x++;
		}
		c->y++;
	}
	return (-1);
}

int	find_pos_y(t_check *c)
{
	c->y = 0;
	while (c->matrix[c->y])
	{
		c->x = 0;
		while (c->matrix[c->y][c->x])
		{
			if (c->matrix[c->y][c->x] == 'P')
			{
				return (c->y);
			}
			c->x++;
		}
		c->y++;
	}
	return (-1);
}

char	**dup_matrix(t_check *c)
{
	int		i;

	i = 0;
	c->nmat = malloc((c->count + 1) * sizeof(char *));
	if (!c->nmat)
		return (NULL);
	while (i < c->count)
	{
		c->nmat[i] = ft_strdup(c->matrix[i]);
		if (!c->nmat[i])
			return (free_mat(c->nmat), NULL);
		i++;
	}
	c->nmat[c->count] = NULL;
	return (c->nmat);
}

int	validate_pos(int new_x, int new_y, t_check *c)
{
	if ((new_y > (c->count - 1)) || (new_x > ((int)ft_strlen(c->nmat[0]) - 1)))
		return (-1);
	else if (c->nmat[new_y][new_x] == '1' || c->nmat[new_y][new_x] == 'M')
		return (-1);
	return (0);
}

int	ft_backtracking(int x, int y, t_check *c)
{
	if (c->nmat[y][x] == 'C')
		c->collect = c->collect + 1;
	if (c->nmat[y][x] == 'E')
		c->exit = c->exit + 1;
	c->nmat[y][x] = 'M';
	if (validate_pos((x + 1), y, c) == 0)
		ft_backtracking((x + 1), y, c);
	if (validate_pos((x - 1), y, c) == 0)
		ft_backtracking((x - 1), y, c);
	if (validate_pos(x, (y + 1), c) == 0)
		ft_backtracking(x, (y + 1), c);
	if (validate_pos(x, (y - 1), c) == 0)
		ft_backtracking(x, (y - 1), c);
	return (0);
}

int	validate_map(t_check *c)
{
	if (c->collect != c->col || c->exit != '1')
		ft_backtracking(c->x, c->y, c);
	if (c->collect == c->col || c->exit == '1')
		return (free_mat(c->nmat), 0);
	else
	{
		ft_printf("INVALID MAP! BACKTRACKING");
		return (free_mat(c->nmat), -1);
	}
	return (0);
}
