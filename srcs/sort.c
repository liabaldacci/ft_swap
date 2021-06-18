/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:11:20 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/17 19:36:56 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sort_two(t_stack *a)
{
	if (a->stack[0] > a->stack[1])
	{
		sx(a);
	}
	return (0);
}

int	sort_three(t_stack *a)
{
	if (a->stack[0] > a->stack[1])
	{
		if (a->stack[1] < a->stack[2] && a->stack[0] > a->stack[2])
			rx(a);
		else
		{
			sx(a);
			if (a->stack[0] > a->stack[2])
				rrx(a);
		}
	}
	else if (a->stack[0] > a->stack[2])
		rrx(a);
	else if (a->stack[1] > a->stack[2])
	{
		sx(a);
		rx(a);
	}
	return (0);
}

int	sort(t_stack *a, t_stack *b)
{
	if (a->len == 1)
		return (0);
	else if (a->len == 2)
		return (sort_two(a));
	else if (a->len == 3)
		return (sort_three(a));
	else if (a->len == 5)
		return (sort_five(a, b));
	else if (a->len <= 500)
		return (sort_large(a, b));
	else
		return (0);
}
