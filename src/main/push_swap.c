/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:04:27 by iestero-          #+#    #+#             */
/*   Updated: 2023/08/26 16:04:28 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
 * @brief Chooses an algorithm to sort the elements of stack a
 * @param stack_a A pointer to a pointer to a list that represents stack a
 * @param stack_b A pointer to a pointer to a list that represents stack b
 * @param stack_size The size of stack a
 * @details This function uses different algorithms to sort the elements of 
 * 	stack a based on their size. It does this by using the following cases:
 * 		- If stack_size is 2 and stack_a is not sorted, it swaps the two 
 * 		elements using sa operation.
 * 		- If stack_size is 3, it sorts the three elements using sort_three_elements 
 * 		function. This function uses only sa and ra operations.
 * 		- If stack_size is greater than 3 and stack_a is not sorted, it sorts 
 * 		the elements using sort function. This function uses push_swap 
 * 		algorithm with various operations on both stacks. 
 */
static void	choose_algo(t_list **stack_a, t_list **stack_b, int stack_size)
{
	if (stack_size == 2 && !ft_is_sorted(*stack_a))
		sa(stack_a);
	else if (stack_size == 3)
		sort_three_elements(stack_a);
	else if (stack_size > 3 && !ft_is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

/**
 * @brief Sorts the elements of stack a using stack b as an auxiliary stack
 * @param stack_a A pointer to a pointer to a list that represents stack a
 * @details This function uses the following steps to 
 * 	sort the elements of stack a:
 * 		1. Get the size of stack a using ft_lstsize function.
 * 		2. Allocate memory for a list that represents stack b using malloc 
 * 		function.
 * 		3. Assign an index value to each element of stack a using assign_index 
 * 		function. The index value is based on the sorted order of the elements.
 * 		4. Choose an algorithm to sort the stacks based on their size using 
 * 		choose_algo function. This function prints the operations performed 
 * 		on the stacks to sort them.
 * 		5. Free the memory allocated for stack b using free_list function. 
 */
static void	push_swap(t_list **stack_a)
{
	t_list	**stack_b;
	int		size;

	size = ft_lstsize(*stack_a);
	stack_b = (t_list **) malloc(sizeof(t_list) * 1);
	*stack_b = NULL;
	assign_index(*stack_a, size);
	choose_algo(stack_a, stack_b, size);
	free(stack_b);
	stack_b = NULL;
}

/**
 * @brief The main function of the push_swap program
 * @param argc The number of arguments passed to the program
 * @param argv The array of arguments passed to the program
 * @return 0 if the program finishes successfully or an error occurs
 * @details This function takes a list of numbers as arguments and 
 * 	sorts them using two stacks.It does this by using the following steps:
 * 		1. Check if there are at least two arguments. If not, return 0.
 * 		2. Get the size of the list using size_list function. 
 * 		If it is 0, return an error message.
 * 		3. Create a list that represents stack a using list_numbers 
 * 		function. If it fails, return 0.
 * 		4. Check if there are any errors in the list using error_list 
 * 		function. If so, free the list and return an error message.
 * 		5. Sort the list using push_swap function. This function 
 * 		prints the operations performed on the stacks to sort them.
 * 		6. Free the list and return 0. */
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
	push_swap(stack_a);
	free_list(stack_a);
	free(stack_a);
}
