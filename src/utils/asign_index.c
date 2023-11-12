/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asign_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:38:13 by marvin            #+#    #+#             */
/*   Updated: 2023/03/19 13:38:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Updates the highest value and pointer in a stack
 * @param highest A pointer to a pointer to a node that represents the highest 
 * 	value in the stack
 * @param value A pointer to an integer that represents the current highest 
 * 	value in the stack
 * @param stack_a A pointer to a list that represents the stack
 * @param ptr A pointer to a pointer to a node that is being compared with 
 * 	the highest value
 * @details This function checks if the value of the content array of 
 * the current node is greater than the current highest value and if it has 
 * not been assigned an index yet. If so, it updates the highest value 
 * and pointer with those of the current node and resets the ptr to point to 
 * the beginning of the stack. Otherwise, it moves the ptr to point to the 
 * next node in the stack. The function also assigns an index of 1 to any 
 * node that has a value of INT_MIN and no index yet. 
*/
void	auxiliar(t_list **highest, long long int *value,
		t_list *stack_a, t_list **ptr)
{
	if (((long long int *)(*ptr)->content)[VALUE] > *value
		&& !((long long int *)(*ptr)->content)[INDEX])
	{
		*value = ((long long int *)(*ptr)->content)[VALUE];
		*highest = *ptr;
		*ptr = stack_a;
	}
	else
		*ptr = (*ptr)->next;
}

/**
 * @brief Assigns an index to each element of a stack according to its value
 * @param stack_a A pointer to a list that represents the stack
 * @param stack_size An integer that represents the number of elements 
 * 	in the stack
 * @details This function iterates over the stack and finds the element with 
 * the highest value that has not been assigned an index yet. Then it assigns
 * an index to that element, starting from stack_size - 1 and decreasing by one 
 * for each iteration. The index is stored in the second position of the content 
 * array of each node. The function uses an auxiliary function called auxiliar 
 * to compare values and update pointers. 
*/
void	assign_index(t_list *stack_a, int stack_size)
{
	t_list				*ptr;
	t_list				*highest;
	long long int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
			auxiliar(&highest, &value, stack_a, &ptr);
		if (highest != NULL)
			((long long int *) highest->content)[INDEX] = stack_size;
	}
}
