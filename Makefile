# Main var
NAME = ft_ls

# GCC
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes/ -I libft/includes

# Sources & Objects
SRCS = 	srcs/main.c \
		srcs/list_files.c \
		srcs/list_controller.c \

OBJS_PATH = objs/
OBJS = $(patsubst srcs/%.c,$(OBJS_PATH)%.o, $(SRCS))

# Includes
LIBFT = libft/
INCLUDES = -L libft/ -lft
# Utils
RM = rm -rf
SHELL = /bin/zsh

# Compiling & other stuff

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	@make -C $(LIBFT)
	@echo -n "\e[1;36m Compiling $@...\e[0m"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDES)
	@echo "\e[1;32mOK!\e[0m"

$(OBJS_PATH)%.o : srcs/%.c
	@mkdir -p $(OBJS_PATH)
	@echo -n "\e[1;36m Compiling $<...\e[0m "
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\e[1;32mOK!\e[0m"

clean :
	@make clean -C $(LIBFT)
	@$(RM) $(OBJS_PATH)
	@echo "\e[1;33m Cleaning objects. \e[0m"

fclean : clean
	@make fclean -C $(LIBFT)
	@$(RM) $(NAME)
	@echo "\e[1;33m Cleaning $(NAME). \e[0m"

re : fclean all

.PHONY : all clean fclean re
