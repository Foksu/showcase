/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 18:34:34 by tbergkul          #+#    #+#             */
/*   Updated: 2019/07/21 22:57:49 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

int	check_row(int (*grid)[9], int row, int n)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (grid[row][i] == n)
			return (1);
		i++;
	}
	return (0);
}

int	check_col(int (*grid)[9], int col, int n)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (grid[i][col] == n)
			return (1);
		i++;
	}
	return (0);
}

int	check_box(int (*grid)[9], int row_start, int col_start, int n)
{
	int i;
	int j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (grid[i + row_start][j + col_start] == n)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
