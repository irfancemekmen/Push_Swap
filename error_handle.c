/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 03:30:34 by iekmen            #+#    #+#             */
/*   Updated: 2026/03/30 12:06:33 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
