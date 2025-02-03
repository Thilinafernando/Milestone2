/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:22:17 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/03 15:00:42 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	free_bn(t_texture *t)
{
	if (!t->right || !t->down || !t->up || !t->enemy
		|| !t->wall2)
		ft_printf("ERROR WHILE LOADING IMAGE!");
	if (t->right)
		mlx_destroy_image(t->mlx, t->right);
	if (t->down)
		mlx_destroy_image(t->mlx, t->down);
	if (t->up)
		mlx_destroy_image(t->mlx, t->up);
	if (t->enemy)
		mlx_destroy_image(t->mlx, t->enemy);
	if (t->wall2)
		mlx_destroy_image(t->mlx, t->wall2);
	return ;
}

int	mlx_initialize(t_check *c, t_texture *t)
{
	t->mlx = mlx_init();
	if (!t->mlx)
		return (-1);
	if (image_creation(c, t) == -1 || image_creation2(c, t) == -1
		|| image_creation_bonus(c, t) == -1)
	{
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
		return (free_bn(t), free_image(t), free_mat(c->matrix), -1);
	t->coll = mlx_xpm_file_to_image(t->mlx,
			"./textures/rarecandy.xpm", &height, &width);
	if (!t->coll)
		return (free_bn(t), free_image(t), free_mat(c->matrix), -1);
	t->groud = mlx_xpm_file_to_image(t->mlx,
			"./textures/sand.xpm", &height, &width);
	if (!t->groud)
		return (free_bn(t), free_image(t), free_mat(c->matrix), -1);
	t->enemy = mlx_xpm_file_to_image(t->mlx,
			"./textures/enemy.xpm", &height, &width);
	if (!t->enemy)
		return (free_bn(t), free_image(t), free_mat(c->matrix), -1);
	return (0);
}
