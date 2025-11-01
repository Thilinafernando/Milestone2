/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:01:19 by tkurukul          #+#    #+#             */
/*   Updated: 2025/01/28 17:39:00 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_all(t_check *c, t_texture *t)
{
	free_mat(c->matrix);
	free_image(t);
	free_bn(t);
	if (t->win_ptr)
		mlx_destroy_window(t->mlx, t->win_ptr);
	if (t->mlx)
	{
		mlx_destroy_display(t->mlx);
		free(t->mlx);
	}
	return ;
}

int	click(t_game *g)
{
	free_all(g->c, g->t);
	exit(0);
}
