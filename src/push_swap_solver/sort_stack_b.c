/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 09:25:05 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/18 10:05:57 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * apply_strategy - Applies the most efficient rotation strategy
 * to move a value from stack A to stack B.
 *
 * This function checks all four possible rotation strategies:
 *   - ra + rb
 *   - rra + rrb
 *   - ra + rrb
 *   - rra + rb
 * Each strategy has an associated cost, and the one matching the
 * minimal cost (best_cost) is applied.
 * Return: true if a matching strategy is applied, false otherwise.
 */
bool	apply_strategy(t_stack **a, t_stack **b, int cost, int value)
{
	if (cost == rarb(*a, *b, value))
	{
		apply_rarb(a, b, value, 'a');
		return (true);
	}
	if (cost == rrarrb(*a, *b, value))
	{
		apply_rrarrb(a, b, value, 'a');
		return (true);
	}
	if (cost == rarrb(*a, *b, value))
	{
		apply_rarrb(a, b, value, 'a');
		return (true);
	}
	if (cost == rrarb(*a, *b, value))
	{
		apply_rrarb(a, b, value, 'a');
		return (true);
	}
	return (false);
}

/**
 * optimized_push_to_b - Moves elements from stack_a to stack_b until 3 remain.
 *
 * For each element, it calculates the most efficient rotation strategy
 * (ra/rb, rra/rrb, mixed cases) to insert it correctly into stack_b.
 * This minimizes total operations by choosing the best rotation case.
 * stack_a: Pointer to stack A (source stack).
 * stack_b: Pointer to stack B (target stack).
 */
void	optimized_push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int			best_cost;
	t_stack		*current;

	while (stack_size(*stack_a) > 3 && stack_not_sorted(*stack_a))
	{
		current = *stack_a;
		best_cost = rotate_stacks_ab(*stack_a, *stack_b);
		while (current)
		{
			if (apply_strategy(stack_a, stack_b, best_cost, current->value))
				break ;
			current = current->next;
		}
	}
}

/**
 * create_stack_b - Splits stack_a into two parts by moving elements to stack_b.
 * This function prepares the sorting process by:
 *   - Pushing 2+ elements from stack_a to stack_b if stack_a > 3 and unsorted.
 *   - Continuing to push until only 3 elements remain in stack_a.
 *   - Sorting the remaining 3 elements in stack_a using sort_a_three_nbrs().
 * Returns a pointer to the newly created stack_b containing the pushed elements.
 */
t_stack	*create_stack_b(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	i = 0;
	while (i++ < 2)
	{
		if (stack_size(*stack_a) > 3 && stack_not_sorted(*stack_a))
			pb(stack_a, &stack_b, 0);
	}
	if (stack_size(*stack_a) > 3 && stack_not_sorted(*stack_a))
		optimized_push_to_b(stack_a, &stack_b);
	if (stack_not_sorted(*stack_a))
		sort_a_three_nbrs(stack_a);
	return (stack_b);
}
