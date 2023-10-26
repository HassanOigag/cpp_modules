CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = phonebook

SRCS = Contact.cpp main.cpp PhoneBook.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) Contact.hpp PhoneBook.hpp
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

run: all
	./$(NAME)

re: fclean all

.PHONY: all clean fclean re
