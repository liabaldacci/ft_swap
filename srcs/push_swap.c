/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranco- <nfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:30:48 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/26 05:33:40 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0 ;
	while (i < stack->len)
	{
		printf("number: %i.\n", stack->stack[i]);
		fflush(stdout);
		i++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	init(&a, &b);
	check_args(argc, argv, &a, &b);
	// printf("STACK A BEFORE:\n");
	// print_stack(&a);
	// printf("STACK B BEFORE:\n");
	// print_stack(&b);
	sort(&a, &b);
	// printf("\nSTACK A AFTER:\n");
	// print_stack(&a);
	// printf("STACK B AFTER:\n");
	// print_stack(&b);
	if (a.stack)
		free(a.stack);
	if (b.stack)
		free(b.stack);
	return (0);
}
