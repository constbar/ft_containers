NAME = a.out # rename it // delete unnesses hpp s
SRCS = main.cpp
HEADER = node.hpp iter.hpp map.hpp

# HEADER = vector.hpp ranit.hpp iter.hpp utils.hpp pair.hpp bidit.hpp rbtree.hpp node.hpp map.hpp
# HEADER = vector/vector.hpp vector/ranit.hpp stack/stack.hpp						utils/utils.hpp utils/pair.hpp utils/tests.hpp
#  iter.hpp utils.hpp pair.hpp bidit.hpp rbtree.hpp node.hpp map.hpp
 
OBJS = $(SRCS:.cpp=.o)
CLANG = clang++
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