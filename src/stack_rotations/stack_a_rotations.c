/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:12:13 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/18 10:08:43 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * pa - Pushes the top element from stack B to stack A.
 *      Does nothing if stack B is empty.
 */
void	pa(t_stack **stack_a, t_stack **stack_b, int j)
{
	t_stack	*tmp;

	if (!*stack_b)
		return ;
	tmp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = tmp;
	if (j == 0)
		write(1, "pa\n", 3);
}

/**
 * sa - Swaps the first two elements at the top of stack A.
 *      Does nothing if the stack has fewer than two elements.
 */
void	sa(t_stack **stack_a, int j)
{
	t_stack	*tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	if (j == 0)
		write(1, "sa\n", 3);
}

/**
 * ra - Rotates stack A upwards by one, the first element becomes
 	the last one.
 * 	Does nothing if the stack has fewer than two elements.
 */
void	ra(t_stack **stack_a, int j)
{
	t_stack	*first;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	ft_stack_last(*stack_a)->next = first;
	first->next = NULL;
	if (j == 0)
		write(1, "ra\n", 3);
}

/**
 * rra - Reverse rotates stack A.
 *       The last element becomes the first one.
 *       Does nothing if the stack has fewer than two elements.
 */
void	rra(t_stack **stack_a, int j)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	prev = NULL;
	last = *stack_a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	if (j == 0)
		write(1, "rra\n", 4);
}
