/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_numbers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:44:31 by iestero-          #+#    #+#             */
/*   Updated: 2023/08/14 08:39:22 by iestero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
 * Function tha converts a string into an integer in order to create a 
 * new node
 * @param str the string used to creat the new node
 * @return t_list* a pointer with the new node
 */
t_list	*find_node(char *str)
{
	int		*i;
	t_list	*node;

	i = (int *) malloc(sizeof(int) * 1);
	if (!i)
		return (NULL);
	*i = ft_atoi(str);
	node = ft_lstnew(i);
	return (node);
}

/**
 * Function that construct a new list based on a matrix of string that 
 * @param argv the matrix of strings
 * @param size teh representation of the length of the new list
 * @return t_list** a new list or NULL if an error occur
 */
t_list	**list_numbers(char **argv)
{
	t_list	*node;
	t_list	**lst;
	char	**str;
	char	**tmp;

	lst = (t_list **) malloc(sizeof(t_list) * 1);
	*lst = NULL;
	if (!lst)
		return (NULL);
	while (*++argv)
	{
		str = ft_split(*argv, ' ');
		if (!str)
			return (0);
		tmp = str;
		while (*tmp)
		{
			node = find_node(*tmp++);
			if (!node)
				return (NULL);
			ft_lstadd_back(lst, node);
		}
		double_free(str);
	}
	return (lst);
}
