/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 20:09:13 by schabaud          #+#    #+#             */
/*   Updated: 2017/02/18 14:47:55 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_tab(char **str, char *sep)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		ft_putstr(str[i]);
		ft_putstr(sep);
		++i;
	}
}
