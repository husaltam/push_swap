/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:11:22 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/18 10:03:44 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/** 
 * push_swap - Main sorting the push_swap program:Sorts the input stack_a
 *	       using stack operations and a helper stack_b.
 * 
 * If the stack has only two elements, it swaps them if needed.
 * Otherwise, it:
 *   - Creates and fills stack_b by pushing elements from stack_a.
 *   - Sorts stack_a and reinserts elements from stack_b as needed.
 *   - Rotates stack_a to bring the smallest value to the top.
 */
void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int		i;

	*stack_b = NULL;
	if (stack_size(*stack_a) == 2)
		sa(stack_a, 0);
	else
	{
		*stack_b = create_stack_b(stack_a);
		stack_a = ft_sort_a(stack_a, stack_b);
		i = value_index(*stack_a, get_stack_min(*stack_a));
		if (i < stack_size(*stack_a) - i)
		{
			while ((*stack_a)->value != get_stack_min(*stack_a))
				ra(stack_a, 0);
		}
		else
		{
			while ((*stack_a)->value != get_stack_min(*stack_a))
				rra(stack_a, 0);
		}
	}
}
