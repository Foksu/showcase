/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_in_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:40:48 by tbergkul          #+#    #+#             */
/*   Updated: 2019/07/21 22:58:25 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

int	solve_sudoku_reverse(int (*grid)[9])
{
	int		row;
	int		col;
	int		n;
	t_grid	coord;

	if (where_is_zero(&coord, grid) == 1)
		return (1);
	where_is_zero(&coord, grid);
	row = coord.x;
	col = coord.y;
	n = 9;
	while (n >= 1)
	{
		if (check_number(grid, row, col, n) == 1)
		{
			grid[row][col] = n;
			if (solve_sudoku(grid) == 1)
				return (1);
			grid[row][col] = 0;
		}
		n--;
	}
	return (0);
}
