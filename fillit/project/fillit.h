/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:27:54 by vvaltone          #+#    #+#             */
/*   Updated: 2019/11/20 10:13:31 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct	s_map
{
	char		**array;
}				t_map;

typedef struct	s_block
{
	char			pieceletter;
	int				piececoords[8];
	int				offset_x;
	int				offset_y;
	struct s_block	*next;
}				t_block;

int				parse_adjacency_counter(char *buf);
int				parse_charcount(char *buf);
int				parse_valid(char *buf, int size);
int				solve_check_boundaries(t_block *piece, int map_size, char axis);
int				solve_overlap(t_map *map, t_block *piece);
int				solve_fillit(t_map *map, t_block *piecelist, int map_size);
int				map_square_root(int num);
size_t			map_count_pieces(t_block *piecelist);
t_block			*create_move_to_topleft(t_block *piece);
t_block			*create_piece(char *buf, char pieceletter);
t_block			*create_list(char *buf, int size);
t_block			*parser(char *filename);
t_map			*map_new(int size);
void			create_free_piecelist(t_block *list);
void			map_free(t_map *map, int map_size);
void			map_print(t_map *map, int size);
void			solve_place(t_block *piece, t_map *map, char letter);
void			solve(t_block *piecelist);

#endif
