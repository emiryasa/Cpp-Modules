NAME=megaphone
SRC=megaphone.cpp
OBJ=$(SRC:.cpp=.o)
CPPFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(CPPFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all