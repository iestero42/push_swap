/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:35:39 by iestero-          #+#    #+#             */
/*   Updated: 2023/08/11 11:37:05 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SUCCESS_EXIT 1
# define FAILURE_EXIT 0

# define VALUE 0
# define INDEX 1
# define POS 2
# define TARGET_POS 3
# define COST_A 4
# define COST_B 5

# include "linked_list.h"
# include "ft_printf.h"
# include "operations.h"
# include "utils.h"

int		ft_is_sorted(t_list *list);

void	sort_three_elements(t_list **stack);

void	sort(t_list **stack_a, t_list **stack_b);

void	assign_index(t_list *stack_a, int stack_size);

void	execute_optimal_move(t_list **stack_a, t_list **stack_b);

void	calculate_moves(t_list **stack_a, t_list **stack_b);

void	assign_best_position(t_list **a, t_list **b);

int		find_min_index_position(t_list **stack);

void	move_element(t_list **a, t_list **b, long long int cost_a,
			long long int cost_b);

#endif
