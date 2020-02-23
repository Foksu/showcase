/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_compare.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 23:28:11 by vvaltone          #+#    #+#             */
/*   Updated: 2019/07/21 23:31:18 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

void	ft_array_compare(int (*grid)[9], int (*reverse_grid)[9])
{
	int	i;
	int	j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (grid[i][j] != reverse_grid[i][j])
			{
				write(1, "Error\n", 6);
				return ;
			}
			j++;
		}
		i++;
	}
	ft_print_grid(grid);
}
