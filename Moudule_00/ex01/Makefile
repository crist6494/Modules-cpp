NAME = phonebook

CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = phonebook.cpp contact.cpp main.cpp 
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:
	fclean all

.PHONY: all clean fclean re