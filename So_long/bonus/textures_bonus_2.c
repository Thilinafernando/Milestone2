/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:58:40 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/03 14:59:54 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	image_creation_bonus(t_check *c, t_texture *t)
{
	int	height;
	int	width;

	height = 48;
	width = 48;
	t->right = mlx_xpm_file_to_image(t->mlx,
			"./textures/right.xpm", &height, &width);
	if (!t->right)
		return (free_bn(t), free_image(t), free_mat(c->matrix), -1);
	t->up = mlx_xpm_file_to_image(t->mlx,
			"./textures/up.xpm", &height, &width);
	if (!t->up)
		return (free_bn(t), free_image(t), free_mat(c->matrix), -1);
	t->down = mlx_xpm_file_to_image(t->mlx,
			"./textures/down.xpm", &height, &width);
	if (!t->down)
		return (free_bn(t), free_image(t), free_mat(c->matrix), -1);
	t->wall2 = mlx_xpm_file_to_image(t->mlx,
			"./textures/wall2.xpm", &height, &width);
	if (!t->wall2)
		return (free_bn(t), free_image(t), free_mat(c->matrix), -1);
	return (0);
}

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
			if (c->matrix[t->i][t->j] == 'M')
				IMG_WIN(t->mlx, t->win_ptr, t->enemy, t->xu, t->yu);
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
		while (c->matrix[t->i][t->j] && c->matrix[t->i][t->j] != '\n')
		{
			if (c->matrix[t->i][t->j] == '1')
			{
				if (t->i == 0)
					IMG_WIN(t->mlx, t->win_ptr, t->sea, t->xu, t->yu);
				else if (t->i == (c->count - 1))
					IMG_WIN(t->mlx, t->win_ptr, t->rocks, t->xu, t->yu);
				else if (t->wallst == 1)
					IMG_WIN(t->mlx, t->win_ptr, t->wall2, t->xu, t->yu);
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

void	image_insertion_bonus(t_check *c, t_texture *t)
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
			if (c->matrix[t->i][t->j] == 'R')
				IMG_WIN(t->mlx, t->win_ptr, t->right, t->xu, t->yu);
			if (c->matrix[t->i][t->j] == 'U')
				IMG_WIN(t->mlx, t->win_ptr, t->up, t->xu, t->yu);
			if (c->matrix[t->i][t->j] == 'D')
				IMG_WIN(t->mlx, t->win_ptr, t->down, t->xu, t->yu);
			t->xu += 48;
			t->j++;
		}
		t->yu += 48;
		t->i++;
	}
}
