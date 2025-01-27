/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:42:03 by tkurukul          #+#    #+#             */
/*   Updated: 2025/01/27 20:24:55 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mup(t_move *m, t_check *c, t_texture *t)
{
	m->ym--;
	if (c->matrix[m->ym][m->xm] == 'E' && c->col == 0)
	{
		free_all(c, t);
		ft_printf("YOU WON!");
		exit(0);
	}
	if (c->matrix[m->ym][m->xm] == 'C' ||
		c->matrix[m->ym][m->xm] == '0'
		|| c->matrix[m->ym][m->xm] == 'P')
	{
		mlx_put_image_to_window(t->mlx, t->win_ptr,
			t->player, m->xp, m->yp - 48);
		mlx_put_image_to_window(t->mlx, t->win_ptr,
			t->groud, m->xp, m->yp);
		if (c->matrix[m->ym][m->xm] == 'C')
		{
			c->matrix[m->ym][m->xm] = '0';
			c->col--;
		}
		m->yp -= 48;
		ft_printf("PLAYER MOVES : %d\n", ++m->nm);
		m->ym = (m->yp / 64);
	}
}

void	mdown(t_move *m, t_check *c, t_texture *t)
{
	m->ym++;
	if (c->matrix[m->ym][m->xm] == 'E' && c->col == 0)
	{
		free_all(c, t);
		ft_printf("YOU WON!");
		exit (0);
	}
	if (c->matrix[m->ym][m->xm] == 'C'
		|| c->matrix[m->ym][m->xm] == '0'
		|| c->matrix[m->ym][m->xm] == 'P')
	{
		mlx_put_image_to_window(t->mlx, t->win_ptr,
			t->player, m->xp, m->yp + 48);
		mlx_put_image_to_window(t->mlx, t->win_ptr,
			t->groud, m->xp, m->yp);
		if (c->matrix[m->ym][m->xm] == 'C')
		{
			c->matrix[m->ym][m->xm] = '0';
			c->col--;
		}
		m->yp += 48;
		ft_printf("PLAYER MOVES : %d\n", ++m->nm);
		m->ym = (m->yp / 64);
	}
}

void	mleft(t_move *m, t_check *c, t_texture *t)
{
	m->xm--;
	if (c->matrix[m->ym][m->xm] == 'E' && c->col == 0)
	{
		free_all(c, t);
		ft_printf("YOU WON!");
		exit(0);
	}
	if (c->matrix[m->ym][m->xm] == 'C'
		|| c->matrix[m->ym][m->xm] == '0'
		|| c->matrix[m->ym][m->xm] == 'P')
	{
		mlx_put_image_to_window(t->mlx, t->win_ptr,
			t->player, m->xp - 48, m->yp);
		mlx_put_image_to_window(t->mlx, t->win_ptr,
			t->groud, m->xp, m->yp);
		if (c->matrix[m->ym][m->xm] == 'C')
		{
			c->matrix[m->ym][m->xm] = '0';
			c->col--;
		}
		m->xp -= 48;
		ft_printf("PLAYER MOVES : %d\n", ++m->nm);
		m->xm = (m->xp / 64);
	}
}

void	mright(t_move *m, t_check *c, t_texture *t)
{
	m->xm++;
	if (c->matrix[m->ym][m->xm] == 'E' && c->col == 0)
	{
		free_all(c, t);
		ft_printf("YOU WON!");
		exit(0);
	}
	if (c->matrix[m->ym][m->xm] == 'C'
		|| c->matrix[m->ym][m->xm] == '0'
		|| c->matrix[m->ym][m->xm] == 'P')
	{
		mlx_put_image_to_window(t->mlx, t->win_ptr,
			t->player, m->xp + 48, m->yp);
		mlx_put_image_to_window(t->mlx, t->win_ptr,
			t->groud, m->xp, m->yp);
		if (c->matrix[m->ym][m->xm] == 'C')
		{
			c->matrix[m->ym][m->xm] = '0';
			c->col--;
		}
		m->xp += 48;
		ft_printf("PLAYER MOVES : %d\n", ++m->nm);
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
	if (keycode == XK_w)
		mup(m, c, t);
	if (keycode == XK_s)
		mdown(m, c, t);
	if (keycode == XK_d)
		mright(m, c, t);
	if (keycode == XK_a)
		mleft(m, c, t);
	return (0);
}
