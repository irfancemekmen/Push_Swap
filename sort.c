/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:05:19 by iekmen            #+#    #+#             */
/*   Updated: 2025/02/07 12:41:26 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	ft_is_sorted(int *stack_a, int size, int flag)
{
	int	i;

	i = 0;
	while ((flag == 0) && (++i < size))
	{
		if (stack_a[i - 1] > stack_a[i])
			return (0);
	}
	while ((flag == 1) && (++i < size))
	{
		if (stack_a[i - 1] < stack_a[i])
			return (0);
	}
	return (1);
}

void	ft_sort(t_stack *stack, int size)
{
	if (ft_is_sorted(stack->a, stack->size_a, 0) == 0)
	{
		if (size == 2)
			sa(stack);
		else if (size == 3)
			ft_sort_three(stack);
		else
			ft_first_seperation(stack, size);
	}
}

void	ft_check_repeat(t_stack *stack, int size, char **av, int ctrl)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (stack->a[i] == stack->a[j])
				ft_free_av(av, stack, ctrl);
			j++;
		}
		i++;
		j = i + 1;
	}
}
