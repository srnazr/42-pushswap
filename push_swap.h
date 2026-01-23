/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmina <nmina@student.42beirut.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:21:46 by nmina             #+#    #+#             */
/*   Updated: 2026/01/23 14:34:20 by nmina            ###   ########.fr       */
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

int			ft_strcmp(char *s1, char *s2);
int			is_allowed_flag(char *s);
int			get_start(char **argv, int argc);
t_strategy	get_strategy(char **argv, int argc);

int			*parse_numbers(char **argv, int argc, int start);

int			check_non_digit(char *s);
int			check_all_args(char **args, int argc, int start);
int			check_duplicates_int(int *arr, int n);
void		show_error(void);
int			atoi_arg(char *str);

void		free_stack(t_stack *stack);
void		stack_pop(t_stack *stack);
int			check_sort_order(t_stack *stack);
int			get_top(t_stack *stack);

int			get_max(t_stack *stack);
int			get_max_position(t_stack *stack);
int			shortest_rotation_direction(t_stack *stack, int target_pos);

void		swap(t_stack *stack);
void		push(t_stack *from, t_stack *to);
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);

void		sa(t_stack *a);
void		sb(t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rrr(t_stack *a, t_stack *b);

double		compute_disorder(t_stack stack);
void		quick_sort(int *arr, int low, int high);
void		swap_int(int *a, int *b);

#endif
