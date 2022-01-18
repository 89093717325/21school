/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrender <yrender@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 06:54:28 by yrender           #+#    #+#             */
/*   Updated: 2021/10/30 09:17:15 by yrender          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	int		i;

	i = 0;
	if (s1 == s2)
		return (s1);
	if (s1 > s2)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(char *)(s1 + i) = *(char *)(s2 + i);
			i--;
		}
	}
	else
	{
		while (i < (int)n)
		{
			*(char *)(s1 + i) = *(char *)(s2 + i);
			i++;
		}
	}
	return (s1);
}
