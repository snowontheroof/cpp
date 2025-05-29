NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror

SRC = megaphone.cpp

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

fclean:
	@rm -rf $(NAME)

re: fclean all

.PHONY: all fclean re
