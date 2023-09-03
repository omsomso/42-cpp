NAME	=	megaphone
CC 		=	c++
CFLAGS	=	-Werror -Wall -Wextra -std=c++98
SRC 	= 	megaphone.cpp
OBJ		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	@$(CC) $(CFLAGS) -c $(SRC)
	@$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
	@printf "[$(NAME)] $(GREEN) \t re complete :) $(END)\n"