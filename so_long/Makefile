CC = cc

CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = mlx/libmlx.a -L/usr/lib/X11 -lXext -lX11

INCLUDES = -I/usr/include -Imlx -Iget_next_line -Ilibft -Ilibprintf

PRINTDIR = libprintf/
PRINT = $(PRINTDIR)libftprintf.a

LIBFTDIR = libft/
LIBFT = $(LIBFTDIR)libft.a

MLXDIR = mlx/
MLX = $(MLXDIR)libmlx.a

NAME = so_long
NAME_BONUS = so_long_bonus

GNL = get_next_line/
GNL_SRC = get_next_line.c get_next_line_utils.c
SRCDIR = source_fls/
SRC = source_fls/parsing.c checks.c the_call.c back_tracking.c textures.c movement.c free_all.c\
		back_tracking_2.c checks_2.c textures_2.c\

BONUSDIR = bonus/
BONUS = bonus/parsing_bonus.c checks_bonus.c the_call_bonus.c\
		back_tracking_bonus.c textures_bonus.c movement_bonus.c free_all_bonus.c\
		back_tracking_bonus_2.c checks_bonus_2.c textures_bonus_2.c

OBJ_DIR = obj

OBJECTS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
GNL_OBJECTS = $(addprefix $(OBJ_DIR)/, $(notdir $(GNL_SRC:.c=.o)))
OBJECT_BONUS = $(addprefix $(OBJ_DIR)/, $(notdir $(BONUS:.c=.o)))

all: $(NAME)

bonus:$(NAME_BONUS)

#normal program
$(NAME):  $(LIBFT) $(MLX) $(OBJECTS) $(GNL_OBJECTS) $(PRINT)
	$(CC) $(CFLAGS) $(OBJECTS) $(GNL_OBJECTS) -o  $(NAME) $(PRINT) $(LIBFT) $(MLX_FLAGS) $(MLX)

#Bonus
$(NAME_BONUS):  $(LIBFT) $(MLX) $(OBJECT_BONUS)  $(GNL_OBJECTS) $(PRINT)
	$(CC) $(CFLAGS) $(OBJECT_BONUS)  $(GNL_OBJECTS) -o $(NAME_BONUS) $(PRINT) $(MLX_FLAGS) $(LIBFT) $(MLX)

#Libft compiling
$(LIBFT): $(LIBFTDIR)
	@$(MAKE) -C $(LIBFTDIR) --quiet

#PRINTF compiling
$(PRINT): $(PRINTDIR)
	@$(MAKE) -C $(PRINTDIR) --quiet

#Object files
$(OBJ_DIR)/%.o: $(SRCDIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)


#Bonus
$(OBJ_DIR)/%.o: $(BONUSDIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJ_DIR)/%.o: $(GNL)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(MLX):
	@$(MAKE) -C $(MLXDIR)

clean:
		@$(MAKE) clean -C $(LIBFTDIR)
		@$(MAKE) clean -C $(MLXDIR)
		rm -rf $(OBJ_DIR)

fclean: clean
		@$(MAKE) fclean -C $(LIBFTDIR)
		rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all  bonus clean fclean re
