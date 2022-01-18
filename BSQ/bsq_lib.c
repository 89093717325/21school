/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmiyu <wmiyu@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:58:35 by wmiyu             #+#    #+#             */
/*   Updated: 2021/09/22 13:58:38 by wmiyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

void	cleanarr(char **arr, int str_num)
{
	int	i;

	i = 0;
	while (i < str_num)
	{
		free(arr[i]);
		i++;
	}
	free (arr);
}

void	cleanmap(int **map, t_val *tv)
{
	(void) tv;
	free (*map);
	free (map);
}

void	cleanall(char **arr, int **map, int **clon, t_val *tv)
{
	cleanarr(arr, tv->str_num);
	cleanmap(map, tv);
	cleanmap(clon, tv);
	free(tv);
}

int	cleanallerror(char **arr, int **map, int **clon, t_val *tv)
{
	cleanall(arr, map, clon, tv);
	return (-1);
}
