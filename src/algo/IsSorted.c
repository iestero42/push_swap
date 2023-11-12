/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IsSorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:56:53 by iestero-          #+#    #+#             */
/*   Updated: 2023/08/11 11:33:53 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (*((long long int *) curr->content)
			< *((long long int *) prev->content))
			return (FAILURE_EXIT);
		prev = prev->next;
		curr = curr->next;
	}
	return (SUCCESS_EXIT);
}
