# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lomasse <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:24:01 by lomasse           #+#    #+#              #
#    Updated: 2019/01/31 13:51:16 by cbilga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= Wolf3D

SRC_PATH		= ./srcs/

SRCS			= $(shell ls $(SRC_PATH) | grep -E ".+\.c")

INC				= -I ./includes

LIB				= -L ./libft/

GCC				= gcc

FLAGS			= -Wall -Wextra -Werror

OBJS			= $(addprefix $(SRC_PATH), $(SRCS:.c=.o))

MAKELIB			= make re -C libft/

LIBFT			= -Llibft/ -lft

LIBMLX			= -L ./libui -lSDL2 -lSDL2_image -lSDL2_mixer

FRAME			= -framework OpenGL -framework AppKit

%.o: %.c ./includes/wolf3d.h
	@$(GCC) $(INC) -o $@ -c $<

$(NAME): $(OBJS)
	@$(GCC) -o $@ `sdl2-config --cflags --libs` $(OBJS) $(LIB) $(LIBFT) $(LIBMLX) $(FRAME) $(FLAGS)

all : $(NAME)
	

clean :
	@rm -rf $(OBJS) ; echo "Obj Cleaned"

fclean : clean
	@rm -rf $(NAME) ; echo "Exec Cleaned"

re : fclean all

relibft : 
	$(MAKELIB)

.PHONY : all clean fclean re
