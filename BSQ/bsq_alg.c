/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_alg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmiyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:54:37 by wmiyu             #+#    #+#             */
/*   Updated: 2021/09/22 19:54:39 by wmiyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

int	min(int a, int b, int c)
{
	if (a > b)
		a = b;
	if (a > c)
		a = c;
	return (a + 1);
}

void	bsq(int **arr, int **cl, t_val *tv)
{
	int	i;
	int	j;

	tv->a = 0;
	i = 0;
	j = 0;
	while (i < tv->str_num)
	{
		while (j < tv->str_len)
		{
			if (arr[i][j] > 0 && i > 0 && j > 0)
			{
				cl[i][j] = min (cl[i][j - 1], cl[i - 1][j], cl[i - 1][j - 1]);
			}
			if (cl[i][j] > tv->a)
			{
				tv->a = cl[i][j];
				tv->x = i;
				tv->y = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
