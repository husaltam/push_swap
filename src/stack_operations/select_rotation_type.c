/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_rotation_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:11:14 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/18 10:07:02 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * rotate_stacks_ba - Determines the optimal rotation strategy
 *                     to move an element from stack B back into stack A.
 * 
 * This function evaluates four possible rotation strategies for each element in
 * stack B, in order to insert it into the correct position in stack A:
 *   - ra + rb     (rotate both)
 *   - rra + rrb   (reverse rotate both)
 *   - ra + rrb    (mixed rotation)
 *   - rra + rb    (mixed reverse rotation)
 * It computes the operation cost for each strategy applied to each value in B
 * and returns the smallest number of operations among all possibilities.
 * Return: The minimal number of operations needed from B into A.
 */
int	rotate_stacks_ba(t_stack *a, t_stack *b)
{
	int		min_cost;
	int		cost;
	t_stack	*current;

	current = b;
	min_cost = rrarrb_a(a, b, b->value);
	while (current)
	{
		cost = rarb_a(a, b, current->value);
		if (cost < min_cost)
			min_cost = cost;
		cost = rrarrb_a(a, b, current->value);
		if (cost < min_cost)
			min_cost = cost;
		cost = rarrb_a(a, b, current->value);
		if (cost < min_cost)
			min_cost = cost;
		cost = rrarb_a(a, b, current->value);
		if (cost < min_cost)
			min_cost = cost;
		current = current->next;
	}
	return (min_cost);
}

/**
 *rotate_stacks_ab - Determines the minimum rotation cost to push an element
 * 		     from stack A to the correct position in stack B.
 * 
 * This function evaluates all possible rotation strategies for each element
 * in stack A to be pushed into stack B. The strategies include:
 *   - ra + rb     (rotate both)
 *   - rra + rrb   (reverse rotate both)
 *   - ra + rrb    (mixed rotation)
 *   - rra + rb    (mixed reverse rotation)
 * It computes the cost of each strategy for every element in stack A,
 * and returns the minimal cost found.
 * Return: The minimum rotation cost among all strategies for all elements.
 */
int	rotate_stacks_ab(t_stack *stack_a, t_stack *stack_b)
{
	int		min_cost;
	int		cost;
	t_stack	*current;

	current = stack_a;
	min_cost = rrarrb(stack_a, stack_b, current->value);
	while (current)
	{
		cost = rarb(stack_a, stack_b, current->value);
		if (cost < min_cost)
			min_cost = cost;
		cost = rrarrb(stack_a, stack_b, current->value);
		if (cost < min_cost)
			min_cost = cost;
		cost = rarrb(stack_a, stack_b, current->value);
		if (cost < min_cost)
			min_cost = cost;
		cost = rrarb(stack_a, stack_b, current->value);
		if (cost < min_cost)
			min_cost = cost;
		current = current->next;
	}
	return (min_cost);
}
