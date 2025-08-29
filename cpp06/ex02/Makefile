NAME = identify
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++20

INC_DIR = inc/
SRC_DIR = src/
OBJ_DIR = obj/

INC_FILES = Base.hpp A.hpp B.hpp C.hpp
SRC_FILES = main.cpp Base.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

INC = $(addprefix $(INC_DIR), $(INC_FILES))
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp $(INC)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re
