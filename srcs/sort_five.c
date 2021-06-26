/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranco- <nfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 00:32:21 by nfranco-          #+#    #+#             */
/*   Updated: 2021/06/26 02:51:46 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_one_on_top(t_stack *a, t_stack *b)
{
	if (b->stack[0] < a->stack[0] || b->stack[1] < a->stack[0])
	{
		if (b->stack[0] > b->stack[1])
			sx(b);
		px(b, a);
		if (b->stack[0] < a->stack[0])
			sx(a);
		px(b, a);
		if (a->stack[0] > a->stack[4])
			rx(a);
	}
	else
	{
		if (b->stack[0] > b->stack[1])
			sx(b);
		px(b, a);
		if (b->stack[0] < a->stack[3])
			rrx(a);
		px(b, a);
		rx(a);
		if (a->stack[0] > a->stack[4])
			rx(a);
	}
}

void	ft_one_on_snd_pos(t_stack *a, t_stack *b)
{
	if (b->stack[0] < a->stack[1] && b->stack[1] < a->stack[1]
		&& b->stack[0] < b->stack[1])
		sx(b);
	if ((b->stack[0] > a->stack[1] || b->stack[1] > a->stack[1])
		&& (b->stack[0] > b->stack[1]))
		sx(b);
	px(b, a);
	sx(a);
	if (b->stack[0] < a->stack[1])
	{
		px(b, a);
		sx(a);
	}
	else if (b->stack[0] > a->stack[2] && b->stack[0] < a->stack[3])
	{
		rrx(a);
		px(b, a);
		rx(a);
		rx(a);
	}
	else
	{
		px(b, a);
		rx(a);
	}
}

void	ft_one_on_trd_pos(t_stack *a, t_stack *b)
{
	if (b->stack[0] < b->stack[1])
		sx(b);
	if (b->stack[0] > a->stack[2])
	{
		px(b, a);
		rrx(a);
		px(b, a);
	}
	else
	{
		rrx(a);
		px(b, a);
		px(b, a);
	}
	rrx(a);
	rrx(a);
}

void	ft_one_on_4th_pos(t_stack *a, t_stack *b)
{
	if (b->stack[0] > b->stack[1])
		sx(b);
	px(b, a);
	rx(a);
	px(b, a);
	rx(a);
}

int	sort_five(t_stack *a, t_stack *b)
{
	int i;
	int j;
	int min_idx;

	j = 0;
	while (j < 2)
	{
		i = 0;
		min_idx = find_min_idx(a);
		if (min_idx <= a->len / 2)
		{
			while (i < min_idx)
			{
				rx(a);
				i++;
			}
		}
		else
		{
			while (i < a->len - min_idx)
			{
				rrx(a);
				i++;
			}
		}
		px(a, b);
		j++;
	}
	// px(a, b);
	// px(a, b);
	sort_three(a);
	// if (b->stack[0] < a->stack[0] || b->stack[1] < a->stack[0])
	// {
	// 	ft_one_on_top(a, b);
	// }
	// else if (b->stack[0] < a->stack[1] || b->stack[1] < a->stack[1])
	// {
	// 	ft_one_on_snd_pos(a, b);
	// }
	// else if (b->stack[0] < a->stack[2] || b->stack[1] < a->stack[2])
	// {
	// 	ft_one_on_trd_pos(a, b);
	// }
	// else
	// {
	// 	ft_one_on_4th_pos(a, b);
	// }
	px(b, a);
	px(b, a);
	return (0);
}
