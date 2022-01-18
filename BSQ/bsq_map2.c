/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmiyu <wmiyu@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:18:26 by wmiyu             #+#    #+#             */
/*   Updated: 2021/09/22 14:18:29 by wmiyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

void	printmap(int **map, t_val *tv)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < tv->str_num)
	{
		while (j < tv->str_len)
		{
			c = 48 + map[i][j];
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}

void	printarr(char **arr, t_val *tv)
{
	int	i;

	i = 0;
	while (i < tv->str_num)
	{
		write(1, arr[i], tv->str_len);
		write(1, "\n", 1);
		i++;
	}
}

void	printresultbsq(char **arr, t_val *tv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < tv->a)
	{
		while (j < tv->a)
		{
			(void) arr;
			arr[tv->x - i][tv->y - j] = tv->insert;
			j++;
		}
		j = 0;
		i++;
	}
}

int	ft_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd > 0)
		return (fd);
	else
		return (-1);
	return (0);
}

void	readstdin(void)
{
	char	ch;
	int		fd;

	fd = open("stdinmapfile", O_WRONLY);
	if (fd > 0)
	{
		while (read(0, &ch, 1) > 0)
		{
			write(fd, &ch, 1);
		}
		close (fd);
	}
	else
		ft_putstr("map error\n");
}
