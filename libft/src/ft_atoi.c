/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <schabaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by schabaud          #+#    #+#             */
/*   Updated: 2017/02/18 15:05:14 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char const *s)
{
	int		v;
	char	negative;

	v = 0;
	negative = 0;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\v' || *s == '\f'
			|| *s == '\r')
		s++;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		negative = 1;
		s++;
	}
	while ((*s >= '0') && (*s <= '9'))
		v = (v * 10) - (*s++ - '0');
	if (!negative)
		v = -v;
	return (v);
}
