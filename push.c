/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:26:05 by iekmen            #+#    #+#             */
/*   Updated: 2025/02/07 12:41:43 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	pa(t_stack *s)
{
	int	i;

	if (s->size_b)
	{
		s->size_a++;
		i = s->size_a;
		while (--i > 0)
			s->a[i] = s->a[i - 1];
		s->a[0] = s->b[0];
		i = -1;
		s->size_b--;
		while (++i < s->size_b)
			s->b[i] = s->b[i + 1];
		ft_printf("pa\n");
	}
}

void	pb(t_stack *s)
{
	int	i;

	i = 0;
	if (s->size_a)
	{
		s->size_b++;
		i = s->size_b;
		while (--i > 0)
			s->b[i] = s->b[i - 1];
		s->b[0] = s->a[0];
		i = -1;
		s->size_a--;
		while (++i < s->size_a)
			s->a[i] = s->a[i + 1];
		ft_printf("pb\n");
	}
}
