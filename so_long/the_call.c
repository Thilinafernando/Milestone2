/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_call.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:19:57 by tkurukul          #+#    #+#             */
/*   Updated: 2025/01/28 23:06:27 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_all(t_check *c)
{
	char	**map;
	char	**new;

	c->matrix = NULL;
	c->x = 0;
	c->y = 0;
	c->collect = 0;
	c->exit = 0;
	c->count = 0;
	c->col = 0;
	map = store(c);
	if (!map)
		return (ft_printf("INVALID MAP\n"), -1);
	check_c(c);
	find_pos_x(c);
	find_pos_y(c);
	new = dup_matrix(c);
	if ((check_p_e(c) < 0) || (c->col <= 0) || (top_bot_wall(c) < 0)
		|| lateral_wall(c) < 0 || flag_char(c) < 0 || check_0(c) < 0)
		return (free_mat(new), -1);
	if (validate_map(c) == -1)
		return (-1);
	return (0);
}

int	pablo(t_check *c, t_texture *t, t_move *m, t_game *g)
{
	if (check_all(c) != 0)
	{
		free_mat(c->matrix);
		return (0);
	}
	if (mlx_initialize(c, t) == 0)
	{
		image_insertion(c, t);
		image_insertion2(c, t);
		m->xp = find_pos_x(c) * 48;
		m->yp = find_pos_y(c) * 48;
		ft_printf("Player Moves : %d\n", m->nm = 0);
		g->m = m;
		g->c = c;
		g->t = t;
		mlx_hook(t->win_ptr, 2, 1L << 0, intake, g);
		mlx_hook(t->win_ptr, 17, 1L << 0, click, g);
		mlx_loop(t->mlx);
	}
	return (0);
}

int	ifber(char *ber)
{
	if (ft_strncmp(ber + (ft_strlen(ber) - 4), ".ber", 4) == 0)
		return (0);
	ft_printf("NOT BER MAP");
	return (-1);
}

int	main(int argc, char **argv)
{
	t_check		c;
	t_texture	t;
	t_move		m;
	t_game		g;

	t.player = NULL;
	t.coll = NULL;
	t.groud = NULL;
	t.wall = NULL;
	t.exit = NULL;
	t.rocks = NULL;
	t.sea = NULL;
	if (argc == 2)
	{
		if (ifber(argv[1]) == 0)
		{
			c.arg = argv[1];
			if (tryread(&c) == -1)
				return (0);
			if(pablo(&c, &t, &m, &g) != 0)
			{
				return(-1);
			}
		}
	}
	else
		ft_printf("INSERT MAP!");
	return (0);
}
