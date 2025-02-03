/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:07:22 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/03 15:07:52 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	lateral_wall(t_check *c) /// old
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (c->matrix == NULL)
		return (-1);
	while (c->matrix[i])
	{
		if (c->matrix[i][0] != '1')
			return (ft_printf("INVALID_MAP\nMap not closed!\n"), -1);
		i++;
	}
	i = 0;
	while (c->matrix[0][j] && c->matrix[0][j] != '\n')
		j++;
	j -= 1;
	i = 0;
	while (c->matrix[i])
	{
		if (c->matrix[i][j] != '1')
			return (ft_printf("INVALID_MAP\nMap not closed!\n"), -1);
		i++;
	}
	return (0);
}

int	flag_char(t_check *c)
{
	int	i;
	int	j;

	i = 0;
	if (c->matrix == NULL)
		return (-1);
	while (c->matrix[i])
	{
		j = 0;
		while (c->matrix[i][j])
		{
			if (c->matrix[i][j] != 'E' && c->matrix[i][j] != 'C'
				&& c->matrix[i][j] != 'P' && c->matrix[i][j] != '1'
				&& c->matrix[i][j] != '0' && c->matrix[i][j] != '\n')
			{
				ft_printf("INVALID_MAP: Invalid character\n");
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
