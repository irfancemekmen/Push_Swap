/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:00:00 by iekmen            #+#    #+#             */
/*   Updated: 2026/03/14 01:39:23 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static void	free_arg(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac < 2)
		ft_printf("Argument error!\n");
	else if (ac == 2)
	{
		check_one_argument(av[1]);
		av = ft_split(av[1], ' ');
		stack = add_to_linked_list(av);
		check_number_repeat(stack);
		start_sorting(&stack);
		stack_clear(stack);
		free_arg(av);
	}
	else
	{
		check_arguments(av + 1);
		stack = add_to_linked_list(av + 1);
		check_number_repeat(stack);
		start_sorting(&stack);
		stack_clear(stack);
	}
}
