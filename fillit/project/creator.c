/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:04:54 by vvaltone          #+#    #+#             */
/*   Updated: 2019/11/20 10:13:24 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		create_free_piecelist(t_block *list)
{
	t_block *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

t_block		*create_list(char *buf, int size)
{
	t_block *current;
	t_block *beginning;
	int		i;
	char	pieceletter;

	i = 0;
	pieceletter = 'A';
	while (i < size)
	{
		if (pieceletter == 'A')
		{
			beginning = create_piece(buf + i, pieceletter);
			current = beginning;
		}
		else
		{
			current->next = create_piece(buf + i, pieceletter);
			current = current->next;
		}
		pieceletter++;
		i += 21;
	}
	current->next = NULL;
	return (beginning);
}

t_block		*create_piece(char *buf, char pieceletter)
{
	t_block	*piece_ptr;
	int		x;
	int		y;
	int		i;

	i = 0;
	x = 0;
	y = 1;
	if (!(piece_ptr = (t_block*)malloc(sizeof(t_block))))
		return (NULL);
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			piece_ptr->piececoords[x] = i % 5;
			piece_ptr->piececoords[y] = i / 5;
			x += 2;
			y += 2;
		}
		i++;
	}
	piece_ptr->offset_x = 0;
	piece_ptr->offset_y = 0;
	piece_ptr->pieceletter = pieceletter;
	return (create_move_to_topleft(piece_ptr));
}

t_block		*create_move_to_topleft(t_block *piece)
{
	while (piece->piececoords[0] != 0 && \
			piece->piececoords[2] != 0 && \
			piece->piececoords[4] != 0 && \
			piece->piececoords[6] != 0)
	{
		piece->piececoords[0] += -1;
		piece->piececoords[2] += -1;
		piece->piececoords[4] += -1;
		piece->piececoords[6] += -1;
	}
	while (piece->piececoords[1] != 0 && \
			piece->piececoords[3] != 0 && \
			piece->piececoords[5] != 0 && \
			piece->piececoords[7] != 0)
	{
		piece->piececoords[1] += -1;
		piece->piececoords[3] += -1;
		piece->piececoords[5] += -1;
		piece->piececoords[7] += -1;
	}
	return (piece);
}
