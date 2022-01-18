/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myHead.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmiyu <wmiyu@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:50:55 by wmiyu             #+#    #+#             */
/*   Updated: 2021/09/22 12:51:02 by wmiyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

void	ft_make_params(char *params, t_val *tv)
{
	char	lines[100];
	int		i;
	char	buffer;

	i = 0;
	tv->insert = params[ft_strlen(params) - 1];
	tv->stone = params[ft_strlen(params) - 2];
	tv->field = params[ft_strlen(params) - 3];
	i = 0;
	while (params[i] < params[ft_strlen(params) - 2])
	{
		lines [i] = params[i];
		i++;
	}
	tv->str_num = ft_atoi(lines);
	tv->i = 0;
	buffer = 0;
	while (buffer != '\n')
	{
		read(tv->fd, &buffer, 1);
		tv->i++;
	}
	tv->str_len = tv->i - 1;
}

int	ft_read_params(char *argvN, t_val *tv)
{
	char	buffer;
	char	params[1001];

	tv->fd = open(argvN, O_RDONLY);
	if (tv->fd <= 0)
		return (-1);
	tv->i = 0;
	buffer = '\0';
	while (buffer != '\n')
	{
		read(tv->fd, &buffer, 1);
		params[tv->i] = buffer;
		tv->i++;
	}
	params[tv->i - 1] = '\0';
	ft_make_params(params, tv);
	close(tv->fd);
	return (0);
}

int	bsq_main(char *argvN)
{
	char		**arr;
	int			**map;
	int			**clon;
	t_val		*tv;

	tv = ct_tval();
	map = NULL;
	clon = NULL;
	arr = NULL;
	if (ft_read_params(argvN, tv) == -1)
		return (-1);
	arr = make_arr(tv->str_num, tv->str_len);
	if (map_download(arr, argvN, tv) == -1)
		return (cleanallerror(arr, map, clon, tv));
	map = make_map(tv);
	if (clone_map(arr, map, tv) == -1)
		return (cleanallerror(arr, map, clon, tv));
	clon = make_map(tv);
	make_clon(map, clon, tv);
	bsq(map, clon, tv);
	printresultbsq(arr, tv);
	printarr(arr, tv);
	cleanall(arr, map, clon, tv);
	return (0);
}

int	main(int argc, char **argv)
{
	int	c;

	c = 1;
	if (argc == 1)
	{
		readstdin();
		return (0);
	}
	if (argc >= 2)
	{
		while (c < argc)
		{
			if (bsq_main(argv[c]) == -1)
			{
				write(2, "map error\n", 10);
			}
			c++;
		}
	}
	else
		write(2, "map error\n", 10);
	return (0);
}
