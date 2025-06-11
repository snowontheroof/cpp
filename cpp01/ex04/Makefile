NAME = Replacer
CC = c++
FLAGS = -Wall -Wextra -Werror

SRC = main.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) -o $(NAME) $(SRC)

clean:
	@echo "clean: Nothing to clean."

fclean:
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
