/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:36:44 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/17 20:37:01 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		decide_chunks(int len)
{
	if (len < 25)
		return (2);
	else if (len < 50)
		return (4);
	else if (len < 100)
		return (6);
	else if (len < 250)
		return (8);
	else if (len < 500)
		return (10);
	else
		return (12);
}

int		find_min(t_stack *stack)
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

int		find_min_idx(t_stack *stack)
{
	int	i;
	int	min_idx;

	i = 0;
	min_idx = stack->stack[0];
	while (i < stack->len)
	{
		if (stack->stack[i] < stack->stack[min_idx])
			min_idx = i;
		i++;
	}
	return (min_idx);
}

int		find_max(t_stack *stack)
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

int		find_threshold(t_stack *a, int chunks)
{
	int	min;
	int	max;
	int	thresh;

	min = find_min(a);
	max = find_max(a);
	thresh = (max - min) / chunks;
	return (thresh);	
}

void	send_chunk(t_stack *a, t_stack *b, int thresh)
{
	int	i;
	int	len;

	i = 0;
	len = a->len;
	while (i < len)
	{
		if (a->stack[0] <= thresh)
			px(a, b); //PB
		else
			rx(a);
		i++;
	}
}

void	split_chunks(t_stack *a, t_stack *b, int chunks)
{
	int	i;
	int	thresh;

	i = 1;
	thresh = find_threshold(a, chunks);
	while (i < chunks) //leave out last chunk
	{
		thresh = thresh * i;
		send_chunk(a, b, thresh);
		i++;
	}
}

void	send_smallest(t_stack *a, t_stack *b)
{
	int	min;
	int	i;

	min = find_min_idx(a);
	i = 0;
	if (min <= a->len / 2)
	{
		while (i < min)
		{
			rx(a);
			i++;
		}
		px(a, b);
	}
	else
	{
		while (i <= a->len - min)
		{
			rrx(a);
			i++;
		}
		px(a, b);
	}
}

void	sort_last_chunk(t_stack *a, t_stack *b)
{
	int	len;
	int	i;

	len = a->len;
	while (i < len - 1)
	{
		send_smallest(a, b);
		i++;		
	}
	while (i-- > 0)
		px(b, a);
}

int		sort_large(t_stack *a, t_stack *b)
{
	int	chunks;

	chunks = decide_chunks(a->len);
	split_chunks(a, b, chunks);
	sort_last_chunk(a, b);
	//TODO: Return chunk by chunk to stack A
}