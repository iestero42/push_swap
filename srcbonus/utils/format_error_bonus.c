/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_error_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:13:21 by iestero-          #+#    #+#             */
/*   Updated: 2023/08/26 11:34:29 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
 * Function that find an error in the argument pass by parameter
 * @param arg the string that could have an error
 * @return int if no error return NON_ERROR else returns ERROR_ARG
 */
int	error_arg(char *arg)
{
	int		i;
	int		n;
	char	*number;

	i = 0;
	if ((arg[0] < '0' || arg[0] > '9') && arg[0] != '-' && arg[0] != '+')
		return (ERROR_ARG);
	while (arg[++i] != '\0')
		if (arg[i] < '0' || arg[i] > '9')
			return (ERROR_ARG);
	number = ft_itoa(ft_atoi(arg));
	i = (int) ft_strlen(number);
	n = (int) ft_strlen(arg);
	if (arg[0] == '+')
		n = (int) ft_strlen(arg++) - 1;
	if (i < n)
		i = n;
	n = ft_strncmp(arg, number, i);
	free(number);
	if (n)
		return (ERROR_ARG);
	if (!ft_strncmp(arg, "", ft_strlen(arg)))
		return (ERROR_ARG);
	return (NON_ERROR);
}

/**
 * Function that find an error in the list pass by parameter
 * @param lst the list that could have an error
 * @return int if no error return NON_ERROR else returns ERROR_LIST
 */
int	error_list(t_list *lst)
{
	int		i;
	t_list	*aux1;
	t_list	*aux2;

	aux1 = lst;
	while (aux1)
	{
		aux2 = aux1->next;
		i = *((int *) aux1->content);
		while (aux2)
		{
			if (*((int *) aux2->content) == i)
				return (ERROR_LIST);
			aux2 = aux2->next;
		}
		aux1 = aux1->next;
	}
	return (NON_ERROR);
}

/**
 * Function that write in the standard output an error message
 */
int	error_message(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

/**
 * @brief Checks if a given operation is valid.
 *
 * @param operation The operation to check.
 * @return SUCCESS_EXIT if the operation is valid, FAILURE_EXIT otherwise.
 */
int	error_operation(char *operation)
{
	int	size;

	size = ft_strlen(operation);
	if (size < 3)
		size = 3;
	if (!ft_strncmp("ra\n", operation, size)
		|| !ft_strncmp("rb\n", operation, size)
		|| !ft_strncmp("rb\n", operation, size)
		|| !ft_strncmp("rr\n", operation, size)
		|| !ft_strncmp("sa\n", operation, size)
		|| !ft_strncmp("sb\n", operation, size)
		|| !ft_strncmp("ss\n", operation, size)
		|| !ft_strncmp("pa\n", operation, size)
		|| !ft_strncmp("pa\n", operation, size)
		|| !ft_strncmp("pb\n", operation, size))
		return (SUCCESS_EXIT);
	size = ft_strlen(operation);
	if (size < 4)
		size = 4;
	if (!ft_strncmp("rra\n", operation, size)
		|| !ft_strncmp("rrb\n", operation, size)
		|| !ft_strncmp("rrr\n", operation, size))
		return (SUCCESS_EXIT);
	return (FAILURE_EXIT);
}

/**
 * @brief 
 * 
 * @param str 
 * @return int 
 */
int	error_null(char **str)
{
	free(str);
	return (ERROR_ARG);
}
