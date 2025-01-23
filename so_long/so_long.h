/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:39:51 by tkurukul          #+#    #+#             */
/*   Updated: 2025/01/23 18:04:24 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./mlx/mlx_int.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./libprintf/ft_printf.h"


# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <ctype.h>
# include <errno.h>

typedef struct s_check
{
	char	**matrix;
	int		count;
	int		x;
	int		y;
	int		col;
	int		collect;
	int		exit;
} t_check;

void	free_mat(char **matrix, int j);
int	top_bot_wall(t_check *check);
int	lateral_wall(t_check *check);
int	flag_char(t_check *check);
int	check_p_e(t_check *check);
int	check_c(t_check *check);
// int	all_check(t_check *check);
char	**store(t_check *check);
int	count_line(void);
int	find_pos_x(t_check *check);
int find_pos_y(t_check *check);
char	**dup_matrix(t_check *check);
int	validate_pos(char **nmatrix, int new_x, int new_y, t_check *check);
int	ft_backtracking(char **nmatrix, t_check *check);
int	validate_map(char **nmatrix, t_check *check);


#endif
