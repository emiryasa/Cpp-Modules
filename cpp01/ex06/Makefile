NAME=harlFilter
SRC= main.cpp Sed.cpp
OBJ=$(SRC:.cpp=.o)
CPPFLAGS=-Wall -Wextra -Werror -std=c++98 -pedantic

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(CPPFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all