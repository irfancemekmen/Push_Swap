/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:05:42 by iekmen            #+#    #+#             */
/*   Updated: 2025/02/07 12:41:48 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_push_swap(char **av, int ctrl)
{
	t_stack	*stack;
	int		size;
	int		i;

	i = -1;
	stack = malloc(sizeof(t_stack));
	size = ft_ps_strlen(av);
	stack->a = malloc(sizeof(int) * size);
	if (!stack->a)
		return ;
	stack->size_a = size;
	stack->b = malloc(sizeof(int) * size);
	if (!stack->b)
	{
		free(stack->a);
		return ;
	}
	stack->size_b = 0;
	while (++i < size)
		stack->a[i] = ft_ps_atoi(av[i], stack, av, ctrl);
	ft_check_repeat(stack, size, av, ctrl);
	ft_sort(stack, size);
	free(stack->a);
	free(stack->b);
	free(stack);
}

static int	check_space(char *str)
{
	int	i;

	i = 0;
	if ((str[0] < '0' || str[0] > '9') && str[0] != '-' && str[0] != '+')
		return (0);
	while (str[i])
	{
		if (str[i] == '-' && (str[i + 1] < '0' || str[i + 1] > '9'))
			return (0);
		else if (str[i] == '+' && (str[i + 1] < '0' || str[i + 1] > '9'))
			return (0);
		else if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-'
			|| str[i] == '+')
			i++;
		else if (str[i] == ' ' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
			i++;
		else if (str[i] == ' ' && (str[i + 1] == '-' || str[i + 1] == '+'))
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac == 2)
	{
		i = 1;
		if (check_space(av[i]) == 0)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		av = ft_split(av[i], ' ');
		ft_push_swap(av, 2);
		i = 0;
		while (av[i])
		{
			free(av[i]);
			i++;
		}
		free(av);
	}
	else
		ft_push_swap(++av, 1);
	return (0);
}
