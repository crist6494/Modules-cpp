NAME = maggots

CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS_DIR = ./src/
OBJS_DIR = ./obj/
INC = ./includes/

SRCS = $(wildcard $(SRCS_DIR)*.cpp)

OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.cpp=.o)))

all: obj $(NAME)

obj:
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp #patron representa todos archivos .o
	@$(CPP) $(CPPFLAGS) -I $(INC) -c $< -o $@

$(NAME): $(OBJS)
	@$(CPP) $(OBJS) -o $(NAME)

clean:
	@rm -rf obj *_shrubbery $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean
	@make all

r: re
	@./$(NAME)

.PHONY: all re fclean clean