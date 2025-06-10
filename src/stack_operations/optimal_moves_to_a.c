/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_moves_to_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:13:12 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/18 10:06:56 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * rarb_a - Calculates the cost of rotating both stack A and stack B upwards
 *                  (ra + rb) to move a value from stack B into the correct
 *		    position in stack A.
 *
 * The strategy assumes simultaneous rotations of both stacks:
 *   - ra: to bring the correct insertion position in stack A to the top.
 *   - rb: to bring the target value in stack B to the top.
 * The total number of operations is determined by the higher number of rotations
 * needed between the two stacks. *
 * Return: Total number of operations for the ra + rb strategy.
 */

int	rarb_a(t_stack *a, t_stack *b, int value)
{
	int	index_a;
	int	index_b;

	index_a = ft_index_a(a, value);
	index_b = value_index(b, value);
	if (index_a > index_b)
		return (index_a);
	else
		return (index_b);
}

/**
 * rrarrb_a - Calculates the number of reverse rotations required
 * to optimally insert a value from stack B into stack A using
 * reverse rotation on both stacks (rra and rrb).
 *
 * This function returns the maximum of:
 * - the reverse rotations needed in stack A to insert the value at the position
 * - the reverse rotations needed in stack B to bring the value to the top
 * The implementation avoids conditional structures and logical operators,
 * using bitwise operations to safely determine the maximum.
 * Return: Number of operations required using reverse-reverse strategy.
 */
int	rrarrb_a(t_stack *a, t_stack *b, int value)
{
	int	rot_a;
	int	rot_b;
	int	result;

	rot_a = stack_size(a) - ft_index_a(a, value);
	rot_b = stack_size(b) - value_index(b, value);
	result = rot_a;
	result -= (rot_a - rot_b) & ((rot_a - rot_b) >> 31);
	return (result);
}

/**
 * rarrb_a - Calculates the total number of operations needed to move a value
 *           from stack B to the correct position in stack A using:
 *           - regular rotate on stack A (ra)
 *           - reverse rotate on stack B (rrb)
 * Return: Total combined operations (ra + rrb)
 */
int	rarrb_a(t_stack *a, t_stack *b, int c)
{
	int	rot_b;

	rot_b = stack_size(b) - value_index(b, c);
	if (value_index(b, c) == 0)
		rot_b = 0;
	return (ft_index_a(a, c) + rot_b);
}

/**
 * rrarb_a - Calculates the total number of operations needed to move a value
 *           from stack B to the correct position in stack A using:
 *           - reverse rotate on stack A (rra)
 *           - regular rotate on stack B (rb)
 * Return: Total combined operations (rra + rb)
 */
int	rrarb_a(t_stack *a, t_stack *b, int c)
{
	int	rra_moves;
	int	rb_moves;

	rra_moves = stack_size(a) - ft_index_a(a, c);
	rb_moves = value_index(b, c);
	return (rra_moves + rb_moves);
}
