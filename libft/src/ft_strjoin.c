/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <schabaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by schabaud          #+#    #+#             */
/*   Updated: 2017/01/09 16:17:15 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	j = -1;
	tmp = NULL;
	if (!s1 || !s2)
		return (tmp);
	if (!(tmp = (char*)ft_memalloc(sizeof(char) * (ft_strlen(s1) +
		ft_strlen(s2) + 1))))
		return (tmp);
	while (s1[++i])
		tmp[i] = s1[i];
	while (s2[++j])
		tmp[i++] = s2[j];
	return (tmp);
}
