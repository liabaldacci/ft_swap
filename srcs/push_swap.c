/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranco- <nfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:30:48 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/24 22:26:26 by nfranco-         ###   ########.fr       */
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

int		check_duplicates(t_stack *a, int nr)
{
	int i;

	i = 0;
	while (a->stack[i])
	{
		if(nr == a->stack[i])
			return(-1);
		i++;
	}
	return(0);	
}

int		arg_to_stack_str(char **temp, t_stack *a)
{
	int i;
	int nr;

	i = 0;
	while (temp[i])
	{
		if (is_valid_number(temp[i]) == 0)
			return (-1);
		nr = ft_atoi(temp[i]);
		if (check_duplicates(a, nr) == -1)
			return (-1);		
		a->stack[i] = nr;
		i++;
	}
	a->len = i;
	return (0);	
}

int		arg_to_stack(int argc, char *argv[], t_stack *a)
{
	int i;
	int nr;

	i = 0;
	while (i < argc - 1)
	{
		if (is_valid_number(argv[i + 1]) == 0)
			return (-1);
		nr = ft_atoi(argv[i + 1]);
		if (check_duplicates(a, nr) == -1)
			return (-1);		
		a->stack[i] = nr;
		i++;
	}
	a->len = i;
	return (0);	
}

int		check_args(int argc, char *argv[], t_stack *a, t_stack *b)
{
	int	i;
	char **temp;

	i = 1;
	if (argc > 2)
	{
		if (arg_to_stack(argc, argv, a) == -1)
			return (error(a, b));
	}
	else
	{
		temp = ft_split(argv[1], ' ');
		if (arg_to_stack_str(temp, a) == -1)
			return (error(a, b));
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
		fflush(stdout);
		i++;
	}
	printf("\n");
}

int     main(int argc, char **argv)
{
	t_stack	a;
	t_stack b;

	// printf("ARGC %i\n", argc);
	// printf("ARGV %s\n", argv[1]);
	if (init(&a, &b, argc) == -1)
		return (error(&a, &b));
	check_args(argc, argv, &a, &b);
	// if (arg_to_stack(argc, argv, &a) == -1)
	// 	return (error(&a, &b));
	//TODO: NÃO PERMITIR DUPLICADOS
	// printf("STACK A BEFORE:\n");
	// print_stack(&a);
	// printf("STACK B BEFORE:\n");
	// print_stack(&b);

	// printf("\nOPERATIONS:\n");
	sort(&a, &b);

	printf("\nSTACK A AFTER:\n");
	print_stack(&a);
	// printf("STACK B AFTER:\n");
	// print_stack(&b);

	free(a.stack);
	free(b.stack);
	return (0);
}