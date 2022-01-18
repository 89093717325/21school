/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmiyu <wmiyu@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:50:55 by wmiyu             #+#    #+#             */
/*   Updated: 2021/09/22 12:51:02 by wmiyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

char	**make_arr(int str_num, int str_len)
{
	int		i;
	char	**arr;

	i = 0;
	arr = (char **)malloc(str_num * sizeof(char *));
	while (i < str_num)
	{
		arr[i] = (char *)malloc(str_len + 1 * sizeof(char));
		i++;
	}
	return (arr);
}

int	map_download(char **arr, char *argvN, t_val *tv)
{
	ssize_t	read_bytes;
	char	buffer;
	int		i;
	int		fd;

	fd = ft_open(argvN);
	if (fd == -1)
		return (-1);
	i = 0;
	buffer = 0;
	while (buffer != '\n')
	{
		read_bytes = read(fd, &buffer, 1);
		i++;
	}
	i = 0;
	while (i < tv->str_num)
	{
		read_bytes = read(fd, arr[i], tv->str_len + 1);
		i++;
	}
	close (fd);
	return (read_bytes);
}

int	**make_map(t_val *tv)
{
	int	i;
	int	j;
	int	**map;

	i = 0;
	j = 0;
	map = (int **) malloc (sizeof(int *));
	while (i < tv->str_num)
	{
		while (j < tv->str_len)
		{
			map[i] = (int *) malloc (sizeof(int));
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}

int	clone_map(char **arr, int **map, t_val *tv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < tv->str_num)
	{
		while (j < tv->str_len)
		{
			if (arr[i][j] == tv->stone)
				map[i][j] = 0;
			else if (arr[i][j] == tv->field)
				map[i][j] = 1;
			else
				tv->map_err = -1;
			j++;
		}
		j = 0;
		i++;
	}
	return (tv->map_err);
}

void	make_clon(int **map, int **clon, t_val *tv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < tv->str_num)
	{
		while (j < tv->str_len)
		{
			clon[i][j] = map[i][j];
			j++;
		}
		j = 0;
		i++;
	}
}
