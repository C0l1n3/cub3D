SRCS	= ft_memset.c \
			ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memcpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memmove.c \
			ft_split.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_itoa.c \
			ft_strmapi.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_printf.c \
			ft_process.c \
			ft_print_ptr.c \
			ft_print_int.c \
			ft_print_hexa.c \
			ft_print_char_str.c \
			ft_printf_classics.c \
			ft_check_format.c \


BONUS	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS	= ${SRCS:.c=.o}

OBJSBONUS	= ${BONUS:.c=.o}

NAME	= libft.a

CC		= gcc

LIB		= ar rcs

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I includes

INCLUDES	= libft.h

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:		${OBJS} ${INCLUDES}
				${LIB} ${NAME} ${OBJS}
				ranlib ${NAME}

${OBJS}:		${INCLUDES}

${OBJSBONUS}:	${INCLUDES}

all:			${NAME}

bonus:			all ${OBJSBONUS}
				${LIB} ${NAME} ${OBJSBONUS}
				ranlib ${NAME}

clean:		
				${RM} ${OBJS} ${OBJSBONUS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re bonus
