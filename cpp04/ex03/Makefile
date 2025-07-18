NAME = MateriaSource
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

INC_DIR = inc/
SRC_DIR = src/
OBJ_DIR = obj/

INC_FILES = AMateria.hpp Ice.hpp Cure.hpp Character.cpp MateriaSource.hpp
SRC_FILES = main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp
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
