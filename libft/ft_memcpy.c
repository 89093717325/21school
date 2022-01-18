/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrender <yrender@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:21:44 by yrender           #+#    #+#             */
/*   Updated: 2021/10/16 20:21:44 by yrender          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char	*dest;
	char	*src;
	size_t	i;

	i = 0;
	dest = (char *)s1;
	src = (char *)s2;
	if ((n == 0) || (s1 == s2))
		return (s1);
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return ((void *)s1);
}
