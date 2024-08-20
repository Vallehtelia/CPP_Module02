NAME = Fixed
SRC = main.cpp Fixed.cpp
OBJ = $(SRC:.cpp=.o)
COMPILER = c++
FLAGS = -Wall -Wextra -Werror
EXTRA_FLAGS = -std=c++98

all: $(NAME)

std98: FLAGS += $(EXTRA_FLAGS)
std98: re
	
$(NAME): $(OBJ)
	$(COMPILER) $(FLAGS) -o $@ $^

%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re std98