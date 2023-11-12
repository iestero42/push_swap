/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:20:48 by iestero-          #+#    #+#             */
/*   Updated: 2023/08/11 10:52:27 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/**
 * Funtion that takes the first element of the stack_b and put it at the top
 * of stack_a
 * @param stack_a the stack where the new element goes
 * @param stack_b the stack that gives the element to the other stack
 */
void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;

	if (!stack_b || !(*stack_b))
		return ;
	head = *stack_b;
	*stack_b = head->next;
	head -> next = *stack_a;
	*stack_a = head;
	ft_putstr_fd("pa\n", 1);
}

/**
 * Funtion that takes the first element of the stack_a and put it at the top
 * of stack_b
 * @param stack_b the stack where the new element goes
 * @param stack_a the stack that gives the element to the other stack
 */
void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;

	if (!stack_a || !(*stack_a))
		return ;
	head = *stack_a;
	*stack_a = head->next;
	head -> next = *stack_b;
	*stack_b = head;
	ft_putstr_fd("pb\n", 1);
}
