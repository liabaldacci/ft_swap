/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:47:52 by gadoglio          #+#    #+#             */
/*   Updated: 2021/05/31 21:29:28 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sx(t_stack *s)
{
	int	temp;

	temp = s->stack[0];
	s->stack[0] = s->stack[1];
	s->stack[1] = temp;
}

void	ss(t_stack *a, t_stack *b)
{
	sx(a);
	sx(b);
}

void	px(t_stack *one, t_stack *two)
{
	int	*temp;
	int	*temp2;
	int i;
	
	temp = (int *) malloc((two->len + 1) * sizeof(int));
	temp2 = (int *) malloc((one->len - 1) * sizeof(int));
	temp[0] = one->stack[0];
	i = 1;
	while (i <= two->len)
	{
		temp[i] = two->stack[i - 1];
		i++;
	}
	i = 1;
	while (i < one->len)
	{
		temp2[i - 1] = one->stack[i];
		i++;
	}
	free(two->stack);
	free(one->stack);
	one->stack = temp2;
	two->stack = temp;
	one->len--;
	two->len++;
}