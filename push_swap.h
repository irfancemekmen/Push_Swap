/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:06:13 by iekmen            #+#    #+#             */
/*   Updated: 2025/02/07 12:41:45 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}		t_stack;

void	ft_free_av(char **av, t_stack *stack, int ctrl);
void	ft_error(t_stack *stack);

void	ft_push_swap(char **av, int ctrl);

void	pa(t_stack *s);
void	pb(t_stack *s);

void	ft_first_seperation(t_stack *stack, int size);
int		ft_quicksort_a(t_stack *stack, int size, int count);
int		ft_quicksort_b(t_stack *stack, int size, int count);

void	rra(t_stack *s);
void	rrb(t_stack *s);
void	rrr(t_stack *s);

void	ra(t_stack *s);
void	rb(t_stack *s);
void	rr(t_stack *s);

int		ft_push(t_stack *stack, int size, int flag);
int		ft_sort_three(t_stack *s);
void	ft_bubble_sort(int *tmp_stack, int size);
int		ft_get_middle(int *pivot, int *stack_a, int size);

int		ft_sort_small_a(t_stack *s);
int		ft_sort_small_a2(t_stack *s, int size);
int		ft_sort_small_b(t_stack *s, int size);

int		ft_is_sorted(int *stack_a, int size, int flag);
void	ft_sort(t_stack *stack, int size);
void	ft_check_repeat(t_stack *stack, int size, char **av, int ctrl);

void	sa(t_stack *s);
void	sb(t_stack *s);
void	ss(t_stack *s);

int		ft_ps_strlen(char **str);
int		ft_ps_atoi(char *str, t_stack *stack, char **av, int ctrl);

#endif
