/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:14:04 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/04 20:19:34 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	init(t_stack *a, t_stack *b, int argc)
{
	a->stack = NULL;
	a->len = 0;
	a->id = 1;
	b->stack = NULL;
	b->len = 0;
	b->id = 2;
	if (argc <= 1) //no numbers
		return (-1);
	a->stack = (int *) malloc((argc - 1) * sizeof(int));
	a->len = argc - 1;
	return (0);
}