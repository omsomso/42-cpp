NAME	=	ex04
CC 		=	c++
CFLAGS	=	-Werror -Wall -Wextra -std=c++98
SRC 	= 	main.cpp
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

run : $(NAME)
	@./$(NAME)

clean:
	@rm -f $(OBJ)
	@printf "[$(NAME)]$(GREEN) \t object files removed $(END)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "[$(NAME)]$(GREEN) \t $(NAME) removed $(END)\n"

re: fclean all
	@printf "[$(NAME)] $(GREEN) \t complete :) $(END)\n"