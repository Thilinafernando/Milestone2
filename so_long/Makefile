CC = cc

CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = mlx/libmlx.a -L/usr/lib/X11 -lXext -lX11

INCLUDES = -I/usr/include -Imlx -Iget_next_line -Ilibft -Ilibprintf

PRINTDIR = libprintf/
PRINT = $(PRINTDIR)libftprintf.a

LIBFTDIR = libft/
LIBFT = $(LIBFTDIR)libft.a

NAME = so_long.a
NAME_BONUS = so_long_bonus.a

GNL = get_next_line/
GNL_SRC = get_next_line.c get_next_line_utils.c
SRCDIR = source_fls/
SRC = parsing.c utils.c checks.c the_call.c back_tracking.c

BONUSDIR = bonus/
BONUS =

OBJ_DIR = obj

OBJECTS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJECT_BONUS = $(addprefix $(OBJ_DIR)/, $(BONUS:.c=.o))
GNL_OBJECTS = $(addprefix $(OBJ_DIR)/, $(GNL_SRC:.c=.o))

all: $(NAME)

bonus:$(NAME_BONUS)

#normal program
$(NAME):  $(LIBFT) $(OBJECTS) $(GNL_OBJECTS) $(PRINT)
	$(CC) $(CFLAGS) $(OBJECTS) $(GNL_OBJECTS) -o  $(NAME) $(PRINT) $(LIBFT) $(MLX_FLAGS)

#Bonus
$(NAME_BONUS):  $(LIBFT) $(BONUS_OBJECTS)  $(GNL_OBJECTS) $(PRINT)
	$(CC) $(CFLAGS) $(OBJECT_BONUS)  $(GNL_OBJECTS) -o $(NAME_BONUS) $(PRINT) $(MLX_FLAGS) $(LIBFT)

#Libft compiling
$(LIBFT): $(LIBFTDIR)
	@$(MAKE) -C $(LIBFTDIR)

#PRINTF compiling
$(PRINT): $(PRINTDIR)
	@$(MAKE) -C $(PRINTDIR)

#Object files
$(OBJ_DIR)/%.o: %.c
		mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

#Bonus
$(OBJ_DIR)/%.o: $(BONUSDIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJ_DIR)/%.o: $(GNL)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
		@$(MAKE) clean -C $(LIBFTDIR)
		rm -rf $(OBJ_DIR)

fclean: clean
		@$(MAKE) fclean -C $(LIBFTDIR)
		rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all  bonus clean fclean re
