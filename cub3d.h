/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:34:59 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/13 17:35:20 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include "/usr/include/x86_64-linux-gnu/bits/stdint-uintn.h"

typedef struct	s_chain
{
	char			*content;
	struct s_chain	*next;
}				t_chain;

typedef struct	s_img
{
	void				*img_ptr;
	int					*data;
	int					size_line;
	int					bpp;
	int					endian;
	int					height;
	int					width;
}				t_img;

typedef struct	s_sprite
{
	int					pos_x;
	int					pos_y;
	double				dist_to_player;
	double				start[2];
	double				middle[2];
	double				end[2];
	double				touch[2];
	double				pos_on_sprite;
	double				pixel;
	double				ht;
}				t_sprite;

typedef struct	s_player
{
	char			init_dir;
	int				grid_co[2];
	double			unit_co[2];
	int				new_grid_h_co[2];
	double			new_unit_h_co[2];
	double			h_dist;
	int				new_grid_v_co[2];
	double			new_unit_v_co[2];
	double			v_dist;
	double			closest[2];
	double			pos_on_wall;
	double			h_quotient[2];
	double			v_quotient[2];
	double			v_angle;
	double			o_angle;
	double			o_vector[2];
}				t_player;

typedef struct	s_win
{
	void			*mlx_ptr;
	void			*game_ptr;
	void			*map_ptr;
	t_img			base;
	int				r_width;
	int				r_height;
	int				color;
	int				block_size;
	char			*error;
}				t_win;

typedef struct	s_game
{
	int				bpp;
	int				size_line;
	int				endian;
	double			dist_to_plane;
	double			sub_angle;
	double			ignore_angle[8];
	t_player		player;
	int				key[7];
	double			coef[4];
}				t_game;

typedef struct	s_map
{
	char			*map_file;
	int				m_width;
	int				m_height;
	int				fd;
	int				perso;
	char			**text;
	t_img			tex[5];
	t_sprite		*sprites;
	int				sp_nb;
	int				c_color;
	int				f_color;
	t_chain			*map_lines;
	int				**map_tab;
	int				x;
	int				y;
}				t_map;

typedef struct	s_cub
{
	t_win			win;
	t_map			map;
	t_game			game;
}				t_cub;

int				mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

/*
** pars_checks
*/

int				extension(char *str);
int				ft_error(int code, int line, char *id, t_cub *cub);
int				ft_error_two(int code, t_cub *cub);
void			ft_free_cub(t_cub *cub);
int				check_screen_size(t_cub *cube);

/*
** pars_elements_check
*/

int				check_format_rgb(char *line);
int				check_texture_path(char *path);

/*
** pars_id_checks
*/

int				check_multiple_id(char id, t_cub *cub);
int				missing_id(t_cub *cub);
int				check_is_id(char *line, t_cub *cub);
int				check_all_info(char **line, t_cub *cub);
void			fill_error(t_cub *cub, char id);

/*
** pars_map_check
*/

int				check_map(int **map, int height, int width, t_cub *cub);
int				ischarmap(char c);
int				check_char_map(int **map, int height, int width);
int				check_leak_map(int **map, int height, int width);
int				check_player(int **map, int height, int width);

/*
** pars_get_elements
*/

int				get_elements(t_cub *cub);
int				ismapline(char *line);
int				get_id(char *line, t_cub *cub, int line_num);
int				get_info(char *line, t_cub *cub, int line_num);

/*
** pars_process_elements
*/

int				process_res(char *line, int i, t_cub *cub, int l);
int				process_texture(char *line, int i, t_cub *cub, int l);
int				process_color(char *line, int i, t_cub *cub, int l);
void			fill_color(char c, t_cub *cub, int *rgb);
int				find_dir(char *line, int i);

/*
** utils_simple_functions
*/

int				mini_atoi(char *line, int *i);
int				ft_rgb_to_int(int a, int b, int c);
double			degree_to_radian(double degree);
double			ft_abs(double x);
double			dist_two_pts(double a_x, double a_y, double b_x, double b_y);

/*
** pars_process_description
*/

