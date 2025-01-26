/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:01:19 by tkurukul          #+#    #+#             */
/*   Updated: 2025/01/26 20:22:45 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_check *check, t_texture *text)
{
	free_mat(check->matrix, check->count);
	free_image(text);
	if(text->win_ptr)
		mlx_destroy_window(text->mlx, text->win_ptr);
	if(text->mlx)
	{
		mlx_destroy_display(text->mlx);
		free(text->mlx);
	}
	return;
}
int	click(t_game *game)
{
	free_all(game->check, game->text);
	exit(0);
}

