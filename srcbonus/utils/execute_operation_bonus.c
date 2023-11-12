/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:07:55 by marvin            #+#    #+#             */
/*   Updated: 2023/03/23 11:07:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
 * @brief Chooses and performs an operation based on the given string.
 *
 * @param str The string representing the operation to perform.
 * @param stack_a A pointer to the first stack.
 * @param stack_b A pointer to the second stack.
 */
void	choose_operation(char *str, t_list **stack_a, t_list **stack_b)
{
	if (str[0] == 'r' && str[1] == 'a')
		ra(stack_a);
	else if (str[0] == 'r' && str[1] == 'b')
		rb(stack_b);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == '\n')
		rr(stack_a, stack_b);
	else if (str[0] == 's' && str[1] == 'a')
		sa(stack_a);
	else if (str[0] == 's' && str[1] == 'b')
		sb(stack_b);
	else if (str[0] == 's' && str[1] == 's')
		ss(stack_a, stack_b);
	else if (str[0] == 'p' && str[1] == 'a')
		pa(stack_a, stack_b);
	else if (str[0] == 'p' && str[1] == 'b')
		pb(stack_a, stack_b);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		rra(stack_a);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		rrb(stack_b);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		rrr(stack_a, stack_b);
}

/**
 * @brief Executes operations read from the standard input.
 *
 * @param stack_a A pointer to the first stack.
 * @param stack_b A pointer to the second stack.
 * @return SUCCESS_EXIT if all operations are executed successfully,
 * 	FAILURE_EXIT otherwise.
 */
int	execute_operation(t_list **stack_a, t_list **stack_b)
{
	char	*operation;

	operation = get_next_line(0);
	while (operation)
	{
		if (!error_operation(operation))
		{
			error_message();
			return (FAILURE_EXIT);
		}
		choose_operation(operation, stack_a, stack_b);
		free(operation);
		operation = get_next_line(0);
	}
	free(operation);
	return (SUCCESS_EXIT);
}
