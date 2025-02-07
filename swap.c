/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:26:18 by iekmen            #+#    #+#             */
/*   Updated: 2025/02/07 12:41:19 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	sa(t_stack *s)
{
	int	tmp;

	tmp = 0;
	tmp = s->a[0];
	s->a[0] = s->a[1];
	s->a[1] = tmp;
	ft_printf("sa\n");
}

void	sb(t_stack *s)
{
	int	tmp;

	tmp = 0;
	if (s->size_b < 2)
		return ;
	tmp = s->b[0];
	s->b[0] = s->b[1];
	s->b[1] = tmp;
	ft_printf("sb\n");
}

void	ss(t_stack *s)
{
	int	tmp;

	tmp = 0;
	tmp = s->a[0];
	s->a[0] = s->a[1];
	s->a[1] = tmp;
	tmp = s->b[0];
	s->b[0] = s->b[1];
	s->b[1] = tmp;
	ft_printf("ss\n");
}
