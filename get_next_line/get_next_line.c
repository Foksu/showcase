/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:10:37 by vvaltone          #+#    #+#             */
/*   Updated: 2019/10/31 16:44:53 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		check_content(char **stack, char **line)
{
	char		*tmp_stack;
	char		*strchr_stack;
	int			i;

	i = 0;
	strchr_stack = *stack;
	while (strchr_stack[i] != '\n')
	{
		if (!strchr_stack[i++])
			return (0);
	}
	tmp_stack = &strchr_stack[i];
	*tmp_stack = '\0';
	*line = ft_strdup(*stack);
	*stack = ft_strdup(tmp_stack + 1);
	return (1);
}

static void		add_heap_to_stack(char **stack, char *heap)
{
	char		*tmp;

	tmp = *stack;
	if (tmp)
	{
		*stack = ft_strjoin(tmp, heap);
		free(tmp);
		tmp = NULL;
	}
	else
	{
		*stack = ft_strdup(heap);
	}
}

int				get_next_line(const int fd, char **line)
{
	static char	*stack[1024 + 1];
	char		heap[BUFF_SIZE + 1];
	int			ret;

	if (!line || fd < 0 || fd >= 1024 + 1 || (read(fd, stack[fd], 0) < 0))
		return (-1);
	while ((ret = read(fd, heap, BUFF_SIZE)) > 0)
	{
		heap[ret] = '\0';
		add_heap_to_stack(&stack[fd], heap);
		if (check_content(&stack[fd], line))
			return (1);
	}
	if (!stack[fd] || stack[fd][0] == '\0')
	{
		*line = NULL;
		return (0);
	}
	if (stack[fd])
		if (check_content(&(stack[fd]), line))
			return (1);
	*line = ft_strdup(stack[fd]);
	free(stack[fd]);
	stack[fd] = NULL;
	return (1);
}
