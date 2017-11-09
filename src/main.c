/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 21:22:08 by schabaud          #+#    #+#             */
/*   Updated: 2016/12/02 14:40:36 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	ft_exit(int k, t_env *e)
{
	(void)k;
	(void)e;
	exit(0);
	return (0);
}

static void	init_wolf(t_env *e)
{
	e->cam.dir_x = -1;
	e->cam.dir_y = 0;
	e->cam.plan_x = 0;
	e->cam.plan_y = 0.66;
	e->cam.pos_x = 22;
	e->cam.pos_y = 12;
	e->cam.rot_s = 0.1;
	e->cam.mov_s = 0.1;
	e->color = 0x00FFFFFF;
}

static void	start_screen(t_env *e)
{
	e->img.mlx = mlx_init();
	e->img.win = mlx_new_window(e->img.mlx, WIDTH, HEIGHT, TITLE);
	e->img.img = mlx_new_image(e->img.mlx, WIDTH, HEIGHT);
	e->img.tab = mlx_get_data_addr(e->img.img, &e->img.a, &e->img.b, &e->img.c);
	init_key(e);
	init_wolf(e);
	mlx_hook(e->img.win, 2, 1L << 0, event_key_press, e);
	mlx_hook(e->img.win, 3, 1L << 1, event_key_release, e);
	mlx_hook(e->img.win, 17, 1L << 17, ft_exit, e);
	mlx_loop_hook(e->img.mlx, play_wolf, e);
	mlx_loop(e->img.mlx);
}

int			main(void)
{
	t_env	e;

	get_map("map/map.wolf", &e);
	start_screen(&e);
	return (0);
}
