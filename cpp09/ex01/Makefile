NAME	=	RPN
SRC 	= 	main.cpp RPN.cpp

CC 		=	c++
CFLAGS	=	-Werror -Wall -Wextra -std=c++98 -g3
OBJ		=	$(SRC:.cpp=.o)

GREEN	=	\033[0;32m
RED		=	\033[0;31m
BLUE	=	\033[0;34m
ORANGE	=	\033[33m
GREY	=	\033[90m
END		=	\033[0m

MSGOBJ=@printf "$(END)$(GREEN)creating object files...$(GREY)\n"
MSGEXE=@printf "$(END)$(GREEN)creating executable...$(GREY)\n"
MSGRUN=@printf "$(END)$(GREEN)running executable$(END)\n"
MSGRES=@printf "$(END)$(GREEN)recompiling...$(END)\n"
MSGREC=@printf "$(END)$(GREEN)complete :)$(END)\n"

all: $(NAME)

$(NAME): $(OBJ)
	$(MSGEXE)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(MSGOBJ)
	$(CC) -c $(CFLAGS) $< -o $@

run: $(NAME)
	$(MSGRUN)
	./$(NAME) "7 7 * 7 -"
	./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	./$(NAME) "( 1 + 1 )"
	./$(NAME) "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /"
	./$(NAME) "2 0 /"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean msgres all 
	$(MSGREC)

msgres:
	$(MSGRES)