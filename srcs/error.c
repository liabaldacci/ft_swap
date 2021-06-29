/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:13:47 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/29 20:13:48 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error(t_stack *a, t_stack *b)
{
	write(2, "Error.\n", 7);
	if (a->stack)
		free(a->stack);
	if (b->stack)
		free(b->stack);
	exit (0);
}
