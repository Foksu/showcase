/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 12:36:06 by vvaltone          #+#    #+#             */
/*   Updated: 2019/07/31 16:06:26 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned short int	ft_min(unsigned short int a, unsigned short int b,
unsigned short int c)
{
	if ((a >= b && b >= c) || (b >= a && a >= c))
		return (c);
	else if ((c >= a && a >= b) || (a >= c && c >= b))
		return (b);
	else
		return (a);
}

unsigned short int	**ft_zero_arr(unsigned short int **arr)
{
	int i;
	int j;

	i = 0;
	arr = (unsigned short int**)malloc(sizeof(unsigned short int*)
	* (g_map_para.col + 1));
	while (i <= g_map_para.row)
	{
		arr[i] = (unsigned short int*)malloc(sizeof(unsigned short int)
		* (g_map_para.row + 1));
		j = 0;
		while (j <= g_map_para.col)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
	return (arr);
}

void				ft_solve_bsq(char **map)
{
	int					i;
	int					j;
	unsigned short int	**b;

	i = 1;
	b = ft_zero_arr(0);
	while (i <= g_map_para.row)
	{
		j = 1;
		while (j <= g_map_para.col)
		{
			if (map[i - 1][j - 1] == g_map_para.empty)
			{
				b[i][j] = ft_min(b[i][j - 1], b[i - 1][j], b[i - 1][j - 1]) + 1;
				if (b[i][j] > g_square.size)
				{
					g_square.size = b[i][j];
					g_square.x = i;
					g_square.y = j;
				}
			}
			j++;
		}
		i++;
	}
}
