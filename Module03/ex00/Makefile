NAME = clapTrap

CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS_DIR = ./src/
OBJS_DIR = ./obj/
INC = ./includes/

SRCS = main.cpp

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

all: obj $(NAME)

obj:
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	$(CPP) $(CPPFLAGS) -I $(INC) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(OBJS) -o $@

clean:
	rm -rf obj $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean
	make all

.PHONY: re clean fclean all