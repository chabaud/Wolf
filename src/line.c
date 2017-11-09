/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_tracer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 07:32:51 by schabaud          #+#    #+#             */
/*   Updated: 2016/12/02 14:40:21 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	ground(int i, t_env *e)
{
	int		k;

	while (++i < HEIGHT / 2)
	{
		texturing(e);
		k = e->cam.x * 4 + i * WIDTH * 4;
		e->img.tab[k] = 102;
		e->img.tab[++k] = 153;
		e->img.tab[++k] = 204;
	}
	return (i);
}

static void	skybox(int i, t_env *e)
{
	int		k;

	while (++i < HEIGHT)
	{
		texturing(e);
		k = e->cam.x * 4 + i * WIDTH * 4;
		e->img.tab[k] = 204;
		e->img.tab[++k] = 153;
		e->img.tab[++k] = 0;
	}
}

void		line_x(t_env *e)
{
	int		k;

	skybox(ground(-1, e), e);
	while (e->draw_start < e->draw_end)
	{
		texturing(e);
		k = e->cam.x * 4 + e->draw_start * WIDTH * 4;
		e->img.tab[k] = e->color;
		e->img.tab[++k] = e->color >> 8;
		e->img.tab[++k] = e->color >> 16;
		++e->draw_start;
	}
}
