/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:36:34 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/18 10:03:53 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * value_index - Finds the index of a given value in the stack.
 * Return: The zero-based index of the value if found, or -1 if not found.
 * Note: This function does not modify the stack structure.
 */
int	value_index(t_stack *stack, int value)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->value == value)
			return (index);
		stack = stack->next;
		index++;
	}
	return (-1);
}

/**
 * Finds the minimum value in a stack
 * @param stack_a Pointer to the top node of the stack
 * @return The smallest value found in the stack
 */
int	get_stack_min(t_stack *stack_a)
{
	int	min;

	if (!stack_a)
		return (0);
	min = stack_a->value;
	while (stack_a)
	{
		if (stack_a->value < min)
			min = stack_a->value;
		stack_a = stack_a->next;
	}
	return (min);
}

/**
 * Finds and returns the maximum value in a stack
 * @param stack Pointer to the top node of the stack
 * @return The largest value in the stack
 * @note Returns INT_MIN if stack is NULL (add #include <limits.h>)
 */
int	get_stack_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (INT_MIN);
	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}
