NAME	=	btc
SRC 	= 	main.cpp BitcoinExchange.cpp

CC 		=	c++
CFLAGS	=	-Werror -Wall -Wextra -std=c++98 -g3
OBJ		=	$(SRC:.cpp=.o)

GREEN	=	\033[0;32m
RED		=	\033[0;31m
BLUE	=	\033[0;34m
ORANGE	=	\033[33m
GREY	=	\033[90m
END		=	\033[0m

MSGFIL=@printf "$(END)$(GREEN)preparing database...$(GREY)\n"
MSGOBJ=@printf "$(END)$(GREEN)creating object files...$(GREY)\n"
MSGEXE=@printf "$(END)$(GREEN)creating executable...$(GREY)\n"
MSGRUN=@printf "$(END)$(GREEN)running executable$(END)\n"
MSGRES=@printf "$(END)$(GREEN)recompiling...$(END)\n"
MSGREC=@printf "$(END)$(GREEN)complete :)$(END)\n"

all: $(NAME)

$(NAME): $(OBJ)
	$(MSGEXE)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	$(MSGFIL)
	curl https://cdn.intra.42.fr/document/document/20227/cpp_09.tgz --output cpp_09.tgz
	tar -xf cpp_09.tgz
	mv cpp_09/data.csv .
	rm -rf cpp_09 cpp_09.tgz

%.o : %.cpp
	$(MSGOBJ)
	$(CC) -c $(CFLAGS) $< -o $@

run: $(NAME)
	$(MSGRUN)
	./$(NAME) query
	@printf "\n"
	./$(NAME) input.txt

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) data.csv

re: fclean msgres all 
	$(MSGREC)

msgres:
	$(MSGRES)