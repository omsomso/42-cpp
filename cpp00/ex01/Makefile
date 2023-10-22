NAME	=	phonebook
CXX		=	c++
CXFLAGS	=	-Werror -Wall -Wextra -std=c++98 -pedantic
SRC 	= 	phonebook.cpp contact.cpp
OBJ		=	$(SRC:.cpp=.o)

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	$(CXX) $(CXFLAGS) -c $(SRC)
	@$(CXX) $(OBJ) -o $(NAME)

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