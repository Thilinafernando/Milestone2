/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_call_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:19:57 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/03 15:37:22 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	g->timer = 0;
	t->wallst = 1;
	if (check_all(c) != 0)
	{
		free_mat(c->matrix);
		return (0);
	}
	if (mlx_initialize(c, t) == 0)
	{
		m->xp = find_pos_x(c) * 48;
		m->yp = find_pos_y(c) * 48;
		g->m = m;
		g->c = c;
		g->t = t;
		g->m->nm = 0;
		mlx_hook(t->win_ptr, 2, 1L << 0, intake, g);
		mlx_hook(t->win_ptr, 17, 1L << 0, click, g);
		mlx_loop_hook(t->mlx, &game_loop, g);
		mlx_loop(t->mlx);
	}
	return (0);
}

int	game_loop(t_game *g)
{
	char	*moves;

	g->timer++;
	if (g->timer >= 400)
	{
		g->timer = 0;
		g->t->wallst = !g->t->wallst;
	}
	moves = ft_itoa(g->m->nm);
	image_insertion(g->c, g->t);
	image_insertion2(g->c, g->t);
	image_insertion_bonus(g->c, g->t);
	mlx_string_put(g->t->mlx, g->t->win_ptr, 10, 20, 0xFF0000, "Moves: ");
	mlx_string_put(g->t->mlx, g->t->win_ptr, 80, 20, 0xFF0000, moves);
	free(moves);
	return (0);
}

int	ifber(char *ber)
{
	if (ft_strncmp(ber + (ft_strlen(ber) - 4), ".ber", 4) == 0)
		return (0);
	ft_printf("ERROR\nNOT BER MAP");
	return (-1);
}

int	main(int argc, char **argv)
{
	t_check		c;
	t_texture	t;
	t_move		m;
	t_game		g;

	if (argc == 2)
	{
		if (ifber(argv[1]) == 0)
		{
			c.arg = argv[1];
			if (tryread(&c) == -1)
				return (0);
			if (pablo(&c, &t, &m, &g) != 0)
			{
				return (-1);
			}
		}
	}
	else
		ft_printf("Error\nINSERT MAP!");
	return (0);
}
