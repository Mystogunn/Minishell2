##
## Makefile for Makefile in /home/Mystogun/exopis
##
## Made by Josselin COSMAO
## Login   <Mystogun@epitech.net>
##
## Started on  Sat Oct 15 16:46:52 2016 Josselin COSMAO
## Last update Tue Apr  4 12:13:38 2017 Josselin
##

CC	= gcc

RM	= rm -rf

NAME	= mysh

SRCS	= main.c \
	  get_next_line.c \
	  my_str_to_wordtab.c \
	  my_function.c \
	  path.c \
	  my_exec.c \
	  my_cd.c \
	  my_setenv.c \
	  new_env.c \
	  doble_malloc.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	+=  -Wextra -Wall -g3 -Iinclude/

all:	$(NAME)

$(NAME): $(OBJS)
	 $(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
