/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_insertion_index.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:12:03 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/18 10:07:44 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Finds the correct insertion index in stack_b for a given value from stack_a.
 * Assumes stack_b is sorted in descending order (as per push_swap rules).
 */
int	ft_index_b(t_stack *stack_b, int a_value)
{
	int		index;
	t_stack	*current;
	t_stack	*next;

	index = 0;
	if (!stack_b || !stack_b->next)
		return (0);
	current = stack_b;
	next = current->next;
	if (a_value > get_stack_max(stack_b) || a_value < get_stack_min(stack_b))
		return (value_index(stack_b, get_stack_max(stack_b)));
	while (next)
	{
		if (a_value < current->value && a_value > next->value)
			return (index + 1);
		current = current->next;
		next = current->next;
		index++;
	}
	return (0);
}

/**
 * ft_index_a - Determines the correct position index in stack A
 *                to insert a value coming from stack B.
 *
 * This function calculates where the number should be inserted in stack A
 * to maintain sorted order (assuming ascending sort):
 * 1. If the value fits between the first and last elements, it should go 
 * 	  to the top (index 0).
 * 2. If the value is smaller than the current minimum or larger than the current
 *    maximum in stack A, it should be placed after the minimum element.
 * 3. Otherwise, it iterates through stack A to find the exact spot between
 *    two nodes where the value logically fits. *
 * Return: The index in stack A where the value should be inserted.
 */
int	ft_index_a(t_stack *stack_a, int nbr_push)
{
	int		i;
	t_stack	*current;

	current = stack_a;
	i = 0;
	if (nbr_push < stack_a->value && nbr_push > ft_stack_last(stack_a)->value)
		return (0);
	if (nbr_push < get_stack_min(stack_a) || nbr_push > get_stack_max(stack_a))
		return (value_index(stack_a, get_stack_min(stack_a)));
	while (current->next)
	{
		if (current->value < nbr_push && current->next->value > nbr_push)
			return (i + 1);
		current = current->next;
		i++;
	}
	return (0);
}
