/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:19:51 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/16 19:26:13 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	stack_size(t_stack *stack)
{
	size_t	counter;

	counter = 0;
	while (stack)
	{
		counter++;
		stack = stack->next;
	}
	return ((int)(counter));
}
