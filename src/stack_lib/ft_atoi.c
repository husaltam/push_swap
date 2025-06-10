/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:19:51 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/16 19:25:33 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_atoi_core(const char *str, int sign, int i)
{
	long long	result;

	result = 0;
	if (!ft_isdigit(str[i]))
		exit_with_error();
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			exit_with_error();
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if ((sign == 1 && result > INT_MAX) || (sign == -1 && - result < INT_MIN))
		exit_with_error();
	return (result * sign);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;

	if (!str || *str == '\0')
		exit_with_error();
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		else
			sign = 1;
		i++;
	}
	return (ft_atoi_core(str, sign, i));
}
