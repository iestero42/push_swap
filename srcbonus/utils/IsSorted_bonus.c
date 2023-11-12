/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IsSorted_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:56:53 by iestero-          #+#    #+#             */
/*   Updated: 2023/03/23 10:47:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
 * @brief Checks if a list of integers is sorted in ascending order
 * @param list a pointer to the first node of the list
 * @return SUCCESS_EXIT if the list is sorted or FAILURE_EXIT otherwise
*/
int	ft_is_sorted(t_list *list)
{
	t_list	*curr;
	t_list	*prev;

	curr = list->next;
	prev = list;
	while (curr)
	{
		if (*((int *) curr->content) < *((int *) prev->content))
			return (FAILURE_EXIT);
		prev = prev->next;
		curr = curr->next;
	}
	return (SUCCESS_EXIT);
}
