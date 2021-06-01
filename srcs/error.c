/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:45:25 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/01 20:17:31 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error(t_stack *a, t_stack *b)
{
	write(1, "Error.\n", 7);
	if (a->stack)
		free(a->stack);
	if (b->stack)
		free(b->stack);
	return (0);
}