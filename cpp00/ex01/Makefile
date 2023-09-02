# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 05:36:48 by kpawlows          #+#    #+#              #
#    Updated: 2023/03/09 05:37:00 by kpawlows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook
CC 		=	c++
CFLAGS	=	-Werror -Wall -Wextra -std=c++98
SRC 	= 	phonebook.cpp
OBJ		=	$(SRC:.cpp=.o)

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	@$(CC) $(CFLAGS) -c $(SRC)
	@printf "[$(NAME)]$(GREEN) \t $? updated $(END)\n"
	@$(CC) $(OBJ) -o $(NAME)
	@printf "[$(NAME)]$(GREEN) \t $(NAME) created $(END)\n"

clean:
	@rm -f $(OBJ)
	@printf "[$(NAME)]$(GREEN) \t .o removed $(END)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "[$(NAME)]$(GREEN) \t $(NAME) removed $(END)\n"

re: fclean all
	@printf "[$(NAME)] $(GREEN) \t re complete :) $(END)\n"