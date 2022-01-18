/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrender <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:16:19 by yrender           #+#    #+#             */
/*   Updated: 2021/09/20 16:56:39 by yrender          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_HEAD_H
# define BSQ_HEAD_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_val
{
	int		str_num;
	int		str_len;
	char	stone;
	char	field;
	char	insert;
	int		a;	
	int		x;
	int		y;
	int		i;
	int		fd;
	int		map_err;
}	t_val;

t_val	*ct_tval(void);
int		ft_atoi(char *str);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strcpy(char *str1, char *str2);
char	**make_arr(int str_num, int str_len);
int		ft_open(char *file);
int		map_download(char **arr, char *argvN, t_val *tv);
void	printarr(char **arr, t_val *tv);
int		**make_map(t_val *tv);
void	cleanarr(char **arr, int str_num);
void	cleanaap(int **map, t_val *tv);
void	printaap(int **map, t_val *tv);
int		clone_map(char **arr, int **map, t_val *tv);
void	make_clon(int **map, int **clon, t_val *tv);
void	bsq(int **arr, int **clon, t_val *tv);
int		min(int a, int b, int c);
void	cleanall(char **arr, int **map, int **clon, t_val *tv);
void	printdebug(int **map, int **clon, t_val *tv);
void	printresultbsq(char **arr, t_val *tv);
void	readstdin(void);
int		ft_read_params(char *argvN, t_val *tv);
int		ft_open(char *file);
int		cleanallerror(char **arr, int **map, int **clon, t_val *tv);
#endif