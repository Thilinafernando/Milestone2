/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:39:51 by tkurukul          #+#    #+#             */
/*   Updated: 2025/01/22 17:51:11 by tkurukul         ###   ########.fr       */
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

void	free_mat(char **matrix, int j);
int	top_bot_wall(char **matrix, int count);
int	lateral_wall(char **matrix);
int	flag_char(char **matrix);
int	check_p_e(char **matrix);
int	check_c(char **matrix);
int	all_check(void);
char	**store(int count);
int	count_line(void);

#endif
