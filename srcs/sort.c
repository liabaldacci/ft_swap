/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranco- <nfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:11:20 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/26 03:06:53 by nfranco-         ###   ########.fr       */
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

int	ft_need_sort(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->len - 1)
	{
		if (a->stack[i] > a->stack[i + 1])
			return (-1);
		i++;
	}
	return (0);
}

int	sort(t_stack *a, t_stack *b)
{
	if (ft_need_sort(a) == 0)
		return (0);
	if (a->len == 1)
		return (0);
	else if (a->len == 2)
		return (sort_two(a));
	else if (a->len == 3)
		return (sort_three(a));
	else if (a->len == 5)
		return (sort_five(a, b));
	return (sort_large(a, b));
}
