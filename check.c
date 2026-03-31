/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 02:46:42 by iekmen            #+#    #+#             */
/*   Updated: 2026/03/30 17:32:58 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	check_one_argument(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] == '-' || s[i] == '+') && s[i + 1] >= '0' && s[i + 1] <= '9')
			i++;
		else if ((s[i] >= '0' && s[i] <= '9') && ((s[i + 1] >= '0'
					&& s[i + 1] <= '9') || s[i + 1] == ' ' || !s[i + 1]))
			i++;
		else if (s[i] == ' ' && (s[i + 1] == ' ' || s[i + 1] == '-'
				|| s[i + 1] == '+' || !s[i + 1]))
			i++;
		else if (s[i] == ' ' && s[i + 1] >= '0' && s[i + 1] <= '9')
			i++;
		else
			error_handle("Argument error!");
	}
}

void	check_arguments(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if ((s[i][j] == '-' || s[i][j] == '+') && s[i][j + 1] >= '0'
				&& s[i][j + 1] <= '9')
				j++;
			else if ((s[i][j] >= '0' && s[i][j] <= '9') && ((s[i][j + 1] >= '0'
				&& s[i][j + 1] <= '9') || s[i][j + 1] == ' ' || !s[i][j + 1]))
				j++;
			else if (s[i][j] == ' ' && (s[i][j + 1] == ' '
				|| s[i][j + 1] == '-' || s[i][j + 1] == '+' || !s[i][j + 1]
				|| (s[i][j + 1] >= '0' && s[i][j + 1] <= '9')))
				j++;
			else
				error_handle("Argument error!");
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
			{
				stack_clear(stack);
				error_handle("Error: Duplicate numbers!");
			}
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
