/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:00:00 by iekmen            #+#    #+#             */
/*   Updated: 2026/03/07 03:37:31 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static void	ft_sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->nbr;
	second = stack->next->nbr;
	third = stack->next->next->nbr;
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

static int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_start_sorting(t_stack *stack)
{
	int	size;
	t_stack	*tmp;

	tmp = stack;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	if (is_sorted(stack))
		return ;
	else if (size == 2)
		sa(stack);
	else if (size == 3)
		ft_sort_three(stack);
	else
		ft_first_seperation(stack, size);
}

static void	free_arg(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_printf("Argument error!\n");
		return (0);
	}
	else if (ac == 2)
	{
		check_one_argument(av[1]);
		av = ft_split(av[1], ' ');
		add_to_linked_list(av);
		free_arg(av);
	}
	else
	{
		check_arguments(av + 1);
		add_to_linked_list(av + 1);
	}
	return (0);
}
