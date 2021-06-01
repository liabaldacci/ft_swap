/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:30:48 by gadoglio          #+#    #+#             */
/*   Updated: 2021/05/31 21:32:33 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		is_valid_number(char *s)
{
	if (*s == '-')
		s++;
	while (*s)
	{
		if (ft_isdigit(*s) == 0)
			return (0);
		s++;			
	}
	return (1);
}
int		arg_to_stack(int argc, char *argv[], t_stack *a)
{
	int i;
	int j;

	i = argc - 1;
	j = 0;
	while (j < argc - 1)
	{
		if (is_valid_number(argv[i]) == 0)
			return (-1);
		a->stack[j] = ft_atoi(argv[i]);
		i--;
		j++;
	}
	a->len = j;
	return (0);	
}

void	print_stack(t_stack *stack)
{
	int i;

	i = 0 ;
	while (i < stack->len)
	{
		printf("number: %i.\n", stack->stack[i]);
		i++;
	}
	printf("\n");
}

int     main(int argc, char **argv)
{
	t_stack	a;
	t_stack b;

	if (argc <= 1) //no numbers
		return (0);
	init(&a);
	init(&b);
	a.stack = (int *) malloc((argc - 1) * sizeof(int));
	b.stack = (int *) malloc((1) * sizeof(int));
	a.len = argc - 1;
	arg_to_stack(argc, argv, &a);
	free(a.stack);
	free(b.stack);
	printf("Started.");
	return (0);
}