NAME = a.out # rename it
SRCS = main.cpp
HEADER = vector.hpp ranit.hpp iter.hpp utils.hpp tests.hpp pair.hpp bidit.hpp rbtree.hpp
 
OBJS = $(SRCS:.cpp=.o)
CLANG = clang++ -std=c++98 -fsanitize=address
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