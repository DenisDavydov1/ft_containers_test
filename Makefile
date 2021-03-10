NAME = ft_containers_test

HDR_CONTAINERS = containers

HDR_DIR = ./
HDR_LIST =	test.hpp test_utils.hpp
HDR = $(addprefix $(HDR_DIR), $(HDR_LIST))

SRC_DIR = ./
SRC_LIST =	main.cpp test_utils.cpp
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = ./obj/
OBJ_LIST = $(patsubst %.cpp, $(OBJ_DIR)%.o, $(SRC_LIST))

CL = clang++
FLAGS = -std=c++98 -Wall -Wextra -Werror
INCLUDE = -I$(HDR_DIR) -I$(HDR_CONTAINERS)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ_LIST)
	@$(CL) $(OBJ_LIST) -o $@ $(INCLUDE)
	@echo "$(NAME) created"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(SRC_DIR_SRCS)

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp $(HDR)
	@$(CL) $(FLAGS) -c $< -o $@ $(INCLUDE)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(OBJ_DIR) deleted"
	
fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) deleted"

re: fclean all
