/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:36:03 by marvin            #+#    #+#             */
/*   Updated: 2023/03/19 13:36:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Assigns a position to each element of a stack from top to bottom
 * @param stack A pointer to a pointer to a list that represents the stack
 * @details This function iterates over the elements of the stack and assigns
 * a position value to each one using an array index. The position value is
 * stored in the POS field of the content array. The top element of the stack
 * has position 0 and the bottom element has position n-1, where n is the size
 * of the stack. 
*/
static void	assign_position(t_list **stack)
{
	t_list	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		((long long int *) tmp->content)[POS] = i;
		tmp = tmp->next;
		i++;
	}
}

/**
 * @brief Gets the current position of the element with the lowest index
 * within a stack.
 * @param stack A pointer to a pointer to a list that represents the stack
 * @return The position value of the element with the lowest index
 * @details This function first calls assign_position to assign a position value
 * to each element of the stack. Then it iterates over the elements and finds
 * the one with the lowest index value. It returns the position value of that
 * element. The index value is stored in the INDEX field of the content array.
 */
int	find_min_index_position(t_list **stack)
{
	t_list	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	assign_position(stack);
	lowest_pos = ((long long int *) tmp->content)[POS];
	while (tmp)
	{
		if (((long long int *) tmp->content)[INDEX] < lowest_index)
		{
			lowest_index = ((long long int *) tmp->content)[INDEX];
			lowest_pos = ((long long int *) tmp->content)[POS];
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

void	find_best_position_aux(long long int *target_idx,
		long long int *target_pos, t_list *tmp)
{
	*target_idx = ((long long int *) tmp->content)[INDEX];
	*target_pos = ((long long int *) tmp->content)[POS];
}

/**
 * @brief Gets the best position to insert an element from stack b into stack a
 * @param a A pointer to a pointer to a list that represents stack a
 * @param b_idx The index value of the element to be inserted from stack b
 * @param target_idx A pointer to an integer that stores the index value of 
 * 	the best position
 * @param target_pos A pointer to an integer that stores the position 
 * 	value of the best position
 * @return The position value of the best position
 * @details This function iterates over the elements of stack a and finds 
 * the one with the closest index value that is greater than b_idx. 
 * It updates target_idx and target_pos accordingly using find_best_position_aux 
 * function. If no such element is found, it iterates again and finds 
 * the one with the smallest index value. It returns target_pos as 
 * the best position to insert b_idx into stack a. */
static int	find_best_position(t_list **a, int b_idx,
			long long int target_idx, long long int target_pos)
{
	t_list	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (((long long int *) tmp_a->content)[INDEX] > b_idx
			&& ((long long int *) tmp_a->content)[INDEX] < target_idx)
			find_best_position_aux(&target_idx, &target_pos, tmp_a);
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (((long long int *) tmp_a->content)[INDEX] < target_idx)
			find_best_position_aux(&target_idx, &target_pos, tmp_a);
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

/**
 * @brief Assigns a target position to each element of stack b
 * @param a A pointer to a pointer to a list that represents stack a
 * @param b A pointer to a pointer to a list that represents stack b
 * @details This function iterates over the elements of stack b and 
 * calls find_best_position function to find the best position to insert 
 * each element into stack a. It assigns the target position
 * value to each element using the TARGET_POS field of the content array. 
 */
void	assign_best_position(t_list **a, t_list **b)
{
	t_list				*tmp_b;
	long long int		target_pos;

	tmp_b = *b;
	assign_position(a);
	assign_position(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = find_best_position(a,
				((long long int *) tmp_b->content)[INDEX], INT_MAX, target_pos);
		((long long int *) tmp_b->content)[TARGET_POS] = target_pos;
		tmp_b = tmp_b->next;
	}
}
