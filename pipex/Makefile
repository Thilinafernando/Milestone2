CC = cc

CFLAGS = -Wall -Wextra -Werror -g

INCLUDES = -I/usr/include -Imlx -Iget_next_line -Ilibft -Ilibprintf

PRINTDIR = libprintf/
PRINT = $(PRINTDIR)libftprintf.a

LIBFTDIR = libft/
LIBFT = $(LIBFTDIR)libft.a

NAME = pipex
# NAME_BONUS =

GNL = get_next_line/
GNL_SRC = get_next_line.c get_next_line_utils.c
SRCDIR = source/
SRC = source/pipex.c

BONUSDIR = bonus/
BONUS = bonus/

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
# $(NAME_BONUS):  $(LIBFT) $(MLX) $(OBJECT_BONUS)  $(GNL_OBJECTS) $(PRINT)
# $(CC) $(CFLAGS) $(OBJECT_BONUS)  $(GNL_OBJECTS) -o $(NAME_BONUS) $(PRINT) $(MLX_FLAGS) $(LIBFT) $(MLX)

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
# $(OBJ_DIR)/%.o: $(BONUSDIR)%.c
# mkdir -p $(OBJ_DIR)
# $(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJ_DIR)/%.o: $(GNL)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
		@$(MAKE) clean -C $(LIBFTDIR)
		rm -rf $(OBJ_DIR)

fclean: clean
		@$(MAKE) fclean -C $(LIBFTDIR)
		rm -rf $(NAME)

re: fclean all

.PHONY: all  bonus clean fclean re
