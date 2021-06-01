/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:47:52 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/01 20:14:28 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sx(t_stack *s)
{
	int	temp;

	if (s->len <= 1)
		return ;
	temp = s->stack[0];
	s->stack[0] = s->stack[1];
	s->stack[1] = temp;
}

void	ss(t_stack *one, t_stack *two)
{
	sx(one);
	sx(two);
}

void	px(t_stack *src, t_stack *dst)
{
	int	*src_temp;
	int	*dst_temp;
	int i;
	
	if (src->len == 0)
		return ;
	src_temp = (int *) malloc((src->len - 1) * sizeof(int));
	dst_temp = (int *) malloc((dst->len + 1) * sizeof(int));
	dst_temp[0] = src->stack[0];
	i = 1;
	while (i <= dst->len)
	{
		dst_temp[i] = dst->stack[i - 1];
		i++;
	}
	i = 0;
	while (i < src->len - 1)
	{
		src_temp[i] = src->stack[i + 1];
		i++;
	}
	free(dst->stack);
	free(src->stack);
	src->stack = src_temp;
	dst->stack = dst_temp;
	src->len--;
	dst->len++;
}

void	rx(t_stack *s)
{
	int	temp;
	int	i;

	if (s->len <= 1)
		return ;
	temp = s->stack[0];
	i = 0;
	while (i < s->len - 1)
	{
		s->stack[i] = s->stack[i + 1];
		i++;
	}
	s->stack[i] = temp;
}

void	rr(t_stack *one, t_stack *two)
{
	rx(one);
	rx(two);
}

void	rrx(t_stack *s)
{
	int	temp;
	int	i;

	if (s->len <= 1)
		return ;
	temp = s->stack[s->len - 1];
	i = s->len - 1;
	while (i > 0)
	{
		s->stack[i] = s->stack[i - 1];
		i--;
	}
	s->stack[0] = temp;
}

void	rrr(t_stack *one, t_stack *two)
{
	rrx(one);
	rrx(two);
}