/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:26:53 by tkurukul          #+#    #+#             */
/*   Updated: 2025/01/23 16:26:13 by tkurukul         ###   ########.fr       */
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
int	check_p_e(t_check *check)
{
	int	i;
	int	j;
	int	e;
	int	p;

	e = 0;
	p = 0;
	i = 0;
	while (check->matrix[i])
	{
		j = 0;
		while(check->matrix[i][j])
		{
			if (check->matrix[i][j] == 'E')
				e++;
			else if (check->matrix[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	if (!(e == 1 && p == 1))
		return(ft_printf("INVALID_MAP\nMissing spawnpoint or exit!\n"), -1);
	return(0);
}
int	check_c(t_check *check)
{
	int	i;
	int	j;

	check->col = 0;
	i = 0;
	while (check->matrix[i])
	{
		j = 0;
		while(check->matrix[i][j])
		{
			if (check->matrix[i][j] == 'C')
				check->col++;
			j++;
		}
		i++;
	}
	if (!(check->col > 0))
		return(ft_printf("INVALID_MAP\nIncorrect values on the map!\n"), -1);
	return(check->col);
}
int	top_bot_wall(t_check *check)
{
	int	i;

	i = 0;
	while(check->matrix[0][i] && check->matrix[0][i] != '\n')
	{
		if(check->matrix[0][i] == '1')
			i++;
		else
			return(ft_printf("INVALID_MAP\nMap is not top closed!\n"), -1);
	}
	i = 0;
	while(check->matrix[check->count - 1][i] && check->matrix[check->count - 1][i] != '\n')
	{
		if(check->matrix[check->count - 1][i] == '1')
			i++;
		else
			return(ft_printf("INVALID_MAP\nMap is not bot closed!\n"), -1);
	}
	return(0);
}
int	lateral_wall(t_check *check) /// old
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(check->matrix[i])
	{
		if(check->matrix[i][0] != '1')
			return(ft_printf("INVALID_MAP\nMap is not left closed!\n"), -1);
		i++;
	}
	i = 0;
	while(check->matrix[0][j] && check->matrix[0][j] != '\n')
		j++;
	j -= 1;
	i = 0;
	while(check->matrix[i])
	{
		if(check->matrix[i][j] != '1')
			return(ft_printf("INVALID_MAP\nMap is not right closed!\n"), -1);
		i++;
	}
	return(0);
}

/* int lateral_wall(t_check *check)
{
    int i;
    int j;

    i = 0;
    while (check->matrix[i])
    {
        if (check->matrix[i][0] != '1')
            return (ft_printf("INVALID_MAP\nMap is not left closed!\n"), -1);
        i++;
    }

    i = 0;
    j = 0;
    while (check->matrix[0][j] && check->matrix[0][j] != '\n') // Correct the loop
        j++;
    j -= 1;

    i = 0;
    while (check->matrix[i])
    {
        if (check->matrix[i][j] != '1')
            return (ft_printf("INVALID_MAP\nMap is not right closed!\n"), -1);
        i++;
    }
    return (0);
} */


int	flag_char(t_check *check)
{
	int	i;
	int	j;

	i = 0;
	while (check->matrix[i])
	{
		j = 0;
		while(check->matrix[i][j])
		{
			if (check->matrix[i][j] != 'E' && check->matrix[i][j] != 'C' && check->matrix[i][j] != 'P' &&
				check->matrix[i][j] != '1' && check->matrix[i][j] != '0' && check->matrix[i][j] != '\n')
			{
				ft_printf("INVALID_MAP: Invalid character '%c' at row %d, col %d\n",  check->matrix[i][j], i, j);
				return(-1);
			}
			j++;
		}
		i++;
	}
	return(0);
}
