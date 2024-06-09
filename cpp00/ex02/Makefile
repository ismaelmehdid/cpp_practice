NAME = bank

SRCS = Account.cpp tests.cpp

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[92mCompiled: $<\033[0m"

clean:
	$(RM) $(OBJS)
	@echo "\033[93mObject files cleaned.\033[0m"

fclean: clean
	$(RM) $(NAME)
	@echo "\033[93mExecutable removed.\033[0m"

re: fclean all

.PHONY: all clean fclean re
