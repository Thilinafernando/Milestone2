/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_call.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:19:57 by tkurukul          #+#    #+#             */
/*   Updated: 2025/01/24 15:32:53 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main()
{
	char	**map;
	char	**new;
	t_check	check;
	int x = 0;
	int y = 0;

	check.matrix = NULL;
	check.x = 0;
	check.y = 0;
	check.collect = 0;
	check.exit = 0;
	check.count = 0;
	check.col = 0;

	map = store(&check);
	check_c(&check);
	if((check_p_e(&check) < 0) || (check.col < 0) || (top_bot_wall(&check) < 0)
		|| (lateral_wall(&check) < 0) || (flag_char(&check) < 0))
			return(ft_printf("INVALID MAP B==D~~\n"), 0);
	else
		ft_printf("hokana");
	x = find_pos_x(&check);
	y = find_pos_y(&check);
	new = dup_matrix(&check);
	validate_map(new, &check);
	free(new);
	free(map);
}
