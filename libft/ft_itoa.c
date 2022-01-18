/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrender <yrender@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:05:09 by yrender           #+#    #+#             */
/*   Updated: 2021/10/26 14:37:04 by yrender          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen(int n)
{
	size_t	len;

	len = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (size == ((size_t)0) - 1)
		return (0);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == 0)
		return (0);
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char			*res;
	size_t			len;
	unsigned int	nb;

	len = ft_numlen(n);
	nb = n;
	if (n < 0)
	{
		nb = n * -1;
		len++;
	}
	res = ft_strnew(len);
	if (res == 0)
		return (0);
	res[--len] = (nb % 10) + '0';
	while (nb / 10 != 0)
	{
		nb /= 10;
		res[--len] = (nb % 10) + '0';
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
