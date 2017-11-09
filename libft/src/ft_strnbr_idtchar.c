/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnbr_idtchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 17:32:48 by schabaud          #+#    #+#             */
/*   Updated: 2017/02/18 14:46:53 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnbr_idtchar(char *str, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (str == NULL)
		return (j);
	while (str[i])
	{
		if (str[i] == c)
			++j;
		++i;
	}
	return (j);
}
