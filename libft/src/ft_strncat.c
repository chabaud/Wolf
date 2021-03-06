/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <schabaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by schabaud          #+#    #+#             */
/*   Updated: 2017/01/09 16:21:05 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, char const *src, size_t n)
{
	size_t	i;
	size_t	l_dest;
	size_t	l_src;

	i = -1;
	l_dest = ft_strlen(dest);
	l_src = ft_strlen(src);
	while (++i < l_src && i < n)
		dest[l_dest + i] = src[i];
	dest[l_dest + i] = '\0';
	return (dest);
}
