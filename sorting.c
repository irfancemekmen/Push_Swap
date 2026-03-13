/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 23:22:51 by iekmen            #+#    #+#             */
/*   Updated: 2026/03/14 01:31:38 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->nbr;
	second = (*stack)->next->nbr;
	third = (*stack)->next->next->nbr;
	if (first > second && second < third && first < third)
		sa(stack);
	else if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > second && second < third && first > third)
		ra(stack);
	else if (first < second && second > third && first < third)
	{
		sa(stack);
		ra(stack);
	}
	else if (first < second && second > third && first > third)
		rra(stack);
}

void	separation(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	pivot_a;
	int	pivot_b;
	int	i;

	i = size;
	get_pivot(*stack_a, size, &pivot_a);
	while (size != i / 2 + i % 2)
	{
		if ((*stack_a)->nbr < pivot_a)
		{
			pb(stack_a, stack_b);
			size--;
		}
		else if (stack_size(*stack_b) > 2)
		{
			get_pivot(*stack_b, stack_size(*stack_b), &pivot_b);
			if ((*stack_b)->nbr <= pivot_b)
				rr(stack_a, stack_b);
			else
				ra(stack_a);
		}
		else
			ra(stack_a);
	}
	qsort_check_a(stack_a, stack_b, i / 2 + i % 2, 0);
	qsort_check_b(stack_a, stack_b, i / 2, 0);
}

void	start_sorting(t_stack **stack_a)
{
	t_stack	*stack_b;
	int	size;

	stack_b = NULL;
	size = stack_size(*stack_a);
	if (!is_sorted(*stack_a))
	{
		if (size == 2)
			sa(stack_a);
		else if (size == 3)
			sort_three(stack_a);
		else
			separation(stack_a, &stack_b, size);
	}
}
