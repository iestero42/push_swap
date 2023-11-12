/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm_small.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:01:09 by marvin            #+#    #+#             */
/*   Updated: 2023/03/19 12:01:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
* @brief Moves all elements from stack_a to stack_b except the first three
* @param stack_a A pointer to a pointer to a list that represents stack_a
* @param stack_b A pointer to a pointer to a list that represents stack_b
* @details This function performs a series of operations on both stacks to move 
*	all elements from stack_a to stack_b except the first three. 
*	The operations are:
*	- pb: pushes the top element of stack_a onto stack_b and removes it from 
*		  stack_a
*	- ra: shifts up all elements of stack_a by one
*	The function uses some helper functions defined elsewhere, such as 
*	ft_lstsize and pb. 
*/
static void	divide_stack(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;
	int	pushed;

	stack_size = ft_lstsize(*stack_a);
	pushed = 0;
	while (stack_size > 6 && pushed < stack_size / 2)
	{
		if (((long long int *)(*stack_a)->content)[INDEX] <= stack_size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
	}
	while (stack_size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

/**
 * @brief Shifts the elements of stack_a until the smallest one is on top
 * @param stack_a A pointer to a pointer to a list that represents stack_a
 * @details This function determines the position of the smallest element 
 *	of stack_a and performs a series of operations to move it to the top.
 *	The operations are:
 * 		- rra: shifts down all elements of stack_a by one
 *  		- ra: shifts up all elements of stack_a by one
 * 	The function uses some helper functions defined elsewhere, such as 
 * 	ft_lstsize and find_min_index_position. 
*/
static void	shift_stack(t_list **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	lowest_pos = find_min_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack_a);
			lowest_pos--;
		}
	}
}

/**
* @brief Sorts the elements of stack_a using stack_b as an auxiliary stack
* @param stack_a A pointer to a pointer to a list that represents stack_a
* @param stack_b A pointer to a pointer to a list that represents stack_b
* @details This function uses the following steps to 
*		sort the elements of stack_a:
* 		- Push half of the elements from stack_a to stack_b, leaving only three 
*		elements in stack_a. This is done by the function divide_stack.
* 		- Sort the three remaining elements in stack_a using only two operations: 
*		sa (swap a) and ra (rotate a). This is done by the function sort_
		three_elements.
* 		- While there are still elements in stack_b, do the following:
* 		- Find the best position to insert the top element of stack_b 
*		into stack_a. This is done by the function assign_best_position.
* 		- Calculate the minimum number of operations needed to move both 
*		stacks to reach that position. This is done by the function 
		calculate_moves.
* 		- Perform those operations using pa (push to a), ra (rotate a), 
*		rra (reverse rotate a), rb (rotate b) and rrb (reverse rotate b). 
*		This is done by the function execute_optimal_move.
* 		- If stack_a is not sorted yet, shift it until the lowest index element 
*		is at the top. This is done by the function shift_stack.
 */
void	sort(t_list **stack_a, t_list **stack_b)
{
	divide_stack(stack_a, stack_b);
	sort_three_elements(stack_a);
	while (*stack_b)
	{
		assign_best_position(stack_a, stack_b);
		calculate_moves(stack_a, stack_b);
		execute_optimal_move(stack_a, stack_b);
	}
	if (!ft_is_sorted(*stack_a))
		shift_stack(stack_a);
}
