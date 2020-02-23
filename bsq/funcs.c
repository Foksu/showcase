/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseinela <iseinela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 02:51:48 by iseinela          #+#    #+#             */
/*   Updated: 2019/07/31 17:46:49 by iseinela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_check_numbers(char *temp, int j)
{
	int count;

	count = 0;
	if (temp[j] >= '0' && temp[j] <= '9')
		count = 3;
	return (count);
}

int		ft_strlen(char *str)
{
	int length;

	length = 0;
	while (*str)
	{
		length++;
		str++;
	}
	return (length);
}

int		ft_atoi(char *str, int count, int size)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	while (str[i] != '\0' && i < (size - count))
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + (str[i] - '0');
		else
			break ;
		i++;
	}
	return (res);
}

void	ft_print_square(char **map)
{
	int		i;
	int		j;
	int		k;
	int		s;

	k = 0;
	i = g_square.x - g_square.size;
	while (k++ < g_square.size)
	{
		s = 0;
		j = g_square.y - g_square.size;
		while (s++ < g_square.size)
			map[i][j++] = g_map_para.full;
		i++;
	}
}

void	ft_print_map(char **map)
{
	int		i;
	int		j;
	int		k;
	int		s;

	k = g_square.x - g_square.size;
	s = g_square.y - g_square.size;
	i = 0;
	while (*(map[i]))
	{
		j = 0;
		while (map[i][j])
		{
			if (i == k && j == s)
				ft_print_square(map);
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
