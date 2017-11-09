/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_sqrt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 09:59:18 by schabaud          #+#    #+#             */
/*   Updated: 2017/01/09 16:24:58 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				**matrix_sqrt(unsigned int x, unsigned int y)
{
	void			**tmp;
	unsigned int	i;

	i = 0;
	if (!(tmp = (void**)malloc(sizeof(tmp) * y)))
		return (tmp);
	while (i < y)
		tmp[i++] = (void*)ft_memalloc(x);
	return (tmp);
}
