NAME = base

CPP = c++
CPPFLAGS = -g -Wall -Werror -Wextra -std=c++98

SRCS_DIR = ./src/
OBJS_DIR = ./obj/
INC = ./includes/

SRCS = $(wildcard $(SRCS_DIR)*.cpp)

OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.cpp=.o)))

all: obj $(NAME)

obj:
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@$(CPP) $(CPPFLAGS) -I $(INC) -c $< -o $@

$(NAME): $(OBJS)
	@$(CPP) $(OBJS) -o $(NAME)

clean:
	@rm -rf obj $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean
	@make all

val: all
	valgrind --leak-check=full ./$(NAME)
	rm -rf $(NAME).dSYM

r: re
	@./$(NAME)

.PHONY: all re fclean clean