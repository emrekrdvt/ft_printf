NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC_FILES = ft_printf.c      \
			ft_printbasic.c
OBJ_FILES = $(SRC_FILES:.c=.o)
HEADER = ft_printf.h
RM = rm -rf
all:	$(NAME)
%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< 
$(NAME):	$(OBJ_FILES)
		ar crs $(NAME) $(OBJ_FILES)
clean:
	$(RM) $(OBJ_FILES)
fclean: clean
		$(RM) $(NAME)
re: fclean all
.PHONY: clean fclean re
