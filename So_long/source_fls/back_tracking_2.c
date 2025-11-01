/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:06:18 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/03 15:06:36 by tkurukul         ###   ########.fr       */
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
