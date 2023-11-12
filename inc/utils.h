/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:47:18 by marvin            #+#    #+#             */
/*   Updated: 2023/03/19 20:47:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define ERROR_ARG -1
# define ERROR_LIST -2
# define NON_ERROR 0

# include "linked_list.h"

t_list	**list_numbers(char **argv);

int		error_arg(char *arg);

int		error_list(t_list *lst);

int		error_message(void);

int		nb_abs(int nb);

int		error_null(char **str);

#endif