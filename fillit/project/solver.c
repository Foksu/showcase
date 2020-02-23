/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skellman <skellman@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:28:33 by vvaltone          #+#    #+#             */
/*   Updated: 2019/11/18 16:31:40 by skellman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve(t_block *piecelist)
{
	t_map	*map;
	int		map_size;

	map_size = map_square_root(map_count_pieces(piecelist) * 4);
	map = map_new(map_size);
	while (!solve_fillit(map, piecelist, map_size))
	{
		map_free(map, map_size);
		map_size++;
		map = map_new(map_size);
	}
	map_print(map, map_size);
	map_free(map, map_size);
}

int		solve_check_boundaries(t_block *piece, int map_size, char axis)
{
	if (axis == 'y')
		return (piece->piececoords[1] + piece->offset_y < map_size &&
				piece->piececoords[3] + piece->offset_y < map_size &&
				piece->piececoords[5] + piece->offset_y < map_size &&
				piece->piececoords[7] + piece->offset_y < map_size);
	else
		return (piece->piececoords[0] + piece->offset_x < map_size &&
				piece->piececoords[2] + piece->offset_x < map_size &&
				piece->piececoords[4] + piece->offset_x < map_size &&
				piece->piececoords[6] + piece->offset_x < map_size);
}

int		solve_overlap(t_map *map, t_block *piece)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	x = piece->piececoords[i] + piece->offset_x;
	y = piece->piececoords[i + 1] + piece->offset_y;
	while (i <= 6 && map->array[y][x] == '.')
	{
		i += 2;
		x = piece->piececoords[i] + piece->offset_x;
		y = piece->piececoords[i + 1] + piece->offset_y;
	}
	return (i != 8);
}

void	solve_place(t_block *piece, t_map *map, char letter)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (i <= 6)
	{
		x = piece->piececoords[i] + piece->offset_x;
		y = piece->piececoords[i + 1] + piece->offset_y;
		map->array[y][x] = letter;
		i += 2;
	}
}

int		solve_fillit(t_map *map, t_block *piece, int map_size)
{
	if (!piece)
		return (1);
	piece->offset_x = 0;
	piece->offset_y = 0;
	while (solve_check_boundaries(piece, map_size, 'y'))
	{
		while (solve_check_boundaries(piece, map_size, 'x'))
		{
			if (!solve_overlap(map, piece))
			{
				solve_place(piece, map, piece->pieceletter);
				if (solve_fillit(map, piece->next, map_size))
					return (1);
				else
				{
					solve_place(piece, map, '.');
				}
			}
			piece->offset_x++;
		}
		piece->offset_x = 0;
		piece->offset_y++;
	}
	return (0);
}
