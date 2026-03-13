/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 00:23:17 by iekmen            #+#    #+#             */
/*   Updated: 2026/03/14 01:31:14 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	not_three_size(t_stack **stack_a, t_stack **stack_b, int size)
{
	while (size != 3 || !((*stack_a)->nbr < (*stack_a)->next->nbr && (*stack_a)->next->nbr < (*stack_a)->next->next->nbr))
	{
		if (size == 3 && (*stack_a)->nbr > (*stack_a)->next->nbr)
		{
			if ((*stack_a)->nbr > (*stack_a)->next->nbr && (*stack_b)->nbr < (*stack_b)->next->nbr)
				ss(stack_a, stack_b);
			else
				sa(stack_a);
		}
		else if (size == 3 && !((*stack_a)->next->next->nbr > (*stack_a)->nbr && (*stack_a)->next->next->nbr > (*stack_a)->next->nbr))
		{
			pb(stack_a, stack_b);
			size--;
		}
		else if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			sa(stack_a);
		else if (size++)
			pa(stack_a, stack_b);
	}
}

void	ft_bubble_sort(int *tmp_stack, int size)
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
	ft_bubble_sort(tmp, i);
	*pivot = tmp[i / 2];
	free(tmp);
}

void	qsort_a(t_stack **stack_a, t_stack **stack_b, int *size, int *count)
{
	int	i;
	int	pivot;

	get_pivot(*stack_a, *size, &pivot);
	i = *size;
	while (*size != i / 2 + i % 2)
	{
		if ((*stack_a)->nbr < pivot)
		{
			pb(stack_a, stack_b);
			(*size)--;
		}
		else
		{
			ra(stack_a);
			(*count)++;
		}
	}
	while (*count > 0)
	{
		rra(stack_a);
		(*count)--;
	}
	qsort_check_a(stack_a, stack_b, i / 2 + i % 2, 0);
	qsort_check_b(stack_a, stack_b, i / 2, 0);
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

void	qsort_check_a(t_stack **stack_a, t_stack **stack_b, int size, int count)
{
	if (is_sorted(*stack_a))
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
			not_three_size(stack_a, stack_b, size);
		return ;
	}
	else
		qsort_a(stack_a, stack_b, &size, &count);
}

void	qsort_b(t_stack **stack_a, t_stack **stack_b, int *size, int *count)
{
	int	i;
	int	pivot;

	get_pivot(*stack_b, *size, &pivot);
	i = *size;
	while (*size != i / 2)
	{
		if ((*stack_b)->nbr >= pivot)
		{
			pa(stack_a, stack_b);
			(*size)--;
		}
		else
		{
			rb(stack_b);
			(*count)++;
		}
	}
	while (*count > 0)
	{
		rrb(stack_b);
		(*count)--;
	}
	qsort_check_a(stack_a, stack_b, i / 2 + i % 2, 0);
	qsort_check_b(stack_a, stack_b, i / 2, 0);
}

void	stack_b_process(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
	{
		if ((*stack_b)->nbr < (*stack_b)->next->nbr)
			sb(stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else if (size == 3)
	{
		while (size || !((*stack_a)->nbr < (*stack_a)->next->nbr && (*stack_a)->next->nbr < (*stack_a)->next->next->nbr))
		{
			if (size == 1 && (*stack_a)->nbr > (*stack_a)->next->nbr)
				sa(stack_a);
			else if (size == 1 || (size >= 2 && (*stack_b)->nbr > (*stack_b)->next->nbr) || (size == 3
					&& (*stack_b)->nbr > (*stack_b)->next->next->nbr))
			{
				pa(stack_a, stack_b);
				size--;
			}
			else
				sb(stack_b);
		}
	}
}

void	qsort_check_b(t_stack **stack_a, t_stack **stack_b, int size, int count)
{
	if (!count && is_sorted(*stack_b))
	{
		while (size-- > 0)
			pa(stack_a, stack_b);
	}
	else if (size <= 3)
		stack_b_process(stack_a, stack_b, size);
	else
		qsort_b(stack_a, stack_b, &size, &count);
}
