NAME		= cub3D

INCLIB		= %%%%/minilibx-linux/lib

SRCS		=	srcs/pars_checks.c \
				srcs/utils_simple_functions.c \
				srcs/pars_init.c \
				srcs/pars_id_checks.c \
				srcs/pars_elements_check.c \
				srcs/pars_process_elements.c \
				srcs/pars_process_description.c \
				srcs/pars_get_elements.c \
				srcs/pars_map_to_tab.c \
				srcs/pars_str_to_lst.c \
				srcs/pars_process_player.c \
				srcs/pars_process_sprites.c \
				srcs/pars_map_check.c \
				srcs/disp_cub3d.c \
				srcs/disp_display.c \
				srcs/disp_sprites.c \
				srcs/disp_fill_background.c \
				srcs/disp_cast.c \
				srcs/disp_cast_hv.c \
				srcs/disp_cast_first_pnt.c \
				srcs/disp_cast_sprite.c \
				srcs/events_movements.c \
				srcs/events_turning.c \
				srcs/events_loop.c \
				srcs/events_bmp.c \

INCLUDES	= cub3d.h

CC			= clang

FRAMEWORK 	= -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx_Linux -L$(INCLIB) -lXext -lX11 -lm -lbsd

CFLAGS		= -Wall -Wextra -Werror -g3 -flto -O3 -march=native -ffast-math

MAKE		= make

LIBFT_PATH	= ./libft/

MLX_PATH	= ./minilibx-linux/

LIBFT		= $(LIBFT_PATH)/libft.a

MLX			= $(MLX_PATH)/libmlx_Linux.a

OBJS		= ${SRCS:%.c=%.o}

%.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

all			:	lib ${NAME}

$(NAME)		: ${OBJS}
	$(CC) $(CFLAGS) -I./  $(OBJS) main.c -o $(NAME) $(FRAMEWORK)

#bonus    : all

lib			:
	$(MAKE) -C $(LIBFT_PATH)
	$(MAKE) -C $(MLX_PATH)

clean		:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean
	rm -f $(OBJS)

fclean		: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re			: fclean all

PHONY		: all clean fclean bonus comp re
