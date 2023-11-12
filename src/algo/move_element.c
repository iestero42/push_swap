/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:37:06 by marvin            #+#    #+#             */
/*   Updated: 2023/03/19 14:37:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Performs reverse rotations on both stacks until the costs are positive
 * @param a A pointer to a pointer to a list that represents stack_a
 * @param b A pointer to a pointer to a list that represents stack_b
 * @param cost_a A pointer to an integer that represents the cost of moving an 
 * 	element from stack_b to stack_a
 * @param cost_b A pointer to an integer that represents the cost of moving an 
 * 	element to the top of stack_b
 * @details This function performs the rrr operation, which shifts down all 
 * 	elements of both stacks by one. The function does this while both costs 
 * 	are negative, meaning that the target element is closer to the bottom of 
 * 	both stacks. The function updates the costs by incrementing them by one 
 * 	after each operation. The function uses a helper function defined elsewhere, 
 * 	rrr.
 */
static void	rev_rotate_both(t_list **a, t_list **b,
												long long int *cost_a,
													long long int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b);
	}
}

/**
 * @brief Performs rotations on both stacks until the costs are zero or negative
 * @param a A pointer to a pointer to a list that represents stack_a
 * @param b A pointer to a pointer to a list that represents stack_b
 * @param cost_a A pointer to an integer that represents the cost of moving 
 * 	an element from stack_b to stack_a
 * @param cost_b A pointer to an integer that represents the cost of moving an 
 * 	element to the top of stack_b
 * @details This function performs the rr operation, which shifts up all 
 * 	elements of both stacks by one. The function does this while both costs 
 * 	are positive, meaning that the target element is closer to the top of 
 * 	both stacks. The function updates the costs by decrementing them by 
 * 	one after each operation. The function uses a helper function defined 
 * 	elsewhere, rr.
 */
static void	rotate_both(t_list **a, t_list **b, long long int *cost_a,
	long long int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b);
	}
}

/**
 * @brief Performs rotations on stack_a until the cost is zero
 * @param a A pointer to a pointer to a list that represents stack_a
 * @param cost A pointer to an integer that represents the cost of 
 * 	moving an element from stack_b to stack_a
 * @details This function performs either ra or rra operations on 
 * 	stack_a, depending on the sign of the cost. The ra operation 
 * 	shifts up all elements of stack_a by one. The rra operation 
 * 	shifts down all elements of stack_a by one. The function does this 
 * 	until the cost is zero, meaning that the target element is in its 
 * 	correct position in stack_a. The function updates the cost by 
 * 	incrementing or decrementing it by one after each operation. 
 * 	The function uses helper functions defined elsewhere, ra and rra.
 */
static void	rotate_a(t_list **a, long long int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(a);
			(*cost)++;
		}
	}
}

/**
 * @brief Performs rotations on stack_b until the cost is zero
 * @param b A pointer to a pointer to a list that represents stack_b
 * @param cost A pointer to an integer that represents the cost of 
 * 	moving an element to the top of stack_b
 * @details This function performs either rb or rrb operations on 
 * 	stack_b, depending on the sign of the cost. The rb operation 
 * 	shifts up all elements of stack_b by one. The rrb operation 
 * 	shifts down all elements of stack_b by one. The function does 
 * 	this until the cost is zero, meaning that the target element is at 
 * 	the top of stack_b. The function updates the cost by incrementing 
 * 	or decrementing it by one after each operation. The function uses 
 * 	helper functions defined elsewhere, rb and rrb.
 */
static void	rotate_b(t_list **b, long long int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(b);
			(*cost)++;
		}
	}
}

/**
 * @brief Moves an element from stack_b to stack_a with the minimum 
 * 	number of operations
 * @param a A pointer to a pointer to a list that represents stack_a
 * @param b A pointer to a pointer to a list that represents stack_b
 * @param cost_a An integer that represents the cost of moving an 
 * 	element from stack_b to stack_a
 * @param cost_b An integer that represents the cost of moving an 
 * 	element to the top of stack_b
 * @details This function performs a series of operations on both 
 * 	stacks to move the target element from stack_b to its correct 
 * 	position in stack_a. The operations are:
 * - rrr: shifts down all elements of both stacks by one
 * - rr: shifts up all elements of both stacks by one
 * - rra: shifts down all elements of stack_a by one
 * - ra: shifts up all elements of stack_a by one
 * - rrb: shifts down all elements of stack_b by one
 * - rb: shifts up all elements of stack_b by one
 * - pa: pushes the top element of stack_b onto stack_a and removes 
 * 		it from stack_b
 *  The function chooses the optimal combination of operations based 
 *  on the costs given as parameters. The function uses some helper 
 *  unctions defined elsewhere, such as rev_rotate_both, 
 *  rotate_both, rotate_a, rotate_b and pa.
 */
void	move_element(t_list **a, t_list **b, long long int cost_a,
		long long int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(a, b, &cost_a, &cost_b);
	rotate_a(a, &cost_a);
	rotate_b(b, &cost_b);
	pa(a, b);
}
