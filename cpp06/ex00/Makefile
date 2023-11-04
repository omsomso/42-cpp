NAME	=	convert
CC 		=	c++
CFLAGS	=	-Werror -Wall -Wextra -std=c++98
SRC 	= 	main.cpp ScalarConverter.cpp
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
	@printf "[$(NAME)]$(GREEN) \t running executable $(END)\n"
	./$(NAME) a
	@printf "\n"
	./$(NAME) 42.0
	@printf "\n"
	./$(NAME) 42.2f
	@printf "\n"
	./$(NAME) -58
	@printf "\n"
	./$(NAME) -123817625
	@printf "\n"
	./$(NAME) 327865823765827365738256.23576
	@printf "\n"
	./$(NAME) 327865823765827365738253427649832749283498237472
	@printf "\n"
	./$(NAME) +inf
	@printf "\n"
	./$(NAME) +inff
	@printf "\n"
	./$(NAME) -inf
	@printf "\n"
	./$(NAME) -inff
	@printf "\n"
	./$(NAME) nan
	@printf "\n"
	./$(NAME) nanf

clean:
	@rm -f $(OBJ)
	@printf "[$(NAME)]$(GREEN) \t object files removed $(END)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "[$(NAME)]$(GREEN) \t $(NAME) removed $(END)\n"

re: fclean all
	@printf "[$(NAME)] $(GREEN) \t complete :) $(END)\n"