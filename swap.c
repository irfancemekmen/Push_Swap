/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 02:47:45 by iekmen            #+#    #+#             */
/*   Updated: 2026/03/30 12:08:58 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	sa(t_stack **stack)
{
	int	tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = tmp;
	ft_printf("%s\n", "sa");
}

void	sb(t_stack **stack)
{
	int	tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = tmp;
	ft_printf("%s\n", "sb");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	int	tmp;

	if (stack_a && *stack_a && (*stack_a)->next)
	{
		tmp = (*stack_a)->nbr;
		(*stack_a)->nbr = (*stack_a)->next->nbr;
		(*stack_a)->next->nbr = tmp;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		tmp = (*stack_b)->nbr;
		(*stack_b)->nbr = (*stack_b)->next->nbr;
		(*stack_b)->next->nbr = tmp;
	}
	ft_printf("%s\n", "ss");
}
