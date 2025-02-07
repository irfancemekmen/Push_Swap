/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:05:32 by iekmen            #+#    #+#             */
/*   Updated: 2025/02/07 12:41:28 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_small_a(t_stack *s)
{
	if (s->a[0] > s->a[1])
	{
		if (s->b[0] < s->b[1])
			ss(s);
		else
			sa(s);
	}
	return (1);
}

int	ft_sort_small_a2(t_stack *s, int size)
{
	while (size != 3 || !(s->a[0] < s->a[1] && s->a[1] < s->a[2]))
	{
		if (size == 3 && s->a[0] > s->a[1] && s->a[2])
		{
			if ((s->a[0] > s->a[1]) && (s->b[0] < s->b[1]))
				ss(s);
			else
				sa(s);
		}
		else if (size == 3 && !(s->a[2] > s->a[0] && s->a[2] > s->a[1]))
			size = ft_push(s, size, 0);
		else if (s->a[0] > s->a[1])
			sa(s);
		else if (size++)
			pa(s);
	}
	return (1);
}

int	ft_sort_small_b(t_stack *s, int size)
{
	if (size == 2)
	{
		if (s->b[0] < s->b[1])
			sb(s);
		pa(s);
		pa(s);
	}
	else if (size == 3)
	{
		while (size || !(s->a[0] < s->a[1] && s->a[1] < s->a[2]))
		{
			if (size == 1 && s->a[0] > s->a[1])
				sa(s);
			else if (size == 1 || (size >= 2 && s->b[0] > s->b[1]) || (size == 3
					&& s->b[0] > s->b[2]))
				size = ft_push(s, size, 1);
			else
				sb(s);
		}
	}
	return (1);
}
