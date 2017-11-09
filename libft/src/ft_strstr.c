/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 14:41:58 by schabaud          #+#    #+#             */
/*   Updated: 2017/02/18 14:42:01 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *str, char const *to_find)
{
	size_t	size;

	if (*to_find == '\0')
		return ((char *)str);
	size = ft_strlen(to_find);
	while (*str)
	{
		if (ft_strncmp(str, to_find, size) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
