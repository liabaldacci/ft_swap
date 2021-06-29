/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:14:53 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/29 20:14:54 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	send_chunk(t_stack *a, t_stack *b, int thresh)
{
	int	i;
	int	len;

	i = 0;
	len = a->len;
	while (i < len)
	{
		if (a->stack[0] <= thresh)
			px(a, b);
		else
			rx(a);
		i++;
	}
}

int	ft_single_chunk_rrx(t_stack *b, int max_idx, int rb_num)
{
	int	i;

	i = 0;
	while (i < (b->len - max_idx))
	{
		rrx(b);
		rb_num--;
		i++;
	}
	return (rb_num);
}

int	ft_single_chunk_rx(t_stack *b, int max_idx, int rb_num)
{
	int	i;

	i = 0;
	while (i < max_idx)
	{
		rx(b);
		rb_num++;
		i++;
	}
	return (rb_num);
}

void	single_chunk(t_stack *a, t_stack *b, int min)
{
	int	max_idx;
	int	rb_num;

	rb_num = 0;
	while ((b->len > 0) && (b->stack[0] >= min | b->stack[b->len - 1] >= min))
	{
		max_idx = find_max_idx(b);
		if (max_idx == 1)
			sx(b);
		else if (max_idx >= (b->len - rb_num - 1) && (max_idx != 0))
			rb_num = ft_single_chunk_rrx(b, max_idx, rb_num);
		else
			rb_num = ft_single_chunk_rx(b, max_idx, rb_num);
		px(b, a);
	}
}

int	sort_large(t_stack *a, t_stack *b)
{
	int	chunks;
	int	thresh;

	chunks = decide_chunks(a->len);
	thresh = split_chunks(a, b, chunks);
	sort_last_chunk(a, b);
	return_all_chunks(a, b, chunks, thresh);
	return (0);
}
