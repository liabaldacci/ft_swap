/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_part_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:14:41 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/29 20:14:42 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		while (i < a->len - min)
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
	i = 0;
	while (i < len - 1)
	{
		send_smallest(a, b);
		i++;
	}
	while (i-- > 0)
		px(b, a);
}

void	return_single_chunk(t_stack *a, t_stack *b, int min)
{
	int	rb_num;

	rb_num = 0;
	single_chunk(a, b, min);
}

void	return_all_chunks(t_stack *a, t_stack *b, int chunks, int thresh)
{
	int	i;
	int	num_RB;
	int	thresh_chunk;

	i = chunks - 1;
	num_RB = 0;
	while (i > 0)
	{
		thresh_chunk = a->min + ft_abs(thresh * i);
		if (i == 1)
		{
			return_single_chunk(a, b, a->min);
		}
		else
			return_single_chunk(a, b, thresh_chunk);
		i--;
	}	
}

int	split_chunks(t_stack *a, t_stack *b, int chunks)
{
	int	i;
	int	thresh;
	int	thresh_chunk;

	i = 1;
	thresh = find_threshold(a, chunks);
	if (a->min < 0 && a->max > 0)
		thresh = a->min + thresh;
	thresh_chunk = thresh;
	while (i < chunks)
	{
		send_chunk(a, b, thresh_chunk);
		thresh_chunk = thresh_chunk + ft_abs(thresh);
		i++;
	}
	return (thresh);
}
