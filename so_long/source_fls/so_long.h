/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:39:51 by tkurukul          #+#    #+#             */
/*   Updated: 2025/01/27 23:26:34 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define IMG_WIN mlx_put_image_to_window

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../libprintf/ft_printf.h"
# include <X11/keysymdef.h>
# include <X11/keysym.h>

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <ctype.h>
# include <errno.h>

typedef struct s_texture
{
	void	*mlx;
	int		height;
	int		width;
	void	*win_ptr;
	void	*player;
	void	*wall;
	void	*rocks;
	void	*coll;
	void	*groud;
	void	*exit;
	void	*sea;
	int		xu;
	int		yu;
	int		i;
	int		j;
}	t_texture;

typedef struct s_move
{
	int	xp;
	int	yp;
	int	xm;
	int	ym;
	int	nm;
}	t_move;

typedef struct s_check
{
	char	**matrix;
	char	**nmat;
	int		count;
	int		x;
	int		y;
	int		col;
	int		collect;
	int		exit;
	char	*arg;
}	t_check;

typedef struct s_game
{
	t_move		*m;
	t_check		*c;
	t_texture	*t;
}	t_game;

int		tryread(t_check *c);
int		ifber(char *ber);
void	free_mat(char **matrix);
int		top_bot_wall(t_check *check);
int		lateral_wall(t_check *check);
int		flag_char(t_check *check);
int		check_p_e(t_check *check);
int		check_c(t_check *check);
// int	all_check(t_check *check);
char	**store(t_check *check);
int		count_line(t_check	*check);
int		find_pos_x(t_check *check);
int		find_pos_y(t_check *check);
char	**dup_matrix(t_check *check);
int		validate_pos(int new_x, int new_y, t_check *c);
int		ft_backtracking(int x, int y, t_check *c);
int		validate_map(t_check *c);
int		check_all(t_check *check);
void	free_image(t_texture *text);
int		mlx_initialize(t_check *check, t_texture *text);
int		image_creation(t_check *check, t_texture *text);
void	free_all(t_check *check, t_texture *text);
void	image_insertion(t_check *check, t_texture *text);
void	image_insertion2(t_check *check, t_texture *text);
int		image_creation2(t_check *check, t_texture *text);
int		intake(int keycode, t_game *game);
void	mright(t_move *move, t_check *check, t_texture *text);
void	mleft(t_move *move, t_check *check, t_texture *text);
void	mdown(t_move *move, t_check *check, t_texture *text);
void	mup(t_move *move, t_check *check, t_texture *text);
int		click(t_game *game);
int		check_0(t_check *c);

#endif
