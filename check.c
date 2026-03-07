/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 02:46:42 by iekmen            #+#    #+#             */
/*   Updated: 2026/03/07 03:33:03 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	check_one_argument(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
			ft_error_handle("Argument error!");
		else if (str[i] == '-' || str[i] == '+')
		{
			if (str[i + 1] < '0' || str[i + 1] > '9')
				ft_error_handle("Argument error!");
			i++;
		}
		else
			i++;
	}
}

void	check_arguments(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		if ((av[i][0] < '0' || av[i][0] > '9') && av[i][0] != '-' && av[i][0] != '+')
			ft_error_handle("Argument error!");
		else if (av[i][0] == '-' || av[i][0] == '+')
		{
			if (av[i][1] < '0' || av[i][1] > '9')
				ft_error_handle("Argument error!");
			j = 1;
		}
		i++;
	}
}

void	ft_check_number_repeat(t_stack *stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = stack;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->nbr == tmp2->nbr)
				ft_error_handle("Error: Duplicate numbers!");
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}
