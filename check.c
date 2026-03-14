/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 02:46:42 by iekmen            #+#    #+#             */
/*   Updated: 2026/03/14 03:30:05 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	check_one_argument(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if ((str[i] < '0' || str[i] > '9') && str[i] != '-'
			&& str[i] != '+')
			error_handle("Argument error!");
		else if (str[i] == '-' || str[i] == '+')
		{
			if (str[i + 1] < '0' || str[i + 1] > '9')
				error_handle("Argument error!");
			i++;
		}
		else
			i++;
	}
}

void	check_arguments(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		if ((av[i][0] < '0' || av[i][0] > '9') && av[i][0] != '-'
			&& av[i][0] != '+')
			error_handle("Argument error!");
		else if (av[i][0] == '-' || av[i][0] == '+')
		{
			if (av[i][1] < '0' || av[i][1] > '9')
				error_handle("Argument error!");
			j = 1;
		}
		i++;
	}
}

void	check_number_repeat(t_stack *stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = stack;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->nbr == tmp2->nbr)
				error_handle("Error: Duplicate numbers!");
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

int	is_sorted_n(t_stack *stack, int size)
{
	while (stack && stack->next && size > 1)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
		size--;
	}
	return (1);
}

int	is_sorted_b(t_stack *stack, int size)
{
	while (stack && stack->next && size > 1)
	{
		if (stack->nbr < stack->next->nbr)
			return (0);
		stack = stack->next;
		size--;
	}
	return (1);
}
