/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:58:26 by iekmen            #+#    #+#             */
/*   Updated: 2026/03/30 17:10:53 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}					t_stack;

t_stack	*add_to_linked_list(char **av, int flag);
void	check_number_repeat(t_stack *stack);
void	start_sorting(t_stack **stack);
void	check_one_argument(char *str);
void	check_arguments(char **av);
void	error_handle(char *str);
void	stack_clear(t_stack *stack);
int		is_sorted_n(t_stack *stack, int size);
int		is_sorted_b(t_stack *stack, int size);
int		stack_size(t_stack *stack);
void	qsort_check_a(t_stack **a, t_stack **b, int size, int count);
void	qsort_check_b(t_stack **a, t_stack **b, int size, int count);
void	get_pivot(t_stack *stack, int size, int *pivot);
void	sort_three(t_stack **stack);
void	not_three_size(t_stack **stack_a, t_stack **stack_b, int *size);
void	bubble_sort(int *tmp_stack, int size);
void	is_need_double_swap(t_stack **stack_a, t_stack **stack_b);
void	free_arg(char **av);
void	free_helper(t_stack *stack, char **av, char **splitted, int flag);
void	free_splitted(char **splitted);

void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	rra(t_stack **stack);
void	rrb(t_stack **stack);

#endif
