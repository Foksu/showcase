/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 13:22:45 by vvaltone          #+#    #+#             */
/*   Updated: 2019/12/29 13:22:46 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack			*ps_create_new_node(int val)
{
	t_stack *new;

	if ((new = (t_stack*)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	new->val = val;
	new->i = 0;
	new->sort = 1;
	new->next = NULL;
	return (new);
}

t_stack			*ps_get_last_node(t_stack *st)
{
	while (st->next)
		st = st->next;
	return (st);
}

void			ps_set_index(t_stack *st)
{
	int i;

	i = 0;
	while (st)
	{
		st->i = i;
		i++;
		st = st->next;
	}
}

static void		ps_create_stack_a(int argc, char **av, t_stacks *stacks)
{
	int i;
	int value;

	av = argc == 2 ? ft_strsplit(av[1], ' ') : av;
	i = argc == 2 ? 0 : 1;
	while ((argc == 2 ? (int)av[i] : i < argc))
	{
		if (ft_strcmp(av[i], "-v") == 0)
			stacks->flag_v = 1;
		else if (ft_strcmp(av[i], "-c") == 0)
			stacks->flag_c = 1;
		else
		{
			value = ft_atoi(av[i]);
			if (ps_is_integer(value, av[i]) == 0 ||
				ps_check_duplicate(stacks->a, value) == 0)
				ps_error(&stacks, ft_free_array(argc == 2 ? av : NULL, 1));
			if ((ps_push_back_valid(&stacks->a, value)) == NULL)
				ps_error(&stacks, ft_free_array(argc == 2 ? av : NULL, 1));
		}
		i++;
	}
	ft_free_array(argc == 2 ? av : NULL, 1);
}

t_stacks		*ps_create_stacks(int argc, char **av)
{
	t_stacks *stacks;

	if ((stacks = (t_stacks*)malloc(sizeof(t_stacks))) == NULL)
		ps_error(&stacks, 1);
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->swap_mode = 0;
	stacks->flag_v = 0;
	stacks->flag_c = 0;
	ps_create_stack_a(argc, av, stacks);
	return (stacks);
}
