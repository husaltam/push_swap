/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_stacks_rotations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:12:46 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/18 10:08:36 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * ss - Simultaneously swaps the first two elements of stack A and stack B.
 *      Each stack is swapped only if it contains at least two elements.
 */
void	ss(t_stack **stack_a, t_stack **stack_b, int j)
{
	t_stack	*tmp;

	if (*stack_a && (*stack_a)->next)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = (*stack_a)->next;
		(*stack_a)->next = tmp;
	}
	if (*stack_b && (*stack_b)->next)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = (*stack_b)->next;
		(*stack_b)->next = tmp;
	}
	if (j == 0)
		write(1, "ss\n", 3);
}

/**
 * rotate_both_up - Rotates both stacks A and B upwards.
 * 
 * The first element of each stack is moved to the bottom.
 * No operation is performed if any of the stacks has fewer than 2 elements.
 */
void	rr(t_stack **stack_a, t_stack **stack_b, int j)
{
	t_stack	*tmp;

	if (!*stack_a || !(*stack_a)->next || !*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_a;
	*stack_a = ft_stack_last(*stack_a);
	(*stack_a)->next = tmp;
	*stack_a = tmp->next;
	tmp->next = NULL;
	tmp = *stack_b;
	*stack_b = ft_stack_last(*stack_b);
	(*stack_b)->next = tmp;
	*stack_b = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "rr\n", 3);
}

/**
 * helper f() for rrr()
*/
void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

/**
 * Performs reverse rotate on both stacks A and B simultaneously
 * @param j Print flag (0 = print operation)
 */
void	rrr(t_stack **a, t_stack **b, int j)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (j == 0)
		write(1, "rrr\n", 4);
}
