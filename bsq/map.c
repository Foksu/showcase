/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseinela <iseinela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:50:27 by iseinela          #+#    #+#             */
/*   Updated: 2019/07/31 16:46:28 by iseinela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_map_error(void)
{
	write(2, "map error\n", 10);
	ft_reset_globals();
}

void	ft_check_rows(int fd)
{
	int		i;
	int		count;
	char	*temp;

	i = 0;
	temp = (char*)malloc(sizeof(50));
	read(fd, &temp[i], 1);
	while (temp[i] != '\n' && i < 45)
	{
		i++;
		read(fd, &temp[i], 1);
	}
	temp[i] = 0;
	count = ft_check_numbers(temp, ft_strlen(temp) - 3);
	g_map_para.row = ft_atoi(temp, count, ft_strlen(temp));
	i = 0;
	while (temp[i] && temp[i] >= '0' &&
	temp[i] <= '9' && i < (ft_strlen(temp) - count))
		i++;
	g_map_para.empty = temp[i++];
	g_map_para.obst = temp[i++];
	g_map_para.full = temp[i];
	free(temp);
}

void	ft_read_first_line(char **map, int fd)
{
	char	*topline;
	int		i;

	topline = (char*)malloc(sizeof(char) * 70000);
	i = 0;
	read(fd, &topline[i], 1);
	while (topline[i] != '\n')
	{
		if (topline[i] != g_map_para.empty && topline[i] != g_map_para.obst)
		{
			free(topline);
			return (ft_map_error());
		}
		i++;
		read(fd, &topline[i], 1);
	}
	g_map_para.col = i;
	topline[i] = 0;
	*map = (char*)malloc(sizeof(char) * (i + 1));
	i = -1;
	while (topline[++i] != '\0')
		map[0][i] = topline[i];
	map[0][i] = '\0';
	free(topline);
}

void	ft_map_memory(char **map)
{
	int		i;

	i = 1;
	while (i <= g_map_para.row)
	{
		map[i] = (char*)malloc(sizeof(char) * (g_map_para.col + 2));
		i++;
	}
}

void	ft_read_map(char **map, int fd, int i, int j)
{
	char check;

	check = 0;
	while (i < g_map_para.row)
	{
		read(fd, &map[i][j], 1);
		while (map[i][j] != '\n' && j <= g_map_para.col)
		{
			if (map[i][j] != g_map_para.empty && map[i][j] != g_map_para.obst)
				return (ft_map_error());
			j++;
			read(fd, &map[i][j], 1);
		}
		map[i][j] = 0;
		if (j != g_map_para.col)
			return (ft_map_error());
		j = 0;
		i++;
	}
	read(fd, &check, 1);
	if (check || i != g_map_para.row)
		return (ft_map_error());
}
