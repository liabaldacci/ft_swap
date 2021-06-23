/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:36:44 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/22 20:55:47 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_abs(int i)
{
	if (i > 0)
		return (i);
	else
		return (i * -1);
}

int		decide_chunks(int len)
{
	if (len < 25)
		return (2);
	else if (len < 50)
		return (4);
	else if (len < 100)
		return (8);
	else if (len < 250)
		return (10);
	else if (len < 500)
		return (12);
	else
		return (15);
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
	min_idx = 0;
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

int		find_max_idx(t_stack *stack)
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

int		find_threshold(t_stack *a, int chunks)
{
	int	min;
	int	max;
	int	thresh;

	min = find_min(a);
	max = find_max(a);
	if (min < 0 && max > 0)
		thresh = (max - ((max - min) / chunks) + 1);
	else
		thresh = ((max - min) / chunks) + 1;
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

int		split_chunks(t_stack *a, t_stack *b, int chunks)
{
	int	i;
	int	thresh;
	int	thresh_chunk;

	i = 1;
	thresh = find_threshold(a, chunks);
	thresh_chunk = thresh;
	while (i < chunks) //leave out last chunk
	{
		send_chunk(a, b, thresh_chunk);
		thresh_chunk = thresh_chunk + ft_abs(thresh);
		i++;
	}
	return (thresh);
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

void	single_chunk_positive(t_stack *a, t_stack *b, int min)
{
	int	j;
	int	max_idx;
	int	rb_num;

	rb_num = 0;
	while (b->stack[0] > min | b->stack[b->len - 1] > min)
	{
		max_idx = find_max_idx(b); //find index of largest number
		if (max_idx == 1) //if the largest number is on the second position do SB instead of RB
			sx(b);
		else if (max_idx >= (b->len - rb_num - 1))
		//if the largest number is one of the last in the stack after doing RB
		{
			j = 0;
			while (j < (b->len - max_idx)) //DO enough RRBs to send the largest number back to the first position
			{
				rrx(b);
				rb_num--; //number of times RB was used is decreased
				j++;
			}
		}
		else
		// if the largest number is not in the second position nor in the end of the stack,
		//	do RB until it is in the first position
		{
			j = 0;
			while (j < max_idx)
			{
				rx(b);
				rb_num++;
				j++;
			}
		}
		//after all that the largest number is in the first position so now just needs to be sent ot stack A
		px(b, a);
	}
}

void	single_chunk_negative(t_stack *a, t_stack *b, int min)
{
	int	j;
	int	max_idx;
	int	rb_num;

	rb_num = 0;
	while (b->stack[0] < min | b->stack[b->len - 1] < min)
	{
		max_idx = find_max_idx(b); //find index of largest number
		if (max_idx == 1) //if the largest number is on the second position do SB instead of RB
			sx(b);
		else if (max_idx >= (b->len - rb_num - 1)) 
		//if the largest number is one of the last in the stack after doing RB
		{
			j = 0;
			while (j < (b->len - max_idx)) //DO enough RRBs to send the largest number back to the first position
			{
				rrx(b);
				rb_num--; //number of times RB was used is decreased
				j++;
			}
		}
		else
		// if the largest number is not in the second position nor in the end of the stack,
		//	do RB until it is in the first position
		{
			j = 0;
			while (j < max_idx)
			{
				rx(b);
				rb_num++;
				j++;
			}
		}
		//after all that the largest number is in the first position so now just needs to be sent ot stack A
		px(b, a);
	}
}

void	return_single_chunk(t_stack *a, t_stack *b, int min)
{
	// int	j;
	// int	max_idx;
	int	rb_num;

	rb_num = 0;
	if (min >= 0)
		single_chunk_positive(a, b, min);
	else
		single_chunk_negative(a, b, min);
	// while (b->stack[0] > min | b->stack[b->len - 1] > min)
	// {
	// 	max_idx = find_max_idx(b); //find index of largest number
	// 	if (max_idx == 1) //if the largest number is on the second position do SB instead of RB
	// 		sx(b);
	// 	else if (max_idx >= (b->len - rb_num - 1)) 
	// 	//if the largest number is one of the last in the stack after doing RB
	// 	{
	// 		j = 0;
	// 		while (j < (b->len - max_idx)) //DO enough RRBs to send the largest number back to the first position
	// 		{
	// 			rrx(b);
	// 			rb_num--; //number of times RB was used is decreased
	// 			j++;
	// 		}
	// 	}
	// 	else
	// 	// if the largest number is not in the second position nor in the end of the stack,
	// 	//	do RB until it is in the first position
	// 	{
	// 		j = 0;
	// 		while (j < max_idx)
	// 		{
	// 			rx(b);
	// 			rb_num++;
	// 			j++;
	// 		}
	// 	}
	// 	//after all that the largest number is in the first position so now just needs to be sent ot stack A
	// 	px(b, a);
	// }
}

void	return_all_chunks(t_stack *a, t_stack *b, int chunks, int thresh)
{
	int	i;
	int	num_RB;
	int	thresh_chunk;

	i = chunks - 1;
	num_RB = 0;
	if (thresh < 0)
		thresh_chunk = thresh + ft_abs(thresh * i);
	else
		thresh_chunk = ft_abs(thresh * i);
	while (i > 0)
	{
		thresh_chunk = thresh_chunk - ft_abs(thresh);
		return_single_chunk(a, b, thresh_chunk);
		i--;
	}	
}

int		sort_large(t_stack *a, t_stack *b)
{
	int	chunks;
	int	thresh;

	chunks = decide_chunks(a->len);
	thresh = split_chunks(a, b, chunks);
	sort_last_chunk(a, b);
	return_all_chunks(a, b, chunks, thresh);
	return (0);
}