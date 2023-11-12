/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:24:30 by iestero-          #+#    #+#             */
/*   Updated: 2023/03/29 15:07:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation_bonus.h"

/**
 * Function that find the penultimate element in order to use as the new last
 * @param stack where the penultimate element is 
 * @return t_list* that point to the new last element
 */
t_list	*ft_new_last(t_list **stack)
{
	t_list	*prev;
	t_list	*curr;

	prev = NULL;
	curr = *stack;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	return (prev);
}

/**
 * Function that move all the element downward so the last element is now the 
 * first and vice versa
 * @param stack where the rotation is taking place
 */
void	ft_reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*new_last;
	t_list	*head;

	if (ft_lstsize(*stack) < 2)
		return ;
	last = ft_lstlast(*stack);
	new_last = ft_new_last(stack);
	head = *stack;
	*stack = last;
	last->next = head;
	new_last->next = NULL;
}

void	rra(t_list **stack)
{
	if (ft_lstsize(*stack) < 2)
		return ;
	ft_reverse_rotate(stack);
}

void	rrb(t_list **stack)
{
	if (ft_lstsize(*stack) < 2)
		return ;
	ft_reverse_rotate(stack);
}

/**
 * Function that move all the element downward so the last element is now the 
 * first and vice versad
 * @param stack_a where the rotation takes place
 * @param stack_b where the rotation takes place
 */
void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return ;
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
}
