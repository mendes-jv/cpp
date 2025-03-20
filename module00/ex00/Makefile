NAME	= megaphone

CC		= c++

CFLAGS	= -Wall -Wextra -Werror -Wunreachable-code -std=c++98

FILE	= $(addsuffix .cpp, $(NAME))

OBJ		= $(FILE:%.cpp=$(OBJ_DIR)%.o)

OBJ_DIR	= objects/

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJ_DIR)%.o:%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re