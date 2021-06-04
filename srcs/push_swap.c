/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:30:48 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/04 20:51:01 by gadoglio         ###   ########.fr       */
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
		if (!a->stack[j])
			return (-1);
		i--;
		j++;
	}
	a->len = j;
	return (0);	
}

int		check_args(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_valid_number(argv[i]) == 0)
			return (-1);
		ft_atoi(argv[i]);
		i--;
	}
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

	if (init(&a, &b, argc) == -1)
		return (error(&a, &b));
	check_args(argc, argv);
	if (arg_to_stack(argc, argv, &a) == -1)
		return (error(&a, &b));

	printf("STACK A BEFORE:\n");
	print_stack(&a);
	printf("STACK B BEFORE:\n");
	print_stack(&b);

	printf("\nOPERATIONS:\n");
	sort(&a, &b);

	printf("\nSTACK A AFTER:\n");
	print_stack(&a);
	printf("STACK B AFTER:\n");
	print_stack(&b);

	free(a.stack);
	free(b.stack);
	return (0);
}