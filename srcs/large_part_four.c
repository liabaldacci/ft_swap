/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_part_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:14:32 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/29 20:14:33 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_abs(int i)
{
	if (i > 0)
		return (i);
	else
		return (i * -1);
}

int	decide_chunks(int len)
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
