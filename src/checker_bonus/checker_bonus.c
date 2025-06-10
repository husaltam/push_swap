/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:39:05 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/18 13:19:27 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * Prints an error message to stderr and exits the program.
 * Used to handle invalid instructions or input errors.
 */
void	ft_error_ch(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

/**
 * Executes a stack manipulation instruction based on the input line.
 * 
 * @param line The instruction line to parse (e.g., "sa\n", "pb\n").
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 *
 * If the instruction is not recognized, the program exits with an error.
 */
void	execute_instruction(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(a, 1);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(b, 1);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(a, b, 1);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(a, b, 1);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(a, b, 1);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(a, 1);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(b, 1);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(a, b, 1);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(a, 1);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(b, 1);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(a, b, 1);
	else
		ft_error_ch();
}

/**
 * Reads and executes stack instructions from standard input.
 * 
 * Continues reading and executing instructions until EOF.
 * Prints "OK" if stack A is sorted and stack B is empty; otherwise prints "KO".
 * 
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 */
void	run_checker(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(0);
			continue ;
		}
		execute_instruction(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	if (*b || stack_not_sorted(*a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

/**
 * Entry point for the checker program.
 * 
 * Parses arguments into stack A, checks for duplicates,
 * runs the instruction checker, and cleans up memory.
 * 
 * @param argc Argument count.
 * @param argv Argument values.
 * @return int Exit status code.
 */
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		ft_error_ch();
	a = parse_stack_args(argc, argv);
	if (!a || has_duplicates(a))
	{
		free_stack(&a);
		ft_error_ch();
	}
	run_checker(&a, &b);
	stack_print(a, "\nprinting \"STACK A\" should give values sorted:\n");
	stack_print(b, "\nprinting \"STACK B\" should be empty with no values:");
	free_stack(&a);
	free_stack(&b);
	return (0);
}
