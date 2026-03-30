/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 01:41:22 by iekmen            #+#    #+#             */
/*   Updated: 2026/03/16 01:52:36 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	not_three_size(t_stack **stack_a, t_stack **stack_b, int *size)
{
	while ((*size) != 3 || !((*stack_a)->nbr < (*stack_a)->next->nbr
			&& (*stack_a)->next->nbr < (*stack_a)->next->next->nbr))
	{
		if ((*size) == 3 && (*stack_a)->nbr > (*stack_a)->next->nbr)
		{
			if ((*stack_a)->nbr > (*stack_a)->next->nbr
				&& (*stack_b)->nbr < (*stack_b)->next->nbr)
				ss(stack_a, stack_b);
			else
				sa(stack_a);
		}
		else if ((*size) == 3 && !((*stack_a)->next->next->nbr > (*stack_a)->nbr
				&& (*stack_a)->next->next->nbr > (*stack_a)->next->nbr))
		{
			pb(stack_a, stack_b);
			(*size)--;
		}
		else if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			sa(stack_a);
		else if ((*size)++)
			pa(stack_a, stack_b);
	}
}

void	bubble_sort(int *tmp_stack, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp_stack[i] > tmp_stack[j])
			{
				tmp = tmp_stack[i];
				tmp_stack[i] = tmp_stack[j];
				tmp_stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	get_pivot(t_stack *stack, int size, int *pivot)
{
	int	i;
	int	*tmp;

	if (!stack || size <= 0)
		return ;
	if (size == 1)
	{
		*pivot = stack->nbr;
		return ;
	}
	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return ;
	i = 0;
	while (i < size && stack)
	{
		tmp[i] = stack->nbr;
		i++;
		stack = stack->next;
	}
	bubble_sort(tmp, i);
	*pivot = tmp[i / 2];
	free(tmp);
}

void	is_need_double_swap(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
	{
		if ((*stack_b)->nbr < (*stack_b)->next->nbr)
			ss(stack_a, stack_b);
		else
			sa(stack_a);
	}
}
