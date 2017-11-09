/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 03:34:50 by schabaud          #+#    #+#             */
/*   Updated: 2016/12/02 14:40:08 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void		mov_down(t_env *e)
{
	if (!e->map.map[(int)(e->cam.pos_x - e->cam.dir_x * e->cam.mov_s)]
			[(int)e->cam.pos_y])
		e->cam.pos_x -= e->cam.dir_x * e->cam.mov_s;
	if (!e->map.map[(int)e->cam.pos_x][(int)(e->cam.pos_y - \
				e->cam.dir_y * e->cam.mov_s)])
		e->cam.pos_y -= e->cam.dir_y * e->cam.mov_s;
}

void		mov_up(t_env *e)
{
	if (!e->map.map[(int)(e->cam.pos_x + e->cam.dir_x * e->cam.mov_s)]
			[(int)e->cam.pos_y])
		e->cam.pos_x += e->cam.dir_x * e->cam.mov_s;
	if (!e->map.map[(int)e->cam.pos_x][(int)(e->cam.pos_y + \
				e->cam.dir_y * e->cam.mov_s)])
		e->cam.pos_y += e->cam.dir_y * e->cam.mov_s;
}

void		turn_left(t_env *e)
{
	double	dir_x;
	double	plan_x;

	dir_x = e->cam.dir_x;
	plan_x = e->cam.plan_x;
	e->cam.dir_x = e->cam.dir_x * cos(-e->cam.rot_s) - e->cam.dir_y *
		sin(-e->cam.rot_s);
	e->cam.plan_x = e->cam.plan_x * cos(-e->cam.rot_s) - e->cam.plan_y *
		sin(-e->cam.rot_s);
	e->cam.dir_y = dir_x * sin(-e->cam.rot_s) + e->cam.dir_y *
		cos(-e->cam.rot_s);
	e->cam.plan_y = plan_x * sin(-e->cam.rot_s) + e->cam.plan_y *
		cos(-e->cam.rot_s);
}

void		turn_right(t_env *e)
{
	double	dir_x;
	double	plan_x;

	dir_x = e->cam.dir_x;
	plan_x = e->cam.plan_x;
	e->cam.dir_x = e->cam.dir_x * cos(e->cam.rot_s) - e->cam.dir_y *
		sin(e->cam.rot_s);
	e->cam.plan_x = e->cam.plan_x * cos(e->cam.rot_s) - e->cam.plan_y *
		sin(e->cam.rot_s);
	e->cam.dir_y = dir_x * sin(e->cam.rot_s) + e->cam.dir_y *
		cos(e->cam.rot_s);
	e->cam.plan_y = plan_x * sin(e->cam.rot_s) + e->cam.plan_y *
		cos(e->cam.rot_s);
}
