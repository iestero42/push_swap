/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:22:40 by iestero-          #+#    #+#             */
/*   Updated: 2023/03/19 20:46:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/**
 * Function that move all the elements upward so the first element is now 
 * the last
 * @param stack where the rotation take place
 */
void	ft_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*last;

	if (ft_lstsize(*stack) < 2)
		return ;
	head = *stack;
	*stack = head->next;
	last = ft_lstlast(*stack);
	last->next = head;
	head->next = NULL;
}

void	ra(t_list **stack)
{
	if (ft_lstsize(*stack) < 2)
		return ;
	ft_rotate(stack);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_list **stack)
{
	if (ft_lstsize(*stack) < 2)
		return ;
	ft_rotate(stack);
	ft_putstr_fd("rb\n", 1);
}

/**
 * Function that do same as above but with two stacks
 * @param stack_a first stack to rotate
 * @param stack_b second stack to rotate
 */
void	rr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return ;
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
