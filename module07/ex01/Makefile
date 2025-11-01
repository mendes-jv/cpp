NAME		= ./iter

CC			= c++

CFLAGS		= -Wall -Wextra -Werror -Wunreachable-code -std=c++98

FILES		= main

SRC_DIR 	= sources/

SRC_FILES	= $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES)))

OBJ_DIR		= objects/

OBJ_FILES	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

INCLUDES	= -I ./includes/

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_FILES) -o $@

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re