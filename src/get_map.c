/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 00:05:25 by schabaud          #+#    #+#             */
/*   Updated: 2017/02/18 14:39:39 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void		ft_exit(void)
{
	ft_putstr("\033[Corrupted File\n");
	exit(0);
}

void		get_info_map(t_env *e, char *line)
{
	int		i;
	char	**tmp;

	i = -1;
	tmp = ft_strsplit(line, ' ');
	while (tmp[++i] != NULL)
		;
	if (i != 4)
		ft_exit();
	e->map.start_x = ft_atoi(tmp[2]);
	e->map.start_y = ft_atoi(tmp[3]);
	e->map.x = ft_atoi(tmp[0]);
	e->map.y = ft_atoi(tmp[1]);
	matrix_sqrt_free(tmp, 4);
}

void		load_map(t_env *e, int fd)
{
	int		i;
	int		j;
	int		k;
	char	*line;
	char	**tmp;

	k = -1;
	e->map.map = (char**)matrix_sqrt(e->map.x, e->map.y);
	while (get_next_line(fd, &line))
	{
		i = -1;
		j = -1;
		++k;
		tmp = ft_strsplit(line, ' ');
		while (tmp[++i] != NULL)
			;
		if (i != e->map.x)
			ft_exit();
		while (tmp[++j] != NULL)
			e->map.map[k][j] = ft_atoi(tmp[j]);
		matrix_sqrt_free(tmp, i);
		free(line);
	}
}

void		get_map(char *file, t_env *e)
{
	int		fd;
	char	*line;

	line = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_exit();
	get_next_line(fd, &line);
	get_info_map(e, line);
	free(line);
	load_map(e, fd);
}
