/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 09:41:18 by schabaud          #+#    #+#             */
/*   Updated: 2017/02/18 14:41:15 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static void	multi_tex_a(t_env *e)
{
	if (e->map.map[e->px][e->py] == 1)
		e->color = 0x660066;
	else if (e->map.map[e->px][e->py] == 2)
		e->color = 0xCCFF66;
	else if (e->map.map[e->px][e->py] == 3)
		e->color = 0x660066;
	else if (e->map.map[e->px][e->py] == 4)
		e->color = 0x000FFF;
	else if (e->map.map[e->px][e->py] == 5)
		e->color = 0x0;
	else if (e->map.map[e->px][e->py] == 6)
		e->color = 0xFFFF33;
}

static void	multi_tex_b(t_env *e)
{
	if (e->map.map[e->px][e->py] == 1)
		e->color = 0x660066;
	else if (e->map.map[e->px][e->py] == 2)
		e->color = 0x006660;
	else if (e->map.map[e->px][e->py] == 3)
		e->color = 0xF8F6F6;
	else if (e->map.map[e->px][e->py] == 4)
		e->color = 0xFFF;
	else if (e->map.map[e->px][e->py] == 5)
		e->color = 0xFFFFFF;
	else if (e->map.map[e->px][e->py] == 6)
		e->color = 0x33FFFF;
}

static void	quad_text(t_env *e)
{
	if (e->ray.dir_x > 0 && e->ray.dir_y > 0)
		e->color = 0x0000FF;
	else if (e->ray.dir_x > 0 && e->ray.dir_y < 0)
		e->color = 0x00FF00;
	else if (e->ray.dir_x < 0 && e->ray.dir_y > 0)
		e->color = 0xFF0000;
	else if (e->ray.dir_x < 0 && e->ray.dir_y < 0)
		e->color = 0xFFFF00;
}

void		texturing(t_env *e)
{
	if (e->key.f1 == 1 && e->key.f2 == 0)
		multi_tex_a(e);
	else if (e->key.f2 == 1 && e->key.f1 == 0)
		quad_text(e);
	else
		multi_tex_b(e);
}
