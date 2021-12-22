# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 10:44:24 by fel-maac          #+#    #+#              #
#    Updated: 2021/12/16 10:44:39by fel-maac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c init/init_collectible.c init/init_game.c init/init_player.c init/init_tiles.c map/map_check.c map/map_split.c map/map_utils.c map/map_walls_check.c map/parse_map.c render/render_game.c render/render_map.c render/key_hooks.c

OBJ	= $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_LIB = -lmlx

FRAMEWORKS = -framework OpenGl -framework AppKit

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_LIB) $(FRAMEWORKS) -I.

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
