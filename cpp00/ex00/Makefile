# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpawlows <kpawlows@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 04:21:35 by kpawlows          #+#    #+#              #
#    Updated: 2023/09/02 01:12:16 by kpawlows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone
CC 		=	c++
CFLAGS	=	-Werror -Wall -Wextra -std=c++98
SRC 	= 	megaphone.cpp
OBJ		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	@$(CC) $(CFLAGS) -c $(SRC)
	@printf "[$(NAME)]$(GREEN) \t $? updated $(END)\n"
	@$(CC) $(OBJ) -o $(NAME)
	@printf "[$(NAME)]$(GREEN) \t $(NAME) created $(END)\n"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
	@printf "[$(NAME)] $(GREEN) \t re complete :) $(END)\n"