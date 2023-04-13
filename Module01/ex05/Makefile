NAME = harl2.0

CPP = c++
CPFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS_DIR = ./src/
OBJS_DIR = ./obj/

SRCS = main.cpp Harl.cpp
OBJS = $(addprefix $(OBJS_DIR),$(SRCS:.cpp=.o))

all: obj $(NAME)

obj:
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	$(CPP) $(CPPFLAGS) -I ./includes/ -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(OBJS) -o $(NAME)

clean:
	rm -rf obj $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean 
	make all

.PHONY: all clean fclean re