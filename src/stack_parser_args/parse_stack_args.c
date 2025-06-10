/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:12:54 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/18 10:05:08 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * ft_free_split - Frees a NULL-terminated array of strings.
 */
void	ft_free_split(char **split_args)
{
	int	i;

	if (!split_args)
		return ;
	i = 0;
	while (split_args[i])
	{
		free(split_args[i]);
		i++;
	}
	free(split_args);
}

/**
 * parse_single_arg - Parses a single string argument containing space-separated
 *                    integers and builds a linked stack from them.
 */
t_stack	*parse_single_arg(char **argv)
{
	t_stack	*stack_a;
	char	**split_args;
	int		i;
	int		value;

	stack_a = NULL;
	i = 0;
	if (!argv[1] || argv[1][0] == '\0')
		exit_with_error();
	split_args = ft_split(argv[1], ' ');
	if (!split_args || !split_args[0])
	{
		ft_free_split(split_args);
		exit_with_error();
	}
	while (split_args[i])
	{
		value = ft_atoi(split_args[i]);
		ft_stackadd_back(&stack_a, ft_stack_new(value));
		i++;
	}
	ft_free_split(split_args);
	return (stack_a);
}

/**
 * parse_stack_args - Parses command-line arguments to build the initial stack.
 *                    Supports both single quoted string
 *                    and multiple arguments (e.g., "./a.out 1 2 3").
 */
t_stack	*parse_stack_args(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		value;

	stack_a = NULL;
	i = 1;
	if (argc < 2)
		return (NULL);
	if (argc == 2)
	{
		stack_a = parse_single_arg(argv);
	}
	else
	{
		while (i < argc)
		{
			value = ft_atoi(argv[i]);
			ft_stackadd_back(&stack_a, ft_stack_new(value));
			i++;
		}
	}
	return (stack_a);
}
