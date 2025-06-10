/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:12:39 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/18 10:08:51 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * pb - Push the top element from stack_a to stack_b.
 * Removes the top node from stack_a and places it on top of stack_b.
 * Optionally prints "pb" to stdout if print_flag == 0.
 */
void	pb(t_stack **stack_a, t_stack **stack_b, int print_flag)
{
	t_stack	*top_node;

	if (!stack_a || !*stack_a)
		return ;
	top_node = *stack_a;
	*stack_a = top_node->next;
	top_node->next = *stack_b;
	*stack_b = top_node;
	if (print_flag == 0)
		write(STDOUT_FILENO, "pb\n", 3);
}

/**
 * sb - Swap the first two elements at the top of stack B.
 *      Does nothing if the stack has fewer than two elements.
 */
void	sb(t_stack **stack_b, int j)
{
	t_stack	*tmp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	if (j == 0)
		write(1, "sb\n", 3);
}

/**
 * rb - Rotates stack B upwards.
 *      The first element becomes the last.
 */
void	rb(t_stack **stack_b, int j)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	*stack_b = first->next;
	first->next = NULL;
	last = ft_stack_last(*stack_b);
	last->next = first;
	if (j == 0)
		write(1, "rb\n", 3);
}

/**
 * rrb - Performs a reverse rotation on stack B.
 *       Moves the last element of the stack to the top.
 */
void	rrb(t_stack **stack_b, int print_flag)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	prev = NULL;
	last = *stack_b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	if (print_flag == 0)
		write(1, "rrb\n", 4);
}
