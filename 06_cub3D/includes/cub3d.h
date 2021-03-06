/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:03:30 by wopark            #+#    #+#             */
/*   Updated: 2021/04/14 13:53:23 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "opengl/mlx.h"
# include "mms/mlx.h"
# include "key.h"
# include "libft/libft.h"

typedef struct		s_img
{
	int				w;
	int				h;
	int				bpp;
	int				size_line;
	int				endian;
	void			*ptr;
	unsigned int	*addr;
	char			*path;
}					t_img;

typedef struct		s_vec
{
	double			x;
	double			y;
}					t_vec;

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			dist;
}					t_sprite;

typedef struct		s_player
{
	t_vec			pos;
	t_vec			dir;
	double			move_speed;
	double			rot_speed;
}					t_player;

typedef struct		s_sprites
{
	t_vec			sprt_pos;
	t_vec			transform;
	double			inv_det;

	int				scrn_x;
	int				sprt_h;
	int				sprt_w;
	int				draw_start_x;
	int				draw_start_y;
	int				draw_end_y;
	int				draw_end_x;

	int				tex_x;
	int				tex_y;
	int				dist;
	int				color;
}					t_sprites;

typedef struct		s_texture
{
	double			wall;
	double			step;
	double			tex_pos;

	int				color;
	int				tex_x;
	int				tex_y;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_texture;

typedef struct		s_screen
{
	int				width;
	int				height;
	int				col_size;
	int				row_size;
	t_player		p;
	t_vec			plane;

	double			*buffer;
	int				*sprite_idx;
	int				numofsprt;
	t_sprite		*sprite;

	t_texture		tex;

	double			scrn_x;
	double			dist_wall;
	t_vec			ray;
	t_vec			side;
	t_vec			delta;
	t_img			view;
	int				grid_x;
	int				grid_y;
	int				cell_x;
	int				cell_y;
	int				is_hit_side;
	int				is_hit_wall;
	char			**map_arr;

	void			*mlx;
	void			*win;
}					t_screen;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_bfs
{
	t_pos			cur;
	int				dx[4];
	int				dy[4];
	int				*chk;
	int				col;
	int				row;
	int				f;
	int				r;
	int				is_empty_player;
}					t_bfs;

typedef struct		s_color
{
	int				color;
	int				rgb;
	int				cnt;
	char			*tmp;
}					t_color;

typedef struct		s_gamedata
{
	t_screen		scrn;
	t_key			key;
	int				*north_img;
	int				*south_img;
	int				*east_img;
	int				*west_img;
	int				*sprite_img;
	int				ceil_color;
	int				floor_color;

	int				chk_parse[8];
	int				argc;

	int				fd;
	int				eof;
	int				chk_map_parse;
	char			*line;
	char			**res;
	t_list			*map_lst;
}					t_gamedata;

int					ft_exit(void);
int					cub3d(t_gamedata *d);
/*
** ------------------ valid_map.c -----------------------
*/
int					find_arguments(t_gamedata *d, t_bfs *a);
int					is_valid_map(t_gamedata *d);

/*
** ------------------ init_parse.c -----------------------
*/
void				init_bfs(t_gamedata *d, t_bfs *a);
void				init_gamedata(t_gamedata *d);
void				init_player(t_gamedata *d, t_bfs *a, int k);

/*
** ------------------ parse_gamedata_2.c -----------------------
*/
int					parse_map(char *line, t_list **map);
int					parse_color(char **res, t_gamedata *d, int n);
int					*parse_texture(t_gamedata *d, char **res, int n);

/*
** ------------------ parse_gamedata_1.c -----------------------
*/
int					parse_info(t_gamedata *d, char *line, char **res);
void				parse_gamedata(t_gamedata *d, char *path);

/*
** ------------------ parse_util.c -----------------------
*/
int					error_message(char *s, t_gamedata *d);
int					get_col_size(t_list *lst);
char				**lst2arr(t_gamedata *d, t_list *lst);
void				free_split(char **res);
void				free_gamedata(t_gamedata *d);

/*
** ------------------ vec.c -----------------------
*/
t_vec				new_vector(double x, double y);
t_vec				add_vector(t_vec a, t_vec b);
t_vec				sub_vector(t_vec a, t_vec b);
t_vec				mul_vector(t_vec v, double k);
t_vec				rot_vector(t_vec v, double rs);

/*
** ------------------ sprite.c -----------------------
*/
void				init_sprite(t_screen *s);
void				proc_sprite(t_screen *s, int *img);

/*
** ------------------ sprite_util.c -----------------------
*/
void				init_sprite(t_screen *s);
void				sort_sprite(t_screen *s);

/*
** ------------------ init.c -----------------------
*/
void				init_keys(t_key *key);
void				init_screen(t_screen *s);

/*
** ------------------ key_manage.c -----------------------
*/
int					key_pressed(int key, t_key *key_info);
int					key_released(int key, t_key *key_info);
void				manage_player(t_gamedata *d);

/*
** ------------------ ray_cast.c -----------------------
*/
void				loop_to_wall(t_screen *s);
void				draw_texture(t_screen *s, int *img, int x);
void				check_hit(t_gamedata *d, t_screen *s, int x);
void				proc_dda(t_screen *s, int x);
void				ray_cast(t_gamedata *d);

void				save_bitmap(t_gamedata *d);
int					chk_save_cmd(char **argv, t_gamedata *d);

int					mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
void				chk_cubfile(t_gamedata *d, char *s);

#endif
