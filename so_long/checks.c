/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:26:53 by tkurukul          #+#    #+#             */
/*   Updated: 2025/01/22 19:44:26 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
int	check_p_e(char **matrix)
{
	int	i;
	int	j;
	int	e;
	int	p;

	e = 0;
	p = 0;
	i = 0;
	while (matrix[i])
	{
		j = 0;
		while(matrix[i][j])
		{
			if (matrix[i][j] == 'E')
				e++;
			else if (matrix[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	if (!(e == 1 && p == 1))
		return(ft_printf("INVALID_MAP\nMissing spawnpoint or exit!\n"), -1);
	return(0);
}
int	check_c(char **matrix)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 0;
	while (matrix[i])
	{
		j = 0;
		while(matrix[i][j])
		{
			if (matrix[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (!(c > 0))
		return(ft_printf("INVALID_MAP\nIncorrect values on the map!\n"), -1);
	return(c);
}
int	top_bot_wall(char **matrix, int count)
{
	int	i;

	i = 0;
	while(matrix[0][i] && matrix[0][i] != '\n')
	{
		if(matrix[0][i] == '1')
			i++;
		else
			return(ft_printf("INVALID_MAP\nMap is not top closed!\n"), -1);
	}
	i = 0;
	while(matrix[count - 1][i] && matrix[count - 1][i] != '\n')
	{
		if(matrix[count - 1][i] == '1')
			i++;
		else
			return(ft_printf("INVALID_MAP\nMap is not bot closed!\n"), -1);
	}
	return(0);
}
int	lateral_wall(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(matrix[i])
	{
		if(matrix[i][0] == '1')
			i++;
		else
			return(ft_printf("INVALID_MAP\nMap is not left closed!\n"), -1);
	}
	i = 0;
	while(matrix[0][j])
		j++;
	while(matrix[i][j])
	{
		if(matrix[i][j] == '1')
			i++;
		else
			return(ft_printf("INVALID_MAP\nMap is not right closed!\n"), -1);
	}
	return(0);
}
int	flag_char(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while(matrix[i][j])
		{
			if (matrix[i][j] != 'E' && matrix[i][j] != 'C' && matrix[i][j] != 'P' &&
				matrix[i][j] != '1' && matrix[i][j] != '0' && matrix[i][j] != '\n')
			{
				ft_printf("INVALID_MAP: Invalid character '%c' at row %d, col %d\n",  matrix[i][j], i, j);
				return(-1);
			}
			j++;
		}
		i++;
	}
	return(0);
}
