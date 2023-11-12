/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:33:23 by marvin            #+#    #+#             */
/*   Updated: 2023/03/19 14:33:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * This function returns the absolute value of an integer. It does this by
 * checking if the integer is negative or not. If it is negative, it
 * multiplies it by -1 to make it positive. If it is positive, it returns
 * it as it is.
 * @param nb The integer to get the absolute value of.
 * @return The absolute value of the integer.
 */
int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
