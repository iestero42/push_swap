/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:02:36 by marvin            #+#    #+#             */
/*   Updated: 2023/03/29 15:02:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_BONUS_H
# define OPERATION_BONUS_H

# include "linked_list.h"
# include "libft.h"

void	pa(t_list **stack_a, t_list **stack_b);

void	pb(t_list **stack_a, t_list **stack_b);

void	ra(t_list **stack);

void	rb(t_list **stack);

void	rr(t_list **stack_a, t_list **stack_b);

void	rra(t_list **stack);

void	rrb(t_list **stack);

void	rrr(t_list **stack_a, t_list **stack_b);

void	sa(t_list **stack);

void	sb(t_list **stack);

void	ss(t_list **stack_a, t_list **stack_b);

#endif