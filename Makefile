#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/13 11:21:19 by akryvenk          #+#    #+#              #
#    Updated: 2017/11/05 20:14:56 by mkyianyt         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_retro
FILE_SRCS = main.cpp \
			Enemies.cpp \
			AEntities.cpp \
			Bullets.cpp \
			Player.cpp \

FILE_O = $(FILE_SRCS:.cpp=.o)
OFLAGS = -Wall -Wextra -Werror -c
FLAGS = -lncurses
.PHONY:	all clean fclean re
OBJ = $(SRC:.cpp=.o)
all:	$(NAME_L) $(NAME)
$(NAME): $(FILE_O)
	@clang++  $(OFLAGS) $(FILE_SRCS)
	@clang++ -o $(NAME) $(FILE_O)  $(FLAGS)
clean:
	@/bin/rm -f $(FILE_O)
fclean: clean
	@/bin/rm -f $(NAME)
re: fclean all