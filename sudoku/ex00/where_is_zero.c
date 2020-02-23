/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_is_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 22:04:37 by tbergkul          #+#    #+#             */
/*   Updated: 2019/07/21 22:58:41 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

int		where_is_zero(t_grid *coord, int (*grid)[9])
{
	int x;
	int y;

	x = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 9)
		{
			if (grid[x][y] == 0)
			{
				set_point(coord, x, y);
				return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}
