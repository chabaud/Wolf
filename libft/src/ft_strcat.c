/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <schabaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by schabaud          #+#    #+#             */
/*   Updated: 2017/01/09 16:14:56 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcat(char *dest, char const *src)
{
	char	*tmp_dest;
	char	*tmp_src;

	tmp_dest = dest;
	tmp_src = (char*)src;
	while (*tmp_dest)
		tmp_dest++;
	while (*tmp_src)
		*tmp_dest++ = *tmp_src++;
	*tmp_dest = '\0';
	return (dest);
}
