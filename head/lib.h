/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 21:04:50 by schabaud          #+#    #+#             */
/*   Updated: 2016/12/03 14:51:43 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <math.h>
# include <stdlib.h>
# include <sys/time.h>
# include "libft.h"
# include "mlx.h"
# define HEIGHT 720
# define WIDTH 1280
# define TITLE "Wolf3D"

typedef struct		s_cam
{
	double			cam_x;
	double			dir_x;
	double			dir_y;
	double			mov_s;
	double			plan_x;
	double			plan_y;
	double			pos_x;
	double			pos_y;
	double			rot_s;
	int				x;
}					t_cam;

typedef struct		s_img
{
	int				a;
	int				b;
	int				c;
	void			*img;
	void			*mlx;
	char			*tab;
	void			*win;
}					t_img;

typedef struct		s_key
{
	int				up;
	int				down;
	int				right;
	int				left;
	int				f1;
	int				f2;
	int				f3;
}					t_key;

typedef struct		s_map
{
	char			**map;
	int				start_x;
	int				start_y;
	int				x;
	int				y;
}					t_map;

typedef struct		s_ray
{
	double			dir_x;
	double			dir_y;
	double			pos_x;
	double			pos_y;
}					t_ray;

typedef struct		s_txtr
{
	int				rslt;
	int				**img;
}					t_txtr;

typedef struct		s_env
{
	struct s_cam	cam;
	struct s_img	img;
	struct s_key	key;
	struct s_map	map;
	struct s_ray	ray;
	struct s_txtr	*txtr;
	int				n_map;
	int				id;
	int				color;
	double			delta_dist_x;
	double			delta_dist_y;
	int				draw_start;
	int				draw_end;
	int				line_height;
	double			perp_wall_dist;
	int				px;
	int				py;
	int				side;
	double			side_dist_x;
	double			side_dist_y;
	int				step_x;
	int				step_y;
	int				x;
}					t_env;

void				texturing(t_env *e);
void				init_key(t_env *e);
void				line_x(t_env *e);
int					event_key_press(int k, t_env *e);
int					event_key_release(int k, t_env *e);
void				move_cam(t_env *e);
int					play_wolf(t_env *e);
void				get_map(char *file, t_env *e);
void				mov_down(t_env *e);
void				mov_up(t_env *e);
void				turn_left(t_env *e);
void				turn_right(t_env *e);
void				cpt_fps(t_env *e);

#endif
