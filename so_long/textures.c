/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:22:17 by tkurukul          #+#    #+#             */
/*   Updated: 2025/01/27 22:01:08 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_image(t_texture *t)
{
	if (!t->player || !t->coll || !t->groud || !t->wall
		|| !t->exit || !t->rocks || !t->sea)
		ft_printf("ERROR WHILE LOADING IMAGE!");
	if (t->player)
		mlx_destroy_image(t->mlx, t->player);
	if (t->exit)
		mlx_destroy_image(t->mlx, t->exit);
	if (t->coll)
		mlx_destroy_image(t->mlx, t->coll);
	if (t->groud)
		mlx_destroy_image(t->mlx, t->groud);
	if (t->wall)
		mlx_destroy_image(t->mlx, t->wall);
	if (t->rocks)
		mlx_destroy_image(t->mlx, t->rocks);
	if (t->sea)
		mlx_destroy_image(t->mlx, t->sea);
	return ;
}

int	mlx_initialize(t_check *c, t_texture *t)
{
	t->mlx = mlx_init();
	if (!t->mlx)
		return (-1);
	if (image_creation(c, t) == -1)
	{
		ft_printf("1");
		mlx_destroy_display(t->mlx);
		return (free(t->mlx), -1);
	}
	if (image_creation2(c, t) == -1)
	{
		ft_printf("2");
		mlx_destroy_display(t->mlx);
		return (free(t->mlx), -1);
	}
	t->height = c->count;
	t->width = (ft_strlen(c->matrix[0]) - 1);
	if (t->width <= 0 || t->height <= 0)
		return (ft_printf("Error: Invalid matrix dimensions\n"), -1);
	t->win_ptr = mlx_new_window(t->mlx, t->width * 48,
			t->height * 48, "SO_LONG");
	if (!t->win_ptr)
		return (ft_printf("ISSUE WHILE MAKING WINDOW!"), -1);
	return (0);
}

int	image_creation(t_check *c, t_texture *t)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	t->player = mlx_xpm_file_to_image(t->mlx,
			"./textures/pikachu.xpm", &height, &width);
	if (!t->player)
		return (free_image(t), free_mat(c->matrix), -1);
	t->wall = mlx_xpm_file_to_image(t->mlx,
			"./textures/walls.xpm", &height, &width);
	if (!t->wall)
		return (free_image(t), free_mat(c->matrix), -1);
	t->exit = mlx_xpm_file_to_image(t->mlx,
			"./textures/exit.xpm", &height, &width);
	if (!t->exit)
		return (free_image(t), free_mat(c->matrix), -1);
	t->rocks = mlx_xpm_file_to_image(t->mlx,
			"./textures/rocks.xpm", &height, &width);
	if (!t->rocks)
		return (free_image(t), free_mat(c->matrix), -1);
	return (0);
}

int	image_creation2(t_check *c, t_texture *t)
{
	int	height;
	int	width;

	height = 48;
	width = 48;
	t->sea = mlx_xpm_file_to_image(t->mlx,
			"./textures/sea.xpm", &height, &width);
	if (!t->sea)
		return (free_image(t), free_mat(c->matrix), -1);
	t->coll = mlx_xpm_file_to_image(t->mlx,
			"./textures/rarecandy.xpm", &height, &width);
	if (!t->coll)
		return (free_image(t), free_mat(c->matrix), -1);
	t->groud = mlx_xpm_file_to_image(t->mlx,
			"./textures/sand.xpm", &height, &width);
	if (!t->groud)
		return (free_image(t), free_mat(c->matrix), -1);
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
