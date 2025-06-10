/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_apply_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:11:08 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/18 10:07:36 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * apply_rarb - Applies the "ra + rb" rotation strategy to move a number
 *                 from one stack to the other using simultaneous rotations
 *                 when possible (ft_rr), followed by remaining rotations.
 *
 * @nbr:	The value to move.
 * @stack:	Character to determine direction: 'a' for A → B, 'b' for B → A.
 * Return always -1 (used for compatibility).
 */
int	apply_rarb(t_stack **stack_a, t_stack **stack_b, int nbr, char stack)
{
	if (stack == 'a')
	{
		while ((*stack_a)->value != nbr
			&& ft_index_b(*stack_b, nbr) > 0)
			rr(stack_a, stack_b, 0);
		while ((*stack_a)->value != nbr)
			ra(stack_a, 0);
		while (ft_index_b(*stack_b, nbr) > 0)
			rb(stack_b, 0);
		pb(stack_a, stack_b, 0);
	}
	else
	{
		while ((*stack_b)->value != nbr && ft_index_a(*stack_a, nbr) > 0)
			rr(stack_a, stack_b, 0);
		while ((*stack_b)->value != nbr)
			rb(stack_b, 0);
		while (ft_index_a(*stack_a, nbr) > 0)
			ra(stack_a, 0);
		pa(stack_a, stack_b, 0);
	}
	return (-1);
}

/**
 * Applies reverse rotate (rrr + rra/rrb) to align and push `nbr` between stacks.
 *
 * If `stack` is 'a': moves `nbr` from stack A to B.
 * If `stack` is 'b': moves `nbr` from stack B to A.
 *
 * Steps:
 * 1. Use `rrr` to rotate both stacks.
 * 2. Finish with individual `rra`/`rrb` if needed.
 * 3. Push `nbr` to target stack (`pb` or `pa`).
 *
 * @return Always -1 (placeholder).
 */
int	apply_rrarrb(t_stack **stack_a, t_stack **stack_b, int nbr, char stack)
{
	if (stack == 'a')
	{
		while ((*stack_a)->value != nbr && ft_index_b(*stack_b, nbr) > 0)
			rrr(stack_a, stack_b, 0);
		while ((*stack_a)->value != nbr)
			rra(stack_a, 0);
		while (ft_index_b(*stack_b, nbr) > 0)
			rrb(stack_b, 0);
		pb(stack_a, stack_b, 0);
	}
	else
	{
		while ((*stack_b)->value != nbr && ft_index_a(*stack_a, nbr) > 0)
			rrr(stack_a, stack_b, 0);
		while ((*stack_b)->value != nbr)
			rrb(stack_b, 0);
		while (ft_index_a(*stack_a, nbr) > 0)
			rra(stack_a, 0);
		pa(stack_a, stack_b, 0);
	}
	return (-1);
}

/**
 * Apply reverse rotation on source stack and forward rotation on destination
 * stack to position `nbr` correctly before pushing.
 */
int	apply_rrarb(t_stack **stack_a, t_stack **stack_b, int nbr, char s)
{
	if (s == 'a')
	{
		while ((*stack_a)->value != nbr)
			rra(stack_a, 0);
		while (ft_index_b(*stack_b, nbr) > 0)
			rb(stack_b, 0);
		pb(stack_a, stack_b, 0);
	}
	else if (s == 'b')
	{
		while (ft_index_a(*stack_a, nbr) > 0)
			rra(stack_a, 0);
		while ((*stack_b)->value != nbr)
			rb(stack_b, 0);
		pa(stack_a, stack_b, 0);
	}
	return (-1);
}

/**
 * Performs a combination of rotate and reverse-rotate operations to move
 * a number between stack_a and stack_b, depending on the specified stack.
 *
 * @param nbr      The number to be moved between stacks
 * @param s        Specifies which stack we're moving from ('a')
 * @return         Always returns -1 (convention for operation counting)
 */
int	apply_rarrb(t_stack **stack_a, t_stack **stack_b, int nbr, char s)
{
	if (s == 'a')
	{
		while ((*stack_a)->value != nbr)
			ra(stack_a, 0);
		while (ft_index_b(*stack_b, nbr) > 0)
			rrb(stack_b, 0);
		pb(stack_a, stack_b, 0);
	}
	else
	{
		while (ft_index_a(*stack_a, nbr) > 0)
			ra(stack_a, 0);
		while ((*stack_b)->value != nbr)
			rrb(stack_b, 0);
		pa(stack_a, stack_b, 0);
	}
	return (-1);
}
