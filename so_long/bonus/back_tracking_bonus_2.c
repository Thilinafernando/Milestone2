/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:47:58 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/03 14:48:17 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	validate_map(t_check *c)
{
	if (c->collect != c->col || c->exit != '1')
		ft_backtracking(c->x, c->y, c);
	if (c->collect == c->col || c->exit == '1')
		return (free_mat(c->nmat), 0);
	else
	{
		ft_printf("ERROR\n!BACKTRACKING");
		return (free_mat(c->nmat), -1);
	}
	return (0);
}
