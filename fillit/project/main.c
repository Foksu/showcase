/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:28:00 by vvaltone          #+#    #+#             */
/*   Updated: 2019/11/20 10:13:33 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_block	*piecelist;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (1);
	}
	if ((piecelist = parser(argv[1])) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	solve(piecelist);
	create_free_piecelist(piecelist);
	return (0);
}
