/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:42:03 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/03 14:54:01 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mup(t_move *m, t_check *c, t_texture *t)
{
	m->ym--;
	if (c->matrix[m->ym][m->xm] == 'E' && c->col == 0)
	{
		free_all(c, t);
		ft_printf("YOU WON\n");
		exit(0);
	}
	if (c->matrix[m->ym][m->xm] == 'M')
		game_lost(c, t);
	if (c->matrix[m->ym][m->xm] == 'C' ||
		c->matrix[m->ym][m->xm] == '0'
		|| c->matrix[m->ym][m->xm] == 'P')
	{
		if (c->matrix[m->ym][m->xm] == 'C')
			c->col--;
		if (c->matrix[m->ym][m->xm] != '1' || c->matrix[m->ym][m->xm] != 'E')
		{
			c->matrix[m->ym + 1][m->xm] = '0';
			c->matrix[m->ym][m->xm] = 'U';
		}
		m->yp -= 48;
		m->nm += 1;
		m->ym = (m->yp / 64);
	}
}

void	mdown(t_move *m, t_check *c, t_texture *t)
{
	m->ym++;
	if (c->matrix[m->ym][m->xm] == 'E' && c->col == 0)
	{
		free_all(c, t);
		ft_printf("YOU WON\n");
		exit (0);
	}
	if (c->matrix[m->ym][m->xm] == 'M')
		game_lost(c, t);
	if (c->matrix[m->ym][m->xm] == 'C'
		|| c->matrix[m->ym][m->xm] == '0'
		|| c->matrix[m->ym][m->xm] == 'P')
	{
		if (c->matrix[m->ym][m->xm] == 'C')
			c->col--;
		if (c->matrix[m->ym][m->xm] != '1' || c->matrix[m->ym][m->xm] != 'E')
		{
			c->matrix[m->ym - 1][m->xm] = '0';
			c->matrix[m->ym][m->xm] = 'D';
		}
		m->yp += 48;
		m->nm += 1;
		m->ym = (m->yp / 64);
	}
}

void	mleft(t_move *m, t_check *c, t_texture *t)
{
	m->xm--;
	if (c->matrix[m->ym][m->xm] == 'E' && c->col == 0)
	{
		free_all(c, t);
		ft_printf("YOU WON\n");
		exit(0);
	}
	if (c->matrix[m->ym][m->xm] == 'M')
		game_lost(c, t);
	if (c->matrix[m->ym][m->xm] == 'C'
		|| c->matrix[m->ym][m->xm] == '0'
		|| c->matrix[m->ym][m->xm] == 'P')
	{
		if (c->matrix[m->ym][m->xm] == 'C' )
			c->col--;
		if (c->matrix[m->ym][m->xm] != '1' || c->matrix[m->ym][m->xm] != 'E')
		{
			c->matrix[m->ym][m->xm + 1] = '0';
			c->matrix[m->ym][m->xm] = 'P';
		}
		m->xp -= 48;
		m->nm += 1;
		m->xm = (m->xp / 64);
	}
}

void	mright(t_move *m, t_check *c, t_texture *t)
{
	m->xm++;
	if (c->matrix[m->ym][m->xm] == 'E' && c->col == 0)
	{
		free_all(c, t);
		ft_printf("YOU WON\n");
		exit(0);
	}
	if (c->matrix[m->ym][m->xm] == 'M')
		game_lost(c, t);
	if (c->matrix[m->ym][m->xm] == 'C'
		|| c->matrix[m->ym][m->xm] == '0'
		|| c->matrix[m->ym][m->xm] == 'P')
	{
		if (c->matrix[m->ym][m->xm] == 'C')
			c->col--;
		if (c->matrix[m->ym][m->xm] != '1' || c->matrix[m->ym][m->xm] != 'E')
		{
			c->matrix[m->ym][m->xm - 1] = '0';
			c->matrix[m->ym][m->xm] = 'R';
		}
		m->xp += 48;
		m->nm += 1;
		m->xm = (m->xp / 64);
	}
}

int	intake(int keycode, t_game *g)
{
	t_move		*m;
	t_check		*c;
	t_texture	*t;

	m = g->m;
	t = g->t;
	c = g->c;
	m->xm = m->xp / 48;
	m->ym = m->yp / 48;
	if (keycode == XK_Escape)
	{
		free_all(c, t);
		ft_printf("ESC PRESSED");
		exit(0);
	}
	if (keycode == XK_w || keycode == XK_Up)
		mup(m, c, t);
	if (keycode == XK_s || keycode == XK_Down)
		mdown(m, c, t);
	if (keycode == XK_d || keycode == XK_Right)
		mright(m, c, t);
	if (keycode == XK_a || keycode == XK_Left)
		mleft(m, c, t);
	return (0);
}
