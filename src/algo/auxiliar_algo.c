/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:51:45 by iestero-          #+#    #+#             */
/*   Updated: 2023/08/11 11:32:08 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * This function finds the highest index value in a stack and returns it.
 * It does this by iterating over the stack and comparing the index value
 * of each element with a variable that stores the current highest index.
 * @param stack The pointer to the stack.
 * @return The highest index value in the stack.
 */
static int	max_index(t_list *stack)
{
	int		index;

	index = ((long long int *) stack->content)[INDEX];
	while (stack)
	{
		if (((long long int *) stack->content)[INDEX] > index)
			index = ((long long int *) stack->content)[INDEX];
		stack = stack->next;
	}
	return (index);
}

/**
 * This function sorts three elements in a stack using only two operations:
 * sa (swap a) and ra (rotate a). It does this by using the following steps:
 * 1. Check if the stack is already sorted. If yes, return. This is done by
 *    the function ft_is_sorted.
 * 2. Find the highest index value in the stack. This is done by the function
 *    find_highest_index.
 * 3. If the highest index element is at the top of the stack, rotate the
 *    stack so that it goes to the bottom. This is done by the operation ra.
 * 4. If the highest index element is at the bottom of the stack, reverse
 *    rotate the stack so that it goes to the top. This is done by the
 *    operation rra.
 * 5. If the first two elements of the stack have their index values in
 *    descending order, swap them. This is done by the operation sa.
 *
 * @param stack The pointer to the stack.
 */
void	sort_three_elements(t_list **stack)
{
	int		highest;

	if (ft_is_sorted(*stack))
		return ;
	highest = max_index(*stack);
	if (((long long int *)(*stack)->content)[INDEX] == highest)
		ra(stack);
	if (((long long int *)(*stack)->next->content)[INDEX] == highest)
		rra(stack);
	if (((long long int *)(*stack)->content)[INDEX]
		> ((long long int *)(*stack)->next->content)[INDEX])
		sa(stack);
}
