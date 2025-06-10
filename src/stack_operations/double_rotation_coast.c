/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_rotation_coast.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:13:06 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/18 10:07:53 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * rarb Calculates the cost of rotating both stack A and stack B 
 * 		upwards (ra + rb) to insert a given value from stack A 
 * 		into the correct position in stack B.
 *
 * This strategy assumes simultaneous upward rotations (ra and rb).
 * The total number  * of operations is determined by the higher number of
 * required rotations between  * stack A (to bring the value to the top) and
 * stack B (to find its insert position).
 * Return: The number of combined rotations needed (ra + rb strategy).
 */
int	rarb(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	rotations;

	rotations = ft_index_b(stack_b, value);
	if (rotations < value_index(stack_a, value))
		rotations = value_index(stack_a, value);
	return (rotations);
}

/**
 * Calculates the optimal number of reverse rotations (RRR) needed to position 
 * a given value correctly in both stack_a and stack_b.
 */
int	rrarrb(t_stack *stack_a, t_stack *stack_b, int a_value)
{
	int	rotations_b;
	int	rotations_a;
	int	insertion_index_b;
	int	value_index_a;

	rotations_b = 0;
	rotations_a = 0;
	if (!stack_a || !stack_b)
		return (0);
	insertion_index_b = ft_index_b(stack_b, a_value);
	value_index_a = value_index(stack_a, a_value);
	if (insertion_index_b > 0)
		rotations_b = stack_size(stack_b) - insertion_index_b;
	if (value_index_a > 0)
		rotations_a = stack_size(stack_a) - value_index_a;
	if (rotations_a > rotations_b)
		return (rotations_a);
	else
		return (rotations_b);
}

/**
 * rrarb - Calculates the cost of rotating stack A downwards (rra)
 *         and stack B upwards (rb) to insert a given value.
 *
 * This strategy combines:
 *   - rra: to reverse rotate stack A and bring the target value to the top.
 *   - rb: to rotate stack B so the correct insert position is at the top.
 *
 * The function computes how many operations are needed to:
 *   1. Bring the value to the top of stack A using reverse rotation.
 *   2. Rotate stack B to reach the correct insertion position.
 *
 * Return: Total number of operations for the rra + rb strategy.
 */
int	rrarb(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	rotations;

	rotations = 0;
	if (value_index(stack_a, value))
		rotations = stack_size(stack_a) - value_index(stack_a, value);
	rotations = ft_index_b(stack_b, value) + rotations;
	return (rotations);
}

/**rarrb - Calculates the cost of rotating stack A upwards (ra)
 *         and stack B downwards (rrb) to insert a given value.
 * 
 * This strategy combines:
 *   - ra: to bring the target value in stack A to the top.
 *   - rrb: to reverse rotate stack B so the correct insert position is top.
 * The function computes how many operations are needed to:
 *   1. Bring the value to the top of stack A (via value_index).
 *   2. Bring the insert position to the top of stack B (via reverse rotation).
 * Return: Total number of operations for the ra + rrb strategy.
 */
int	rarrb(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	rotations;

	rotations = 0;
	if (ft_index_b(stack_b, value))
		rotations = stack_size(stack_b) - ft_index_b(stack_b, value);
	rotations = value_index(stack_a, value) + rotations;
	return (rotations);
}
