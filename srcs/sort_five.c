/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:15:21 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/29 20:15:22 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	send_two_smallest(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	min_idx;

	j = -1;
	while (++j < 2)
	{
		i = -1;
		min_idx = find_min_idx(a);
		if (min_idx <= a->len / 2)
		{
			while (++i < min_idx)
				rx(a);
		}
		else
		{
			while (++i < a->len - min_idx)
				rrx(a);
		}
		px(a, b);
	}
}

int	sort_five(t_stack *a, t_stack *b)
{
	send_two_smallest(a, b);
	sort_three(a);
	px(b, a);
	px(b, a);
	return (0);
}
