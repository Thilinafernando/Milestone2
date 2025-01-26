/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:22:17 by tkurukul          #+#    #+#             */
/*   Updated: 2025/01/26 20:21:25 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_image(t_texture *text)
{
	if(!text->player || !text->coll || !text->groud || !text->wall || !text->exit || !text->rocks || !text->sea)
		ft_printf("ERROR WHILE LOADING IMAGE!");
	if (text->player)
		mlx_destroy_image(text->mlx, text->player);
	if (text->exit)
		mlx_destroy_image(text->mlx, text->exit);
	if (text->coll)
		mlx_destroy_image(text->mlx, text->coll);
	if (text->groud)
		mlx_destroy_image(text->mlx, text->groud);
	if (text->wall)
		mlx_destroy_image(text->mlx, text->wall);
	if (text->rocks)
		mlx_destroy_image(text->mlx, text->rocks);
	if (text->sea)
		mlx_destroy_image(text->mlx, text->sea);
	text->player = NULL;
	text->coll = NULL;
	text->groud = NULL;
	text->wall = NULL;
	text->exit = NULL;
	text->rocks = NULL;
	text->sea = NULL;
	return;
}

int mlx_initialize(t_check *check, t_texture *text)
{

	text->mlx = mlx_init();
	if(!text->mlx)
		return(-1);
	text->height = check->count;
	text->width = (ft_strlen(check->matrix[0]) - 1);
	if (text->width <= 0 || text->height <= 0)
		return (ft_printf("Error: Invalid matrix dimensions.\n"), -1);
	text->win_ptr = mlx_new_window(text->mlx, text->width * 48, text->height * 48, "SO_LONG");
	if(!text->win_ptr)
		return(ft_printf("ISSUE WHILE MAKING WINDOW!"), -1);
	return(0);
	// free(text.mlx);
}

int	image_creation(t_check *check, t_texture *text)
{
	int	height;
	int	width;

	height = 48;
	width = 48;
	text->player = mlx_xpm_file_to_image(text->mlx, "./textures/pikachu.xpm", &height, &width);
	if(!text->player)
		return(free_image(text), free_mat(check->matrix, check->count), -1);
	text->coll = mlx_xpm_file_to_image(text->mlx, "./textures/rarecandy.xpm", &height, &width);
	if(!text->coll)
		return(free_image(text), free_mat(check->matrix, check->count), -1);
	text->groud = mlx_xpm_file_to_image(text->mlx, "./textures/sand.xpm", &height, &width);
	if(!text->groud)
		return(free_image(text), free_mat(check->matrix, check->count), -1);
	text->wall = mlx_xpm_file_to_image(text->mlx, "./textures/walls.xpm", &height, &width);
	if(!text->wall)
		return(free_image(text), free_mat(check->matrix, check->count), -1);
	text->exit = mlx_xpm_file_to_image(text->mlx, "./textures/exit.xpm", &height, &width);
	if(!text->exit)
		return(free_image(text), free_mat(check->matrix, check->count), -1);
	text->rocks = mlx_xpm_file_to_image(text->mlx, "./textures/rocks.xpm", &height, &width);
	if(!text->rocks)
		return(free_image(text), free_mat(check->matrix, check->count), -1);
	return(0);
}
int	image_creation2(t_check *check, t_texture *text)
{
	int	height;
	int	width;

	height = 48;
	width = 48;
	text->sea = mlx_xpm_file_to_image(text->mlx, "./textures/sea.xpm", &height, &width);
	if(!text->sea)
		return(free_image(text), free_mat(check->matrix, check->count), -1);
	return(0);
}
void	image_insertion(t_check *check, t_texture *text)
{
	text->i = 0;
	text->yu = 0;
	while(check->matrix[text->i])
	{
		text->j = 0;
		text->xu = 0;
		while(check->matrix[text->i][text->j] && check->matrix[text->i][text->j] != '\n')
		{
			if(check->matrix[text->i][text->j] == '0')
				mlx_put_image_to_window(text->mlx, text->win_ptr, text->groud, text->xu, text->yu);
			if(check->matrix[text->i][text->j] == 'P')
				mlx_put_image_to_window(text->mlx, text->win_ptr, text->player, text->xu, text->yu);
			if(check->matrix[text->i][text->j] == 'E')
				mlx_put_image_to_window(text->mlx, text->win_ptr, text->exit, text->xu, text->yu);
			if(check->matrix[text->i][text->j] == 'C')
				mlx_put_image_to_window(text->mlx, text->win_ptr, text->coll, text->xu, text->yu);
			text->xu += 48;
			text->j++;
		}
		text->yu += 48;
		text->i++;
	}
}
void	image_insertion2(t_check *check, t_texture *text)
{
	text->i = 0;
	text->yu = 0;
	while(check->matrix[text->i])
	{
		text->j = 0;
		text->xu = 0;
		while(check->matrix[text->i][text->j] && check->matrix[text->i][text->j] != '\n')
		{
			if (check->matrix[text->i][text->j] == '1')
		{
			if(text->i == 0)
				mlx_put_image_to_window(text->mlx, text->win_ptr, text->sea, text->xu, text->yu);
			else if(text->i == (check->count - 1))
				mlx_put_image_to_window(text->mlx, text->win_ptr, text->rocks, text->xu, text->yu);
			else
				mlx_put_image_to_window(text->mlx, text->win_ptr, text->wall, text->xu, text->yu);
		}
			text->xu += 48;
			text->j++;
		}
		text->yu += 48;
		text->i++;
	}
}
