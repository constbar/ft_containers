NAME = a.out # rename it // delete unnesses hpp s
SRCS = main.cpp
HEADER = set/set.hpp set/setit.hpp set/snode.hpp
# HEADER = map/node.hpp map/bidit.hpp map/map.hpp stack/stack.hpp utils/tests.hpp utils/utils.hpp vector/ranit.hpp vector/vector.hpp
 
OBJS = $(SRCS:.cpp=.o)
CLANG = clang++ -g #-fsanitize=address #-Wall -Werror -Wextra
# CLANG = clang++ -std=c++98 -fsanitize=address
# CLANG = clang++ -std=c++98 #-Wall -Werror -Wextra -fsanitize=address

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