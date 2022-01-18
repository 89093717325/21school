/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrender <yrender@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:24:14 by yrender           #+#    #+#             */
/*   Updated: 2021/10/31 21:57:41 by yrender          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_isspace(const char *s)
{
	while (*s == ' ' || *s == '\t' || *s == '\n'
		|| *s == '\v' || *s == '\f' || *s == '\r')
		s++;
	return ((char *)s);
}

int	ft_atoi(const char *s)
{
	int			sign;
	long int	num;
	long int	lim;

	num = 0;
	sign = 1;
	s = ft_isspace(s);
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		lim = num;
		num = num * 10 + sign * (*s - '0');
		if (sign == 1 && lim > num)
			return (-1);
		else if (sign == -1 && lim < num)
			return (0);
		s++;
	}
	return (num);
}
