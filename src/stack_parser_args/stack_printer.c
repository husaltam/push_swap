/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:10:55 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/18 10:02:57 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * stack_print f() for the stack_a and stack_b
 * 42_project ft_printf() were used as a printer function
*/
void	stack_print(t_stack *stack, const char *label)
{
	ft_printf("%s", label);
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	write(1, "\n", 1);
}
