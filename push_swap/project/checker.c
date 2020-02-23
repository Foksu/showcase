/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 13:21:50 by vvaltone          #+#    #+#             */
/*   Updated: 2019/12/29 13:21:51 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		main(int argc, char **av)
{
	t_stacks	*stacks;
	char		*cmd;

	cmd = NULL;
	stacks = ps_create_stacks(argc, av);
	stacks->swap_mode = 0;
	if (stacks->a == NULL)
		exit(ps_free_stacks(&stacks, 0));
	while (get_next_line(0, &cmd))
	{
		ps_do(cmd, 1, stacks);
		if (cmd)
			free(cmd);
	}
	if (ps_is_sorted(stacks))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (ps_free_stacks(&stacks, 0));
}
