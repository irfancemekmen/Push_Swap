/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 03:30:34 by iekmen            #+#    #+#             */
/*   Updated: 2026/03/30 17:05:56 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>

void	error_handle(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

void	free_arg(char **av)
{
	int	i;

	if (!av)
		return ;
	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	free_splitted(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

void	free_helper(t_stack *stack, char **av, char **splitted, int flag)
{
	free_splitted(splitted);
	stack_clear(stack);
	if (flag == 1)
		free_arg(av);
	error_handle("Error!");
}
