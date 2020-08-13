NAME		= cub3D

INCLIB		= %%%%/minilibx-linux/lib

SRCS		=	pars_checks.c \
				utils_simple_functions.c \
				pars_init.c \
				pars_id_checks.c \
				pars_elements_check.c \
				pars_process_elements.c \
				pars_process_description.c \
				pars_get_elements.c \
				pars_map_to_tab.c \
				pars_str_to_lst.c \
				pars_process_player.c \
				pars_process_sprites.c \
				pars_map_check.c \
				disp_cub3d.c \
				disp_display.c \
				disp_sprites.c \
				disp_fill_background.c \
				disp_cast.c \
				disp_cast_hv.c \
				disp_cast_first_pnt.c \
				disp_cast_sprite.c \
				events_movements.c \
				events_turning.c \
				events_loop.c \
				events_bmp.c \

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
