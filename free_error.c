/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:05:54 by iekmen            #+#    #+#             */
/*   Updated: 2025/02/07 12:41:53 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_free_av(char **av, t_stack *stack, int ctrl)
{
	int	a;

	a = 0;
	if (ctrl == 2)
	{
		while (av[a])
		{
			free(av[a]);
			a++;
		}
		free(av);
	}
	ft_error(stack);
}

void	ft_error(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack);
	write(2, "Error\n", 6);
	exit(1);
}
