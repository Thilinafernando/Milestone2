/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_call.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:19:57 by tkurukul          #+#    #+#             */
/*   Updated: 2025/01/22 19:22:18 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	all_check(void)
{
	char	**c;
	// int	i = 0;
	int j = count_line();

	// printf("%d\n", count_line());
	c = store(j);
	if(!c)
		return (ft_printf("ERROR: Could not store map\n"), -1);
	// while (c[i] != NULL)
	// {
	// 	printf("%s", c[i]);
	// 	i++;
	// }
	if ((check_p_e(c) >= 0) && (check_c(c) >= 0)
		&& (flag_char(c) >= 0) && (top_bot_wall(c, j) >= 0)
		&& (lateral_wall(c) >= 0))
		{
			//ft_printf("INVALID MAP B==D\n");
			free_mat(c, j);
			return (-1);
		}
	else
		ft_printf("VALID MAP!\n");
	return(0);
}
