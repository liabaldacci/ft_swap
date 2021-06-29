/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_cont.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:15:00 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/29 20:15:01 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	if (s->id == 1)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	rr(t_stack *one, t_stack *two)
{
	rx(one);
	rx(two);
	write(1, "rr\n", 3);
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
	if (s->id == 1)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *one, t_stack *two)
{
	rrx(one);
	rrx(two);
	write(1, "rrr\n", 4);
}
