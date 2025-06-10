/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 09:25:05 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/18 10:04:05 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * helper f() for ft_sort_a.
 */
static void	process_best_move(t_stack **a, t_stack **b)
{
	t_stack	*current_b;
	int		optimal_moves;

	current_b = *b;
	optimal_moves = rotate_stacks_ba(*a, *b);
	while (optimal_moves >= 0)
	{
		if (optimal_moves == rarb_a(*a, *b, current_b->value))
			optimal_moves = apply_rarb(a, b, current_b->value, 'b');
		else if (optimal_moves == rarrb_a(*a, *b, current_b->value))
			optimal_moves = apply_rarrb(a, b, current_b->value, 'b');
		else if (optimal_moves == rrarrb_a(*a, *b, current_b->value))
			optimal_moves = apply_rrarrb(a, b, current_b->value, 'b');
		else if (optimal_moves == rrarb_a(*a, *b, current_b->value))
			optimal_moves = apply_rrarb(a, b, current_b->value, 'b');
		else
			current_b = current_b->next;
		if (!current_b)
			break ;
	}
}

/**
 * Sorts and merges elements from stack_b back into stack_a in the correct order.
 */
t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !stack_b)
		return (stack_a);
	while (*stack_b)
		process_best_move(stack_a, stack_b);
	return (stack_a);
}
