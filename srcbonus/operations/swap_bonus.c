/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:16:17 by iestero-          #+#    #+#             */
/*   Updated: 2023/03/29 15:07:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation_bonus.h"

/**
 * Function that swap the first two elements in a stack 
 * @param stack where the swapping take place
 */
void	ft_swap(t_list **stack)
{
	t_list	*node_1;
	t_list	*node_2;
	t_list	*tmp;

	if (ft_lstsize(*stack) < 2)
		return ;
	node_1 = *stack;
	node_2 = (*stack)->next;
	tmp = node_2->next;
	*stack = node_2;
	node_2->next = node_1;
	node_1->next = tmp;
}

void	sa(t_list **stack)
{
	if (ft_lstsize(*stack) < 2)
		return ;
	ft_swap(stack);
}

void	sb(t_list **stack)
{
	if (ft_lstsize(*stack) < 2)
		return ;
	ft_swap(stack);
}

/**
 * Function that do the same as above but with two stacks
 * @param stack_a the first stack
 * @param stack_b the second stack
 */
void	ss(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return ;
	ft_swap(stack_a);
	ft_swap(stack_b);
}
