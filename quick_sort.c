/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:05:38 by iekmen            #+#    #+#             */
/*   Updated: 2025/02/07 12:41:41 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_first_seperation(t_stack *stack, int size)
{
	int	pivot_a;
	int	pivot_b;
	int	i;

	pivot_a = 0;
	pivot_b = 0;
	i = size;
	ft_get_middle(&pivot_a, stack->a, size);
	while (size != i / 2 + i % 2)
	{
		if (stack->a[0] < pivot_a && (size--))
			pb(stack);
		else if (stack->size_b > 2)
		{
			ft_get_middle(&pivot_b, stack->b, stack->size_b);
			if (stack->b[0] <= pivot_b)
				rr(stack);
			else
				ra(stack);
		}
		else
			ra(stack);
	}
	ft_quicksort_a(stack, i / 2 + i % 2, 0);
	ft_quicksort_b(stack, i / 2, 0);
}

int	ft_quicksort_a(t_stack *stack, int size, int count)
{
	int	pivot_a;
	int	i;

	if (ft_is_sorted(stack->a, size, 0) == 1)
		return (1);
	if (size == 2)
		return (ft_sort_small_a(stack));
	else if (size == 3 && stack->size_a == 3)
		return (ft_sort_three(stack));
	else if (size == 3)
		return (ft_sort_small_a2(stack, size));
	ft_get_middle(&pivot_a, stack->a, size);
	i = size;
	while (size != i / 2 + i % 2)
	{
		if (stack->a[0] < pivot_a && (size--))
			pb(stack);
		else if (++count)
			ra(stack);
	}
	while (i / 2 + i % 2 != stack->size_a && count--)
		rra(stack);
	return (ft_quicksort_a(stack, i / 2 + i % 2, 0), ft_quicksort_b(stack, i
			/ 2, 0));
}

int	ft_quicksort_b(t_stack *stack, int size, int count)
{
	int	pivot_b;
	int	i;

	if (!count && ft_is_sorted(stack->b, size, 1) == 1)
		while (size--)
			pa(stack);
	if (size <= 3)
		return (ft_sort_small_b(stack, size));
	ft_get_middle(&pivot_b, stack->b, size);
	i = size;
	while (size != i / 2)
	{
		if (stack->b[0] >= pivot_b && (size--))
			pa(stack);
		else if (++count)
			rb(stack);
	}
	while (i / 2 != stack->size_b && count--)
		rrb(stack);
	return (ft_quicksort_a(stack, i / 2 + i % 2, 0), ft_quicksort_b(stack, i
			/ 2, 0));
	return (1);
}
