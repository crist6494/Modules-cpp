NAME	=	brain

CPP = c++
CPFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o : %.cpp
	$(CPP) $(CPFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CPP) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:
	fclean all

.PHONY: all clean fclean re