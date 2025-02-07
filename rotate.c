/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:26:15 by iekmen            #+#    #+#             */
/*   Updated: 2025/02/07 12:41:34 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	ra(t_stack *s)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = s->a[i];
	i++;
	while (i < s->size_a)
	{
		s->a[i - 1] = s->a[i];
		i++;
	}
	s->a[i - 1] = tmp;
	ft_printf("ra\n");
}

void	rb(t_stack *s)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = s->b[i];
	i++;
	while (i < s->size_b)
	{
		s->b[i - 1] = s->b[i];
		i++;
	}
	s->b[i - 1] = tmp;
	ft_printf("rb\n");
}

void	rr(t_stack *s)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = s->a[i];
	while (++i < s->size_a)
		s->a[i - 1] = s->a[i];
	s->a[i - 1] = tmp;
	i = 0;
	tmp = s->b[i];
	while (++i < s->size_b)
		s->b[i - 1] = s->b[i];
	s->b[i - 1] = tmp;
	ft_printf("rr\n");
}
