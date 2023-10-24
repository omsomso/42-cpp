NAME	=	megaphone
CC 		=	c++
CFLAGS	=	-Werror -Wall -Wextra -std=c++98
SRC 	= 	megaphone.cpp
OBJ		=	$(SRC:.cpp=.o)

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@printf "[$(NAME)]$(GREEN) \t creating executable... $(END)\n"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	@printf "[$(NAME)]$(GREEN) \t creating object files... $(END)\n"
	$(CC) -c $(CFLAGS) $< -o $@

run: $(NAME)
	@printf "[$(NAME)]$(GREEN) \t running executable $(END)\n"
	./$(NAME) "shhhhh... I think the students are asleep..."
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	./$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
	@printf "[$(NAME)] $(GREEN) \t re complete :) $(END)\n"