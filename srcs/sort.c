/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranco- <nfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:11:20 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/09 01:34:28 by nfranco-         ###   ########.fr       */
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

int	sort_five(t_stack *a, t_stack *b)
{
	px(a, b);
	px(a, b);
	sort_three(a);
	if (b->stack[0] > a->stack[2])
	{
		px(b, a);
		rx(a);
	}
	else if (b->stack[0] > a->stack[1])
	{
		if (b->stack[1] > a->stack[2])
		{
			sx(b);
			px(b, a);
			rrx(a);
			px(b, a);
			rrx(a);
			rrx(a);
			return (0);
		}
		else if (b->stack[1] && (b->stack[1] > a->stack[2]))
		{
			rrx(a);
			if (b->stack[0] < b->stack[1])
				sx(b);
			px(b, a);
			px(b, a);
			rrx(a);
			rrx(a);
			return (0);
		}
		rrx(a);
		px(b, a);
		rx(a);
		rx(a);
	}
	else if (b->stack[0] > a->stack[0])
	{
		if (b->stack[1] < a->stack[1] && b->stack[1] > a->stack[0])
		{
			if (b->stack[0] < b->stack[1])
				sx(b);
			rx(a);
			px(b, a);
			px(b, a);
			rrx(a);
			return (0);
		}
		else
		{
			px(b, a);
			sx(a);
			px(b, a);
			return (0);
		}
	}
	if (b->stack && b->stack[0] > a->stack[0])
	{
		if (b->stack && b->stack[0] > a->stack[3])
		{
			px(b, a);
			rx(a);
		}
		else if (b->stack && b->stack[0] > a->stack[2])
		{
			rrx(a);
			px(b, a);
			rx(a);
			rx(a);
		}
		else if (b->stack && b->stack[0] > a->stack[1])
		{
			rx(a);
			px(b, a);
			sx(a);
			rrx(a);
		}
		else
		{
			px(b, a);
			sx(a);
		}
	}
	else
		px(b, a);
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
	else
		return (0);
}