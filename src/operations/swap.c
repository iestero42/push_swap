/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:16:17 by iestero-          #+#    #+#             */
/*   Updated: 2023/03/19 20:46:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

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
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list **stack)
{
	if (ft_lstsize(*stack) < 2)
		return ;
	ft_swap(stack);
	ft_putstr_fd("sb\n", 1);
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
	ft_putstr_fd("ss\n", 1);
}
