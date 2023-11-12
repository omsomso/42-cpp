NAME	=	PmergeMe
SRC 	= 	main.cpp PmergeMe.cpp PmergeMeParse.cpp PmergeMeUtils.cpp

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
	./$(NAME) 12 11 4 13 5 6 7 312 4
	@printf "\n"
	./$(NAME) 4 19 40 479 12 70 1 3 0 28 02 8 34 95 105 652 888 -6
	@printf "\n"
#	./$(NAME) `jot -r 3000 1 100000 | tr '\n' ' '`
#	@printf "\n"
#	./$(NAME) `jot -r 10000 1 1000000 | tr '\n' ' '`
#	@printf "\n"
	./$(NAME) 1 2 3 4

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean msgres all 
	$(MSGREC)

msgres:
	$(MSGRES)