/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmiyu <wmiyu@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:50:55 by wmiyu             #+#    #+#             */
/*   Updated: 2021/09/22 12:51:02 by wmiyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

t_val	*ct_tval(void)
{
	t_val	*tv;

	tv = malloc (sizeof(t_val));
	tv->str_num = 0;
	tv->str_len = 0;
	tv->stone = 0;
	tv->field = 0;
	tv->insert = 0;
	tv->a = 0;
	tv->x = 0;
	tv->y = 0;
	tv->i = 0;
	tv->fd = 0;
	tv->map_err = 0;
	return (tv);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1 );
		i++;
	}
	write (1, "\0", 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return (num * sign);
}

char	*ft_strcpy(char *str1, char *str2)
{
	char	*str;
	int		len1;
	int		len2;
	int		i;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	i = 0;
	str = (char *)malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	while (i < len1)
	{
		str[i] = str1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		str[len1 + i] = str2[i];
		i++;
	}
	str[len1 + len2] = '\0';
	return (str);
}
