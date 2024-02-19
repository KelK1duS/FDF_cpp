# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 13:46:39 by bedarenn          #+#    #+#              #
#    Updated: 2024/02/14 17:16:24 by bedarenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++

DIR_SRCS = srcs/
DIR_OBJS = objs/
DIR_INCL = headers/
DIR_LIBS = libs/

SRCS = \
	Pair.cpp \
	Mlx.cpp \
	Map.cpp \
	vector_Node.cpp \
	Map_calc.cpp \
	Node.cpp \
	Node_calc.cpp \
	Map_print.cpp \
	Point.cpp \
	Pixel.cpp \
	key_hook.cpp \
	main.cpp

OBJS = $(addprefix $(DIR_OBJS), $(SRCS:%.cpp=%.o))

CFLAGS = -std=c++17 -Wall -Wextra #-Werror -g
IFLAGS = -I$(DIR_INCL)
LFLAGS = -L$(DIR_LIBS) $(DIR_LIBS)libmlx.so -lSDL2 -lXext -lX11 -lm

NAME = fdf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ $(LFLAGS) -o $@

$(DIR_OBJS)%.o: $(DIR_SRCS)%.cpp
	@mkdir -p $(DIR_OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $^ -o $@

clean:
	rm -rf $(DIR_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: fclean
	$(CC) $(SRCS:%=$(DIR_SRCS)%) $(CFLAGS) $(IFLAGS) $(LFLAGS) -o $(NAME)

.PHONY: all clean fclean re
