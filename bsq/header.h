/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseinela <iseinela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 02:45:22 by iseinela          #+#    #+#             */
/*   Updated: 2019/07/31 16:54:40 by iseinela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef	struct			s_map
{
	int		row;
	int		col;
	char	empty;
	char	obst;
	char	full;
}						t_map;

typedef struct			s_sq
{
	int		y;
	int		x;
	int		size;
}						t_sq;

extern	t_map			g_map_para;
extern	t_sq			g_square;

void					ft_reset_globals(void);
void					ft_map_error(void);
void					ft_check_rows(int fd);
void					ft_read_first_line(char **map, int fd);
void					ft_map_memory(char **map);
void					ft_read_map(char **map, int fd, int i, int j);
unsigned short int		ft_min(unsigned short int a, unsigned short int b,
						unsigned short int c);
unsigned short int		**ft_zero_arr(unsigned short int **arr);
void					ft_solve_bsq(char **map);
int						ft_atoi(char *str, int count, int size);
int						ft_strlen(char *str);
int						ft_check_numbers(char *temp, int j);
void					ft_print_square(char **map);
void					ft_print_map(char **map);

#endif
