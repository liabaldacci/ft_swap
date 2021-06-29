/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:15:05 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/29 20:15:06 by gadoglio         ###   ########.fr       */
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
	if (s->id == 1)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	ss(t_stack *one, t_stack *two)
{
	sx(one);
	sx(two);
	write(1, "ss\n", 3);
}

void	p_print(t_stack *src)
{
	if (src->id == 1)
		write(1, "pb\n", 3);
	else
		write(1, "pa\n", 3);
}

void	ft_free_px(t_stack *src, t_stack *dst, int *src_temp, int *dst_temp)
{
	free(dst->stack);
	free(src->stack);
	dst->stack = NULL;
	src->stack = NULL;
	src->stack = src_temp;
	dst->stack = dst_temp;
	src->len--;
	dst->len++;
}

void	px(t_stack *src, t_stack *dst)
{
	int	*src_temp;
	int	*dst_temp;
	int	i;

	if (src->len == 0)
		return ;
	src_temp = NULL;
	dst_temp = NULL;
	if (src->len > 1)
		src_temp = (int *) ft_calloc((src->len - 1), sizeof(int));
	dst_temp = (int *) ft_calloc((dst->len + 1), sizeof(int));
	dst_temp[0] = src->stack[0];
	i = 1;
	while (i <= dst->len)
	{
		dst_temp[i] = dst->stack[i - 1];
		i++;
	}
	i = -1;
	while (++i < src->len - 1)
		src_temp[i] = src->stack[i + 1];
	ft_free_px(src, dst, src_temp, dst_temp);
	p_print(src);
}
