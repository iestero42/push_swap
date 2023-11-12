/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:51:52 by iestero-          #+#    #+#             */
/*   Updated: 2023/08/26 15:52:34 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
 * @brief Frees the memory occupied by a linked list that represents a stack
 * @param stack A pointer to a pointer to a list that represents the stack
 * @details This function calls the ft_lstclear function to delete all the 
 * elements of the list and free the space allocated to each one. 
 * Then it assigns NULL to the stack pointer to indicate that it is empty.
*/
void	free_list(t_list **stack)
{
	ft_lstclear(stack, free);
	stack = NULL;
}

/**
 * @brief Gets the size of the list of numbers passed as arguments
 * @param argv The array of arguments passed to the program
 * @return The size of the list or 0 if an error occurs
 * @details This function iterates over the array of arguments and splits each 
 * argument by spaces using ft_split function. It then checks if each element is 
 * a valid number using error_arg function. If so, it increments the size 
 * by one. If not, it returns 0. It also frees the memory allocated 
 * by ft_split using double_free function. 
*/
int	size_list(char **argv)
{
	int		size;
	char	**str;
	char	**tmp;

	size = 0;
	while (*++argv)
	{
		str = ft_split(*argv, ' ');
		if (!str || !*str)
			return (error_null(str));
		tmp = str;
		while (*tmp)
		{
			if (error_arg(*tmp) == ERROR_ARG)
			{
				double_free(str);
				return (ERROR_ARG);
			}
			size++;
			tmp++;
		}
		double_free(str);
	}
	return (size);
}

/**
 * @brief Checks if the stack is sorted after executing operations
 * read from the standard input.
 *
 * @param stack_a A pointer to the stack to check.
 * @param size The size of the stack.
 */
void	checker(t_list **stack_a)
{
	t_list	**stack_b;

	stack_b = (t_list **) malloc(sizeof(t_list) * 1);
	*stack_b = NULL;
	if (!execute_operation(stack_a, stack_b))
	{
		free(stack_b);
		stack_b = NULL;
		return ;
	}
	if (ft_is_sorted(*stack_a) && !*stack_b)
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 1);
	free(stack_b);
	stack_b = NULL;
}

/**
 * @brief The main function of the program.
 *
 * @param argc The number of arguments passed to the program.
 * @param argv An array of strings representing the arguments passed to 
 * the program.
 * @return 0 if the program exits successfully, an error code otherwise.
 */
int	main(int argc, char **argv)
{
	t_list	**stack_a;
	int		size;

	if (argc < 2)
		return (0);
	size = size_list(argv);
	if (size == ERROR_ARG)
		return (error_message());
	stack_a = list_numbers(argv);
	if (!stack_a)
		return (0);
	if (error_list(*stack_a) == ERROR_LIST)
	{
		free_list(stack_a);
		free(stack_a);
		return (error_message());
	}
	checker(stack_a);
	free_list(stack_a);
}
