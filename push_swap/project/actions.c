/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 13:22:15 by vvaltone          #+#    #+#             */
/*   Updated: 2019/12/29 13:22:16 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void			ps_print_stack(t_stacks *stacks)
{
	t_stack *st_a;
	t_stack *st_b;

	st_a = stacks->a;
	st_b = stacks->b;
	stacks->flag_c ? ft_printf(RED "A | B\n-----\n") :
	ft_printf("A | B\n-----\n");
	while (st_a || st_b)
	{
		st_a ? ft_printf("%d | ", st_a->val) : ft_printf("- | ");
		st_b ? ft_printf("%d\n", st_b->val) : ft_printf("-\n");
		st_a = st_a ? st_a->next : NULL;
		st_b = st_b ? st_b->next : NULL;
	}
	stacks->flag_c ? ft_printf("\n" EOC) : ft_printf("\n");
}

static int		ps_execute(char *cmd, t_stacks *stacks)
{
	int	len;
	int	res;

	len = ft_strlen(cmd);
	res = 0;
	if (len == 2 && cmd[0] == 's' && (cmd[1] == 's' || cmd[1] == 'a'))
		res = ps_execute_s(&stacks->a);
	if (len == 2 && cmd[0] == 's' && (cmd[1] == 's' || cmd[1] == 'b'))
		res = ps_execute_s(&stacks->b);
	if (len == 2 && cmd[0] == 'p' && cmd[1] == 'a')
		res = ps_execute_p(&stacks->b, &stacks->a);
	if (len == 2 && cmd[0] == 'p' && cmd[1] == 'b')
		res = ps_execute_p(&stacks->a, &stacks->b);
	if (len == 2 && cmd[0] == 'r' && (cmd[1] == 'r' || cmd[1] == 'a'))
		res = ps_execute_r(&stacks->a);
	if (len == 2 && cmd[0] == 'r' && (cmd[1] == 'r' || cmd[1] == 'b'))
		res = ps_execute_r(&stacks->b);
	if (len == 3 && cmd[0] == 'r' && cmd[1] == 'r' &&
		(cmd[2] == 'r' || cmd[2] == 'a'))
		res = ps_execute_rr(&stacks->a);
	if (len == 3 && cmd[0] == 'r' && cmd[1] == 'r' &&
		(cmd[2] == 'r' || cmd[2] == 'b'))
		res = ps_execute_rr(&stacks->b);
	return (res == 0 ? 0 : 1);
}

void			ps_do(char *cmd, int count, t_stacks *stacks)
{
	int	i;

	i = ft_abs(count);
	while (i)
	{
		if (ps_execute(cmd, stacks))
		{
			if (stacks->swap_mode == 1)
				ft_printf("%s\n", cmd);
			if (stacks->swap_mode == 0 && stacks->flag_v == 1)
				ps_print_stack(stacks);
		}
		else
			ps_error(&stacks, 0);
		i--;
	}
}
