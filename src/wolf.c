/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:04:02 by schabaud          #+#    #+#             */
/*   Updated: 2016/12/02 14:40:31 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void				cpt_fps(t_env *e)
{
	static struct timeval	fps;
	struct timeval			tmp;
	char					*txt;
	int						v;

	txt = NULL;
	gettimeofday(&tmp, NULL);
	if (e->key.f3)
	{
		v = (tmp.tv_sec * 1000000 + tmp.tv_usec) - \
			(fps.tv_sec * 1000000 + fps.tv_usec);
		txt = ft_itoa(1000000 / abs(v));
		mlx_string_put(e->img.mlx, e->img.win, 0, 0, 0x0, txt);
	}
	free(txt);
	gettimeofday(&fps, NULL);
}
