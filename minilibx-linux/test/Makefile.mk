
SHELL			=	/bin/bash

INC=%%%%

INCLIB=$(INC)/../lib

CC=gcc

CFLAGS= -I$(INC) -O3 -I..

NAME= mlx-test
SRC = main.c
OBJ = $(SRC:.c=.o)

ERASE	= \033[2K\r
BLUE	= \033[36m
WHITE	= \033[37m
END		= \033[0m
GREEN	= \033[0;32m
RED		= \033[0;31m
YELLOW	= \033[0;33m

all	:$(NAME)


%.o: %.c $(INCLIB)
	@$(CC) -Wno-everything -Wno-implicit-function-declaration -Wno-unused-result $(CFLAGS) -c $< -o $@
	@printf "\x1b[48;2;0;200;0m \x1b[0m"


$(NAME)	: $(OBJ)
	@$(CC) -Wno-everything -Wno-implicit-function-declaration -Wno-unused-result -o $(NAME) $(OBJ) -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd

clean	:
	@rm -f $(NAME) $(OBJ) *~ core *.core


re	: clean all
