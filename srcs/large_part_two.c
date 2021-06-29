/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_part_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:14:47 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/29 20:14:49 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = stack->stack[0];
	while (i < stack->len)
	{
		if (stack->stack[i] < min)
			min = stack->stack[i];
		i++;
	}
	return (min);
}

int	find_min_idx(t_stack *stack)
{
	int	i;
	int	min_idx;

	i = 0;
	min_idx = 0;
	while (i < stack->len)
	{
		if (stack->stack[i] < stack->stack[min_idx])
			min_idx = i;
		i++;
	}
	return (min_idx);
}

int	find_max(t_stack *stack)
{
	int	i;
	int	max;

	i = 0;
	max = stack->stack[0];
	while (i < stack->len)
	{
		if (stack->stack[i] > max)
			max = stack->stack[i];
		i++;
	}
	return (max);
}

int	find_max_idx(t_stack *stack)
{
	int	i;
	int	max_idx;

	i = 0;
	max_idx = 0;
	while (i < stack->len)
	{
		if (stack->stack[i] > stack->stack[max_idx])
			max_idx = i;
		i++;
	}
	return (max_idx);
}

int	find_threshold(t_stack *a, int chunks)
{
	int	thresh;

	a->min = find_min(a);
	a->max = find_max(a);
	thresh = ((a->max - a->min) / chunks) + 1;
	return (thresh);
}
