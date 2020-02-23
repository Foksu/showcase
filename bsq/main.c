/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseinela <iseinela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 11:09:15 by iseinela          #+#    #+#             */
/*   Updated: 2019/07/31 17:00:46 by iseinela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_map	g_map_para = {0, 0, 0, 0, 0};
t_sq	g_square = {0, 0, 0};

void	ft_reset_globals(void)
{
	g_map_para.empty = 0;
	g_map_para.obst = 0;
	g_map_para.full = 0;
	g_map_para.col = 0;
	g_map_para.row = 0;
	g_square.size = 0;
	g_square.x = 0;
	g_square.y = 0;
}

void	ft_handler(int fd)
{
	char	**map;

	ft_check_rows(fd);
	if (!g_map_para.row || !g_map_para.obst
		|| !g_map_para.full || !g_map_para.empty)
		return (ft_map_error());
	map = (char**)malloc(sizeof(char*) * g_map_para.row + 2);
	ft_read_first_line(map, fd);
	if (!g_map_para.row)
		return ;
	ft_map_memory(map);
	ft_read_map(map, fd, 1, 0);
	if (!g_map_para.row)
		return ;
	ft_solve_bsq(map);
	ft_print_map(map);
	free(map);
}

int		main(int ac, char **av)
{
	int		fd;
	int		i;

	i = 1;
	while (i < ac)
	{
		if (i > 1)
			write(1, "\n", 1);
		fd = open(av[i], O_RDONLY);
		ft_handler(fd);
		ft_reset_globals();
		close(fd);
		i++;
	}
	if (ac == 1)
		ft_handler(0);
	return (0);
}
