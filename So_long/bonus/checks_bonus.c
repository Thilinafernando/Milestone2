/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:26:53 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/03 14:52:10 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/* int	check_p(char **matrix)
{
	int	i;
	int	j;


	i = 0;
	while (matrix[i])
	{
		j = 0;
		while(matrix[i][j])
		{
			j++;
		}
		i++;
	}
	if (!(p == 1))
		return(ft_printf("INVALID_MAP\nIncorrect values on the map!\n"), -1);
	return(0);
} */
int	check_p_e(t_check *c)
{
	int	i;
	int	j;
	int	e;
	int	p;

	e = 0;
	p = 0;
	i = 0;
	if (c->matrix == NULL)
		return (-1);
	while (c->matrix[i])
	{
		j = 0;
		while (c->matrix[i][j++])
		{
			if (c->matrix[i][j] == 'E')
				e++;
			else if (c->matrix[i][j] == 'P')
				p++;
		}
		i++;
	}
	if (!(e == 1 && p == 1))
		return (ft_printf("INVALID_MAP\nMissing value\n"), -1);
	return (0);
}

int	check_0(t_check *c)
{
	int	i;
	int	j;
	int	o;

	if (c->matrix == NULL)
		return (-1);
	i = 0;
	o = 0;
	while (c->matrix[i])
	{
		j = 0;
		while (c->matrix[i][j])
		{
			if (c->matrix[i][j] == '0')
				o++;
			j++;
		}
		i++;
	}
	if (o <= 0)
		return (ft_printf("INVALID_MAP\nBG MISSING!\n"), -1);
	return (0);
}

int	check_c(t_check *c)
{
	int	i;
	int	j;

	if (c->matrix == NULL)
		return (-1);
	c->col = 0;
	i = 0;
	while (c->matrix[i])
	{
		j = 0;
		while (c->matrix[i][j])
		{
			if (c->matrix[i][j] == 'C')
				c->col += 1;
			j++;
		}
		i++;
	}
	if (c->col <= 0)
		return (ft_printf("INVALIDMAP\nCollectables missin!\n"), -1);
	return (c->col);
}

int	top_bot_wall(t_check *c)
{
	int	i;

	if (c->matrix == NULL)
		return (-1);
	i = 0;
	while (c->matrix[0][i] && c->matrix[0][i] != '\n')
	{
		if (c->matrix[0][i] == '1')
			i++;
		else
			return (ft_printf("INVALID_MAP\nMap not closed!\n"), -1);
	}
	i = 0;
	while (c->matrix[c->count - 1][i]
		&& c->matrix[c->count - 1][i] != '\n')
	{
		if (c->matrix[c->count - 1][i] == '1')
			i++;
		else
			return (ft_printf("INVALID_MAP\nMap not closed!\n"), -1);
	}
	return (0);
}
