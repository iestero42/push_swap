/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:16:28 by marvin            #+#    #+#             */
/*   Updated: 2023/03/22 10:16:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# define ERROR_ARG -1
# define ERROR_LIST -2
# define NON_ERROR 0

# define SUCCESS_EXIT 1
# define FAILURE_EXIT 0

# include "operation_bonus.h"
# include "linked_list.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <stdio.h>

t_list		**list_numbers(char **argv);

int			ft_is_sorted(t_list *list);

int			error_operation(char *operation);

int			error_message(void);

int			error_list(t_list *lst);

int			error_arg(char *arg);

int			execute_operation(t_list **stack_a, t_list **stack_b);

void		print_list(t_list *a);

int			error_null(char **str);

#endif