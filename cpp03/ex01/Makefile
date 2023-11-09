NAME	=	ex01
CC 		=	c++
CFLAGS	=	-Werror -Wall -Wextra -std=c++98
SRC 	= 	main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ		=	$(SRC:.cpp=.o)

GREEN	=	\033[0;32m
RED		=	\033[0;31m
BLUE	=	\033[0;34m
ORANGE	=	\033[33m
GREY	=	\033[90m
END		=	\033[0m

MSGOBJ=@printf "$(GREY)"
MSGEXE=@printf "$(END)[$(NAME)]$(GREEN) creating executable...$(GREY)\n"
MSGRUN=@printf "$(END)[$(NAME)]$(GREEN) running executable$(END)\n"
MSGRES=@printf "$(END)[$(NAME)]$(GREEN) recompiling...$(END)\n"
MSGREC=@printf "$(END)[$(NAME)]$(GREEN) complete :)$(END)\n"

all: $(NAME)

$(NAME): $(OBJ)
	$(MSGEXE)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(MSGOBJ)
	$(CC) -c $(CFLAGS) $< -o $@

run: $(NAME)
	$(MSGRUN)
	./$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
	$(MSGREC)

msgres:
	$(MSGRES)