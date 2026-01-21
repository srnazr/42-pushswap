/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmina <nmina@student.42beirut.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:21:46 by nmina             #+#    #+#             */
/*   Updated: 2026/01/21 12:21:54 by nmina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int	*arr;
	int	size;
	int	capacity;
}	t_stack;

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

int		ft_strcmp(char *s1, char *s2);
int		is_allowed_flag(char *s);
int		get_start(char **argv, int argc);

int		*parse_numbers(char **argv, int argc, int start);

int		check_non_digit(char *s);
int		check_all_args(char **args, int argc, int start);
int		check_duplicates_int(int *arr, int n);
void	show_error(void);
int		atoi_arg(char *str);

void	free_stack(t_stack *stack);
void	stack_pop(t_stack *stack);
int		check_sort_order(t_stack *stack);
int		get_top(t_stack *stack);

int		get_max(t_stack *stack);
int		get_max_position(t_stack *stack);
int		shortest_rotation_direction(t_stack *stack, int target_pos);

void	sb(t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	rb(t_stack *stack_b);
void	rrb(t_stack *stack_b);

#endif
