/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_three_nbrs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:11:48 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/18 10:07:27 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Sorts a 3-element stack with minimal operations
 * Case 1: min first → rra + sa
 * Case 2: max first → ra (+ sa if needed)
 * Case 3: mid first → check max position
 */
void	sort_a_three_nbrs(t_stack **stack_a)
{
	if (get_stack_min(*stack_a) == (*stack_a)->value)
	{
		rra(stack_a, 0);
		sa(stack_a, 0);
	}
	else if (get_stack_max(*stack_a) == (*stack_a)->value)
	{
		ra(stack_a, 0);
		if (stack_not_sorted(*stack_a))
			sa(stack_a, 0);
	}
	else
	{
		if (value_index(*stack_a, get_stack_max(*stack_a)) == 1)
			rra(stack_a, 0);
		else
			sa(stack_a, 0);
	}
}
