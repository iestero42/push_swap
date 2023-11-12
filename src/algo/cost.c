/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:36:43 by marvin            #+#    #+#             */
/*   Updated: 2023/03/19 13:36:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Calculates the cost of moving elements from stack_b to stack_a
 * @param stack_a A pointer to a pointer to a list that represents stack_a
 * @param stack_b A pointer to a pointer to a list that represents stack_b
 * @details This function iterates over the elements of stack_b and assigns 
 * them two costs:
 * - COST_B: The number of operations needed to move the element to the top of 
 * stack_b
 * - COST_A: The number of operations needed to move the element to its target 
 * position in stack_a
 * The costs are stored as integers in the content field of each list node.
 * The function uses some macros defined elsewhere, such as POS, TARGET_POS, 
 * COST_B and COST_A.
 */
void	calculate_moves(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_b = *stack_b;
	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(tmp_b);
	while (tmp_b)
	{
		((long long int *) tmp_b->content)[COST_B]
			= ((long long int *) tmp_b->content)[POS];
		if (((long long int *) tmp_b->content)[POS] > size_b / 2)
			((long long int *) tmp_b->content)[COST_B] = (size_b
					- ((long long int *) tmp_b->content)[POS]) * -1;
		((long long int *) tmp_b->content)[COST_A]
			= ((long long int *) tmp_b->content)[TARGET_POS];
		if (((long long int *) tmp_b->content)[TARGET_POS] > size_a / 2)
			((long long int *) tmp_b->content)[COST_A] = (size_a
					- ((long long int *) tmp_b->content)[TARGET_POS]) * -1;
		tmp_b = tmp_b->next;
	}
}

/**
 * @brief Performs the cheapest move to sort elements from stack_b to stack_a
 * @param stack_a A pointer to a pointer to a list that represents stack_a
 * @param stack_b A pointer to a pointer to a list that represents stack_b
 * @details This function finds the element of stack_b that has the lowest 
 * 	total cost of moving it to its target position in stack_a, and then calls 
 * 	move_element with the corresponding costs. The costs are assumed to be 
 * 	already calculated by calculate_moves and stored in the content field 
 * 	of each list node. The function uses some helper functions defined 
 * 	elsewhere, such as nb_abs and move_element.
 */
void	execute_optimal_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (nb_abs(((long long int *) tmp->content)[COST_A])
			+ nb_abs(((long long int *) tmp->content)[COST_B])
				< nb_abs(cheapest))
		{
			cheapest = nb_abs(((long long int *) tmp->content)[COST_B])
				+ nb_abs(((long long int *) tmp->content)[COST_A]);
			cost_a = ((long long int *) tmp->content)[COST_A];
			cost_b = ((long long int *) tmp->content)[COST_B];
		}
		tmp = tmp->next;
	}
	move_element(stack_a, stack_b, cost_a, cost_b);
}
