/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 13:45:08 by vvaltone          #+#    #+#             */
/*   Updated: 2019/07/21 23:29:22 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

int		check_number(int (*grid)[9], int row, int col, int n)
{
	if (check_row(grid, row, n) == 0)
	{
		if (check_col(grid, col, n) == 0)
		{
			if (check_box(grid, row - row % 3, col - col % 3, n) == 0)
				return (1);
		}
	}
	return (0);
}

int		solve_sudoku(int (*grid)[9])
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
	n = 1;
	while (n <= 9)
	{
		if (check_number(grid, row, col, n) == 1)
		{
			grid[row][col] = n;
			if (solve_sudoku(grid) == 1)
				return (1);
			grid[row][col] = 0;
		}
		n++;
	}
	return (0);
}

void	show_result(int (*grid)[9], int (*reverse_grid)[9])
{
	if (solve_sudoku(grid) == 1 && solve_sudoku_reverse(reverse_grid) == 1)
		ft_array_compare(grid, reverse_grid);
	else
		write(1, "Error\n", 6);
}

void	start_solving(int argc, char **argv)
{
	int grid[9][9];
	int reverse_grid[9][9];
	int i;
	int j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j] != '\0')
		{
			if (argv[i][j] == '.')
				argv[i][j] = '0';
			else if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				write(1, "Error\n", 6);
				return ;
			}
			grid[i - 1][j] = argv[i][j] - '0';
			reverse_grid[i - 1][j] = argv[i][j] - '0';
		}
	}
	show_result(grid, reverse_grid);
}

int		main(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (argc == 10)
	{
		while (argv[++i] != '\0')
		{
			while (argv[i][j] != '\0')
			{
				j++;
			}
			if (j != 9)
			{
				write(1, "Error\n", 6);
				return (0);
			}
			j = 0;
		}
		start_solving(argc, argv);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
