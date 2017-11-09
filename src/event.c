/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:25:45 by schabaud          #+#    #+#             */
/*   Updated: 2016/12/02 14:40:16 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	init_key(t_env *e)
{
	e->key.up = 0;
	e->key.down = 0;
	e->key.left = 0;
	e->key.right = 0;
	e->key.f1 = 0;
	e->key.f2 = 0;
	e->key.f3 = 0;
}

void	move_cam(t_env *e)
{
	if (e->key.up)
		mov_up(e);
	if (e->key.down)
		mov_down(e);
	if (e->key.left)
		turn_left(e);
	if (e->key.right)
		turn_right(e);
}

int		event_key_press(int k, t_env *e)
{
	if (k == 53)
		exit(0);
	else if (k == 13)
		e->key.up = 1;
	else if (k == 1)
		e->key.down = 1;
	else if (k == 0)
		e->key.right = 1;
	else if (k == 2)
		e->key.left = 1;
	else if (k == 122)
		e->key.f1 = (e->key.f1) ? 0 : 1;
	else if (k == 120)
		e->key.f2 = (e->key.f2) ? 0 : 1;
	else if (k == 99)
		e->key.f3 = (e->key.f3) ? 0 : 1;
	return (0);
}

int		event_key_release(int k, t_env *e)
{
	if (k == 13)
		e->key.up = 0;
	else if (k == 1)
		e->key.down = 0;
	else if (k == 0)
		e->key.right = 0;
	else if (k == 2)
		e->key.left = 0;
	return (0);
}
