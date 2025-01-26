/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_call.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:19:57 by tkurukul          #+#    #+#             */
/*   Updated: 2025/01/26 20:49:06 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_all(t_check *check)
{
	char	**map;
	char	**new;
	;
	int	x;
	int	y;

	check->matrix = NULL;
	check->x = 0;
	check->y = 0;
	check->collect = 0;
	check->exit = 0;
	check->count = 0;
	check->col = 0;

	map = store(check);
	if(!map)
		return(-1);
	check_c(check);
	x = find_pos_x(check);
	y = find_pos_y(check);
	new = dup_matrix(check);
	if((check_p_e(check) < 0) || (check->col < 0) || (top_bot_wall(check) < 0)
		|| (lateral_wall(check) < 0) || (flag_char(check) < 0) || (validate_map(new, check) < 0))
			return(free(new), free(map), ft_printf("INVALID MAP B==D~~\n"), -1);
	return(0);
}
int	main()
{
	t_check	check;
	t_texture	text;
	t_move	move;
	t_game game;

	if(check_all(&check) != 0)
		return(0);
	if(mlx_initialize(&check, &text) == 0)
	if(image_creation(&check, &text) == -1)
		return(-1);
	if(image_creation2(&check, &text) == -1)
		return(-1);
	image_insertion(&check, &text);
	image_insertion2(&check, &text);
	move.xp = find_pos_x(&check) * 48;
	move.yp = find_pos_y(&check) * 48;
	ft_printf("Player Moves : %d\n", move.nm = 0);
	game.move = &move;
	game.check = &check;
	game.text = &text;
	mlx_hook(text.win_ptr, 2, 1L << 0, intake, &game);
	mlx_hook(text.win_ptr, 17, 1L << 0, click, &game);
	mlx_loop(text.mlx);
	return(0);
}
