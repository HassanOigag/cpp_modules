CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g

NAME = amateria

SRCS = AMateria.cpp Cure.cpp Ice.cpp main.cpp LinkedList.cpp Character.cpp MateriaSource.cpp

HEADERS = AMateria.hpp Cure.hpp Ice.hpp ICharacter.hpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re
