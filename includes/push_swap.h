/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:10:55 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/17 20:04:01 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct stack_node
{
	long				value;
	long				index;
	struct stack_node	*next;
}	t_stack;

/****************
 *libft functions
*/
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		stack_size(t_stack *stack);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	*ft_calloc(unsigned int count, unsigned int size);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
t_stack	*ft_stack_last(t_stack *stack);
t_stack	*ft_stack_new(long content);

/***************************
 *parse_stack_args functions
*/
int		has_duplicates(t_stack *stack);
int		stack_not_sorted(t_stack *stack_a);
void	exit_with_error(void);
void	free_stack(t_stack **stack);
void	ft_free_split(char **split_args);
void	stack_print(t_stack *stack, const char *label);
t_stack	*parse_single_arg(char **argv);
t_stack	*parse_stack_args(int argc, char **argv);

/**************************
 *pushswap_solver functions
*/
int		value_index(t_stack *stack, int value);
int		get_stack_min(t_stack *stack_a);
int		get_stack_max(t_stack *stack);
void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	optimized_push_to_b(t_stack **stack_a, t_stack **stack_b);
bool	apply_strategy(t_stack **a, t_stack **b, int cost, int value);
t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b);
t_stack	*create_stack_b(t_stack **stack_a);

/***************************
 *stack_operations functions
*/
void	sort_a_three_nbrs(t_stack **stack_a);
int		rarb(t_stack *stack_a, t_stack *stack_b, int value);
int		rrarrb(t_stack *stack_a, t_stack *stack_b, int a_value);
int		rrarb(t_stack *stack_a, t_stack *stack_b, int value);
int		rarrb(t_stack *stack_a, t_stack *stack_b, int value);
int		rarb_a(t_stack *a, t_stack *b, int value);
int		rrarrb_a(t_stack *a, t_stack *b, int value);
int		rarrb_a(t_stack *a, t_stack *b, int c);
int		rrarb_a(t_stack *a, t_stack *b, int c);
int		rotate_stacks_ba(t_stack *a, t_stack *b);
int		rotate_stacks_ab(t_stack *stack_a, t_stack *stack_b);
int		apply_rarb(t_stack **stack_a, t_stack **stack_b, int nbr, char stack);
int		apply_rrarrb(t_stack **stack_a, t_stack **stack_b, int nbr, char stack);
int		apply_rrarb(t_stack **stack_a, t_stack **stack_b, int nbr, char s);
int		apply_rarrb(t_stack **stack_a, t_stack **stack_b, int nbr, char s);
int		ft_index_b(t_stack *stack_b, int a_value);
int		ft_index_a(t_stack *stack_a, int nbr_push);

/**************************
 *stack_rotations functions
*/
void	pa(t_stack **stack_a, t_stack **stack_b, int j);
void	sa(t_stack **stack_a, int j);
void	ra(t_stack **stack_a, int j);
void	rra(t_stack **stack_a, int j);
void	pb(t_stack **stack_a, t_stack **stack_b, int print_flag);
void	sb(t_stack **stack_b, int j);
void	rb(t_stack **stack_b, int j);
void	rrb(t_stack **stack_b, int print_flag);
void	ss(t_stack **stack_a, t_stack **stack_b, int j);
void	rr(t_stack **stack_a, t_stack **stack_b, int j);
void	reverse_rotate(t_stack **stack);
void	rrr(t_stack **a, t_stack **b, int j);

#endif
