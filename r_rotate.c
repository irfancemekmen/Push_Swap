/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:26:11 by iekmen            #+#    #+#             */
/*   Updated: 2025/02/07 12:41:36 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	rra(t_stack *s)
{
	int	tmp;
	int	i;

	i = s->size_a - 1;
	tmp = s->a[i];
	while (i)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	s->a[i] = tmp;
	ft_printf("rra\n");
}

void	rrb(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->size_b > 0)
	{
		i = s->size_b - 1;
		tmp = s->b[i];
		while (i)
		{
			s->b[i] = s->b[i - 1];
			i--;
		}
		s->b[i] = tmp;
		ft_printf("rrb\n");
	}
}

void	rrr(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->size_b > 0)
	{
		i = s->size_a - 1;
		tmp = s->a[i];
		while (i)
		{
			s->a[i] = s->a[i - 1];
			i--;
		}
		s->a[i] = tmp;
		i = s->size_b - 1;
		tmp = s->b[i];
		while (i--)
			s->b[i] = s->b[i - 1];
		s->b[i] = tmp;
		ft_printf("rrr\n");
	}
}
