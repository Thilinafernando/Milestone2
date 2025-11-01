/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:04:55 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/03 15:05:31 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_insertion(t_check *c, t_texture *t)
{
	t->i = 0;
	t->yu = 0;
	while (c->matrix[t->i])
	{
		t->j = 0;
		t->xu = 0;
		while (c->matrix[t->i][t->j]
			&& c->matrix[t->i][t->j] != '\n')
		{
			if (c->matrix[t->i][t->j] == '0')
				IMG_WIN(t->mlx, t->win_ptr, t->groud, t->xu, t->yu);
			if (c->matrix[t->i][t->j] == 'P')
				IMG_WIN(t->mlx, t->win_ptr, t->player, t->xu, t->yu);
			if (c->matrix[t->i][t->j] == 'E')
				IMG_WIN(t->mlx, t->win_ptr, t->exit, t->xu, t->yu);
			if (c->matrix[t->i][t->j] == 'C')
				IMG_WIN(t->mlx, t->win_ptr, t->coll, t->xu, t->yu);
			t->xu += 48;
			t->j++;
		}
		t->yu += 48;
		t->i++;
	}
}

void	image_insertion2(t_check *c, t_texture *t)
{
	t->i = 0;
	t->yu = 0;
	while (c->matrix[t->i])
	{
		t->j = 0;
		t->xu = 0;
		while (c->matrix[t->i][t->j]
			&& c->matrix[t->i][t->j] != '\n')
		{
			if (c->matrix[t->i][t->j] == '1')
			{
				if (t->i == 0)
					IMG_WIN(t->mlx, t->win_ptr, t->sea, t->xu, t->yu);
				else if (t->i == (c->count - 1))
					IMG_WIN(t->mlx, t->win_ptr, t->rocks, t->xu, t->yu);
				else
					IMG_WIN(t->mlx, t->win_ptr, t->wall, t->xu, t->yu);
			}
			t->xu += 48;
			t->j++;
		}
		t->yu += 48;
		t->i++;
	}
}
