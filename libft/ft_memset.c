/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrender <yrender@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:54:10 by yrender           #+#    #+#             */
/*   Updated: 2021/10/28 21:23:39 by yrender          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*res;
	size_t			i;

	i = 0;
	if (n == 0)
		return (b);
	res = (unsigned char *)b;
	while (i < n)
	{
		res[i] = c;
		i++;
	}
	return (res);
}
