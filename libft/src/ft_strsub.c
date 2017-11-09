/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <schabaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by schabaud          #+#    #+#             */
/*   Updated: 2017/01/09 16:24:02 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tmp;

	i = -1;
	if ((!*s && !s) || start > ft_strlen(s) ||
		!(tmp = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (++i < len && s[start] != '\0')
		tmp[i] = s[start++];
	return (tmp);
}
