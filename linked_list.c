/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 02:42:21 by iekmen            #+#    #+#             */
/*   Updated: 2026/03/30 17:06:58 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

static t_stack	*new_node(long nbr)
{
	t_stack	*new;

	if (nbr < -2147483648 || nbr > 2147483647)
		return (NULL);
	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}

static void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	stack_clear(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

t_stack	*add_to_linked_list(char **av, int flag)
{
	t_stack	*stack;
	t_stack	*new;
	char	**splitted;
	int		i;
	int		j;

	stack = NULL;
	j = 0;
	i = 0;
	while (av[i])
	{
		j = 0;
		splitted = ft_split(av[i++], ' ');
		while (splitted[j])
		{
			new = new_node(ft_atoi(splitted[j++]));
			if (!new)
				free_helper(stack, av, splitted, flag);
			stack_add_back(&stack, new);
		}
		free_splitted(splitted);
	}
	return (stack);
}
