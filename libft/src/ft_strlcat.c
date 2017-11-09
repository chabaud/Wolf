/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <schabaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by schabaud          #+#    #+#             */
/*   Updated: 2017/01/09 16:17:22 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, char const *src, size_t count)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i] && i < count)
		i++;
	j = i;
	while (src[i - j] && i < count - 1)
	{
		dest[i] = src[i - j];
		i++;
	}
	if (j < count)
		dest[i] = '\0';
	return (j + ft_strlen(src));
}
