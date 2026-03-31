/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 00:23:17 by iekmen            #+#    #+#             */
/*   Updated: 2026/03/30 17:44:42 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	qsort_a(t_stack **stack_a, t_stack **stack_b, int *size, int count)
{
	int	i;
	int	pivot;
	int	pivot_b;

	get_pivot(*stack_a, *size, &pivot);
	i = *size;
	while (*size != i / 2 + i % 2)
	{
		if ((*stack_a)->nbr < pivot && (*size)--)
			pb(stack_a, stack_b);
		else
		{
			get_pivot(*stack_b, stack_size(*stack_b), &pivot_b);
			if (stack_size(*stack_b) > 2 && (*stack_b)->nbr <= pivot_b)
				rr(stack_a, stack_b);
			else
				ra(stack_a);
			count++;
		}
	}
	while ((i / 2 + i % 2 != stack_size(*stack_a)) && count--)
		rra(stack_a);
	qsort_check_a(stack_a, stack_b, i / 2 + i % 2, 0);
	qsort_check_b(stack_a, stack_b, i / 2, 0);
}

void	qsort_check_a(t_stack **stack_a, t_stack **stack_b, int size, int count)
{
	if (is_sorted_n(*stack_a, size))
		return ;
	else if (size == 2)
	{
		is_need_double_swap(stack_a, stack_b);
		return ;
	}
	else if (size == 3)
	{
		if (stack_size(*stack_a) == 3)
			sort_three(stack_a);
		else
			not_three_size(stack_a, stack_b, &size);
		return ;
	}
	else
		qsort_a(stack_a, stack_b, &size, count);
}

void	qsort_b(t_stack **stack_a, t_stack **stack_b, int *size, int count)
{
	int	i;
	int	pivot;
	int	pivot_a;

	get_pivot(*stack_b, *size, &pivot);
	i = *size;
	while (*size != i / 2)
	{
		if ((*stack_b)->nbr >= pivot && (*size)--)
			pa(stack_a, stack_b);
		else
		{
			get_pivot(*stack_a, stack_size(*stack_a), &pivot_a);
			if ((*stack_a)->nbr > pivot_a)
				rr(stack_a, stack_b);
			else
				rb(stack_b);
			count++;
		}
	}
	while ((i / 2 != stack_size(*stack_b)) && count--)
		rrb(stack_b);
	qsort_check_a(stack_a, stack_b, i / 2 + i % 2, 0);
	qsort_check_b(stack_a, stack_b, i / 2, 0);
}

void	stack_b_process(t_stack **stack_a, t_stack **stack_b, int size)
{
	while (size || !((*stack_a)->nbr < (*stack_a)->next->nbr
			&& (*stack_a)->next->nbr < (*stack_a)->next->next->nbr))
	{
		if (size == 1 && (*stack_a)->nbr > (*stack_a)->next->nbr)
			sa(stack_a);
		else if (size == 1 || (size >= 2 && (*stack_b)->nbr
				> (*stack_b)->next->nbr) || (size == 3 && (*stack_b)->nbr
				> (*stack_b)->next->next->nbr))
		{
			pa(stack_a, stack_b);
			size--;
		}
		else
			sb(stack_b);
	}
}

void	qsort_check_b(t_stack **stack_a, t_stack **stack_b, int size, int count)
{
	if (!count && is_sorted_b(*stack_b, size))
	{
		while (size-- > 0)
			pa(stack_a, stack_b);
	}
	else if (size == 2)
	{
		if ((*stack_b)->nbr < (*stack_b)->next->nbr)
			sb(stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else if (size == 3)
		stack_b_process(stack_a, stack_b, size);
	else
		qsort_b(stack_a, stack_b, &size, count);
}
