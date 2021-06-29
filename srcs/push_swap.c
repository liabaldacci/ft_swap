/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:15:12 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/29 20:15:13 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	init(&a, &b);
	check_args(argc, argv, &a, &b);
	sort(&a, &b);
	if (a.stack)
		free(a.stack);
	if (b.stack)
		free(b.stack);
	return (0);
}
