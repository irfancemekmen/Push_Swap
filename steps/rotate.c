/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 02:53:05 by iekmen            #+#    #+#             */
/*   Updated: 2026/03/14 01:45:37 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../ft_printf/ft_printf.h"

void	ra(t_stack **stack)
{
	t_stack	*tmp;
	int		first_nbr;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	first_nbr = tmp->nbr;
	while (tmp->next)
	{
		tmp->nbr = tmp->next->nbr;
		tmp = tmp->next;
	}
	tmp->nbr = first_nbr;
	ft_printf("ra\n");
}

void	rb(t_stack **stack)
{
	t_stack	*tmp;
	int		first_nbr;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	first_nbr = tmp->nbr;
	while (tmp->next)
	{
		tmp->nbr = tmp->next->nbr;
		tmp = tmp->next;
	}
	tmp->nbr = first_nbr;
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		first_nbr_a;
	int		first_nbr_b;

	if ((!stack_a || !*stack_a || !(*stack_a)->next) || (!stack_b || !*stack_b
			|| !(*stack_b)->next))
		return ;
	tmp_a = *stack_a;
	tmp_b = *stack_b;
	first_nbr_a = tmp_a->nbr;
	first_nbr_b = tmp_b->nbr;
	while (tmp_a->next)
	{
		tmp_a->nbr = tmp_a->next->nbr;
		tmp_a = tmp_a->next;
	}
	while (tmp_b->next)
	{
		tmp_b->nbr = tmp_b->next->nbr;
		tmp_b = tmp_b->next;
	}
	tmp_a->nbr = first_nbr_a;
	tmp_b->nbr = first_nbr_b;
	ft_printf("rr\n");
}
