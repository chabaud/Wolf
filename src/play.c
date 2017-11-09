/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_wolf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 23:09:39 by schabaud          #+#    #+#             */
/*   Updated: 2016/12/02 14:40:26 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static void	init_par(t_env *e)
{
	e->cam.cam_x = 2 * e->cam.x / (double)WIDTH - 1;
	e->ray.pos_x = e->cam.pos_x;
	e->ray.pos_y = e->cam.pos_y;
	e->ray.dir_x = e->cam.dir_x + e->cam.plan_x * e->cam.cam_x;
	e->ray.dir_y = e->cam.dir_y + e->cam.plan_y * e->cam.cam_x;
	e->px = e->ray.pos_x;
	e->py = e->ray.pos_y;
	e->delta_dist_x = sqrt(1 + (e->ray.dir_y * e->ray.dir_y) /
			(e->ray.dir_x * e->ray.dir_x));
	e->delta_dist_y = sqrt(1 + (e->ray.dir_x * e->ray.dir_x) /
			(e->ray.dir_y * e->ray.dir_y));
}

static void	algo_dda(t_env *e)
{
	int		tmp;

	tmp = 0;
	while (tmp == 0)
	{
		if (e->side_dist_x < e->side_dist_y)
		{
			e->side_dist_x += e->delta_dist_x;
			e->px += e->step_x;
			e->side = 0;
		}
		else
		{
			e->side_dist_y += e->delta_dist_y;
			e->py += e->step_y;
			e->side = 1;
		}
		if (e->map.map[e->px][e->py] > 0)
			tmp = 1;
	}
}

static void	side_dist(t_env *e)
{
	if (e->ray.dir_x < 0)
	{
		e->step_x = -1;
		e->side_dist_x = (e->ray.pos_x - e->px) * e->delta_dist_x;
	}
	else
	{
		e->step_x = 1;
		e->side_dist_x = (e->px + 1.0 - e->ray.pos_x) * e->delta_dist_x;
	}
	if (e->ray.dir_y < 0)
	{
		e->step_y = -1;
		e->side_dist_y = (e->ray.pos_y - e->py) * e->delta_dist_y;
	}
	else
	{
		e->step_y = 1;
		e->side_dist_y = (e->py + 1.0 - e->ray.pos_y) * e->delta_dist_y;
	}
}

static void	wall_dist(t_env *e)
{
	if (e->side == 0)
	{
		e->perp_wall_dist = fabs((e->px - e->ray.pos_x + (1 - e->step_x) / 2) /
			e->ray.dir_x);
	}
	else
	{
		e->perp_wall_dist = fabs((e->py - e->ray.pos_y + (1 - e->step_y) / 2) /
			e->ray.dir_y);
	}
	e->line_height = abs((int)(HEIGHT / e->perp_wall_dist));
	e->draw_start = HEIGHT / 2 - e->line_height / 2;
	if (e->draw_start < 0)
		e->draw_start = 0;
	e->draw_end = e->line_height / 2 + HEIGHT / 2;
	if (e->draw_end >= HEIGHT)
		e->draw_end = HEIGHT - 1;
}

int			play_wolf(t_env *e)
{
	e->cam.x = -1;
	move_cam(e);
	while (++e->cam.x < WIDTH)
	{
		init_par(e);
		side_dist(e);
		algo_dda(e);
		wall_dist(e);
		line_x(e);
	}
	mlx_put_image_to_window(e->img.mlx, e->img.win, e->img.img, 0, 0);
	cpt_fps(e);
	return (0);
}
