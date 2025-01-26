/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:42:03 by tkurukul          #+#    #+#             */
/*   Updated: 2025/01/26 20:24:11 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void mup(t_move *move, t_check *check, t_texture *text)
{
	move->ym--;
	if(check->matrix[move->ym][move->xm] == 'E' && check->col == 0)
	{
		free_all(check, text);
		ft_printf("YOU WON!");
		exit(0);
	}
	if(check->matrix[move->ym][move->xm] == 'C' || check->matrix[move->ym][move->xm] == '0'
		|| check->matrix[move->ym][move->xm] == 'P')
	{
		mlx_put_image_to_window(text->mlx, text->win_ptr, text->player, move->xp, move->yp - 48);
		mlx_put_image_to_window(text->mlx, text->win_ptr, text->groud, move->xp, move->yp);
		if(check->matrix[move->ym][move->xm] == 'C')
		{
			check->matrix[move->ym][move->xm] = '0';
			check->col--;
		}
		move->yp -= 48;
		ft_printf("PLAYER MOVES : %d\n", ++move->nm);
		move->ym = (move->yp / 64);
	}
}
void mdown(t_move *move, t_check *check, t_texture *text)
{
	move->ym++;
	if(check->matrix[move->ym][move->xm] == 'E' && check->col == 0)
	{
		free_all(check, text);
		ft_printf("YOU WON!");
		exit(0);
	}
	if(check->matrix[move->ym][move->xm] == 'C' || check->matrix[move->ym][move->xm] == '0'
		|| check->matrix[move->ym][move->xm] == 'P')
	{
		mlx_put_image_to_window(text->mlx, text->win_ptr, text->player, move->xp, move->yp + 48);
		mlx_put_image_to_window(text->mlx, text->win_ptr, text->groud, move->xp, move->yp);
		if(check->matrix[move->ym][move->xm] == 'C')
		{
			check->matrix[move->ym][move->xm] = '0';
			check->col--;
		}
		move->yp += 48;
		ft_printf("PLAYER MOVES : %d\n", ++move->nm);
		move->ym = (move->yp / 64);
	}
}
void mleft(t_move *move, t_check *check, t_texture *text)
{
	move->xm--;
	if(check->matrix[move->ym][move->xm] == 'E' && check->col == 0)
	{
		free_all(check, text);
		ft_printf("YOU WON!");
		exit(0);
	}
	if(check->matrix[move->ym][move->xm] == 'C' || check->matrix[move->ym][move->xm] == '0'
		|| check->matrix[move->ym][move->xm] == 'P')
	{
		mlx_put_image_to_window(text->mlx, text->win_ptr, text->player, move->xp - 48, move->yp);
		mlx_put_image_to_window(text->mlx, text->win_ptr, text->groud, move->xp, move->yp);
		if(check->matrix[move->ym][move->xm] == 'C')
		{
			check->matrix[move->ym][move->xm] = '0';
			check->col--;
		}
		move->xp -= 48;
		ft_printf("PLAYER MOVES : %d\n", ++move->nm);
		move->xm = (move->xp / 64);
	}
}
void mright(t_move *move, t_check *check, t_texture *text)
{
	move->xm++;
	if(check->matrix[move->ym][move->xm] == 'E' && check->col == 0)
	{
		free_all(check, text);
		ft_printf("YOU WON!");
		exit(0);
	}
	if(check->matrix[move->ym][move->xm] == 'C' || check->matrix[move->ym][move->xm] == '0'
		|| check->matrix[move->ym][move->xm] == 'P')
	{
		mlx_put_image_to_window(text->mlx, text->win_ptr, text->player, move->xp + 48, move->yp);
		mlx_put_image_to_window(text->mlx, text->win_ptr, text->groud, move->xp, move->yp);
		if(check->matrix[move->ym][move->xm] == 'C')
		{
			check->matrix[move->ym][move->xm] = '0';
			check->col--;
		}
		move->xp += 48;
		ft_printf("PLAYER MOVES : %d\n", ++move->nm);
		move->xm = (move->xp / 64);
	}
}
int	intake(int	keycode, t_game *game)
{
	t_move *move = game->move;
	t_check *check = game->check;
	t_texture *text = game->text;

	move->xm = move->xp / 48;
	move->ym = move->yp / 48;
	if(keycode == XK_Escape)
	{
		// ft_printf("%d , %d\n", check->col, check->collect);
		free_all(check, text);
		ft_printf("ESC PRESSED");
		exit(0);
	}
	if(keycode == XK_w)
		mup(move, check, text);
	if(keycode == XK_s)
		mdown(move, check, text);
	if(keycode == XK_d)
		mright(move, check, text);
	if(keycode == XK_a)
		mleft(move, check, text);
	return(0);
}