int				get_map(t_cub *cub);
void			get_dimension(t_cub *cub);

/*
** pars_init
*/

void			init_window(t_cub *cub);
void			init_map(t_cub *cub);
void			init_game(t_cub *cub);
void			init_struct(t_cub *cub);
void			free_safe(void **ptr);

/*
** pars_str_to_lst
*/

t_chain			*lstcharnew(char *content);
t_chain			*lstcharlast(t_chain *lst);
void			lstcharadd_back(t_chain **alst, t_chain *new);
void			free_lstchar(t_chain *lst);

/*
** disp_display
*/

int				fill_walls(t_cub *cub);
int				find_wall_dir(t_cub *cub);
void			process_sub_angle(t_cub *cub, int i);
int				fill_ray(t_cub *cub, int i, int d, double wall);

/*
** disp_fill_background
*/

void			fill_background(t_cub *cub);

/*
** pars_map_to_tab
*/

int				**lst_to_int(t_cub *cub);
void			fill_tab(int **tab, t_cub *cub);
void			finish_filling(int **tab, int *i, int j, t_cub *cub);
int				char_to_int(char c);

/*
** pars_process_player
*/

void			process_player(t_cub *cub, int x, int y, char letter);
void			process_o_angle(t_cub *cub, char letter);

/*
** pars_process_sprites
*/

void			sort_sprites(t_cub *cub);
int				process_sprites(t_cub *cub);
void			process_pos_sprites(int	nb, int x, int y, t_cub *cub);

/*
** disp_sprites
*/

void			touch_sprite(t_cub *cub, int i, double *pnt);
void			display_ray_sprite(t_cub *cub, t_sprite sprite, int i);
void			fill_ray_sprite(t_cub *cub, double *ratio, int i,
t_sprite sprite);

/*
** disp_cast_sprite
*/

double			notable_cases(double *pnt, t_cub *cub, int nb);
double			notable_cases_two(double *pnt, t_cub *cub, int nb,
double *coef);
double			cast_common_x(double *coef, double *pnt, t_cub *cub, int nb);
void			dist_to_sprite(t_cub *cub, int nb, double *pnt, double *coef);
void			process_coef(t_cub *cub, double *pnt, int nb);

/*
** disp_cast
*/

double			cast(t_cub *cub);
void			dist_wall(t_cub *cub);
int				is_empty(t_cub *cub, int x, int y);
int				is_vertical_angle(t_cub *cub, double angle);
int				is_horizontal_angle(t_cub *cub, double angle);

/*
** disp_cast_hv
*/

void			add_v_quotient(t_cub *cub, int a);
void			add_h_quotient(t_cub *cub, int a);
void			find_horizontal(t_cub *cub);
void			find_vertical(t_cub *cub);

/*
** disp_cast_first_pnt
*/

void			find_first_vpoint(t_cub *cub);
void			find_first_hpoint(t_cub *cub);
void			first_xh(t_cub *cub, double *angle);
void			first_xv(t_cub *cub, double *angle);
void			find_ignore_angle(t_cub *cub);

/*
** events_movements
*/

void			move_forward(t_cub *cub);
void			move_backward(t_cub *cub);
void			move_left(t_cub *cub);
void			move_right(t_cub *cub);
void			add_value(t_cub *cub, double angle, int a, int b);

/*
** events_turning
*/

void			cub_turn(t_cub *cub, char side);

/*
** events_bmp
*/

void			create_header(t_cub *cub, int fd);
int				create_bmp(t_cub *cub);
void			fill_bits(t_cub *cub, int fd);
void			convert_bits(uint8_t *header, long int data);
void			destroy_images(t_cub *cub);

/*
** events_loop
*/

int				looping(t_cub *cub);
int				process_key(t_cub *cub);
int				deal_key(int key, t_cub *cub);
int				deal_key_release(int key, t_cub *cub);
int				proper_exit(t_cub *param);

/*
** disp_cube3d
*/

int				ft_cub(t_cub *cub);
int				create_img(t_cub *cub);
int				get_textures(t_cub *cub);
int				load_img(t_cub *cub, char *path, t_img *img);

#endif
