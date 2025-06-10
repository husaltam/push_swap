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
 * exit and stops the operations when found any errors
 * print error message
*/
void	exit_with_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}
