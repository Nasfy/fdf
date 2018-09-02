# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/07 18:50:03 by abiriuk           #+#    #+#              #
#    Updated: 2018/09/02 17:26:31 by abiriuk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re $(NAME) $(LFT)

NAME=fdf
CC=gcc
CFLAG=-Wall -Wextra -Werror -I$(LFTPATH) -I/usr/local/include -I./
LFTPATH=libft/
LFTFILE=libft.a
LFT=$(addprefix $(LFTPATH), $(LFTFILE))
SRC=main.c line.c parsing.c test.c global_list.c center.c movement.c \
	key_move.c min_max.c zoom.c xy_rotation.c rotation.c start_view.c \
	move_xy_move.c copy_list.c
SRCS=$(addprefix src/, $(SRC))
OBJ=$(SRCS:.c=.o)

MLX=-L /usr/local/lib -lmlx -framework OpenGL -framework AppKit 

all: $(NAME)

$(NAME): $(OBJ) $(LFT)
	$(CC) $(CFLAG) -L$(LFTPATH) -lft $^ -o $@ $(MLX)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

$(LFT):
	$(MAKE) -C $(LFTPATH)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LFTPATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LFTPATH) fclean

re: fclean all
