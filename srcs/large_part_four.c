/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_part_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranco- <nfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 05:15:44 by nfranco-          #+#    #+#             */
/*   Updated: 2021/06/26 05:15:49 by nfranco-         ###   ########.fr       */
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
