NAME = a.out
SRCS = main.cpp
HEADER = set/set.hpp set/setit.hpp set/snode.hpp map/node.hpp map/bidit.hpp map/map.hpp stack/stack.hpp utils/tests.hpp utils/utils.hpp vector/ranit.hpp vector/vector.hpp
 
OBJS = $(SRCS:.cpp=.o)
CLANG = clang++ -g -Wall -Werror -Wextra -fsanitize=address #-std=c++98

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CLANG) $(OBJS) -o $(NAME)

$(OBJS): %.o : %.cpp
	$(CLANG) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re