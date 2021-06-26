/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranco- <nfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:30:48 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/26 02:50:44 by nfranco-         ###   ########.fr       */
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
	while (i < a->len)
	{
		if(nr == a->stack[i])
			return (-1);
		i++;
	}
	return(0);	
}

int		arg_to_stack_str(char **temp, t_stack *a)
{
	int i;
	int nr;

	i = 0;
	a->stack = (int *) ft_calloc_alternative((a->len), sizeof(int));
	while (temp[i])
	{
		if (is_valid_number(temp[i]) == 0)
			return (-1);
		nr = ft_atoi(temp[i]);
		if ((i > 0) && (check_duplicates(a, nr) == -1))
			return (-1);		
		a->stack[i] = nr;
		i++;
	}
	return (0);	
}

int		arg_to_stack(int argc, char *argv[], t_stack *a)
{
	int i;
	int nr;

	i = 0;
	a->stack = (int *) ft_calloc_alternative((argc - 1), sizeof(int));
	while (i < argc - 1)
	{
		if (is_valid_number(argv[i + 1]) == 0)
			return (-1);
		nr = ft_atoi(argv[i + 1]);
		a->len++;
		if (check_duplicates(a, nr) == -1)
			return (-1);		
		a->stack[i] = nr;
		i++;
	}
	return (0);	
}

int		check_args(int argc, char *argv[], t_stack *a, t_stack *b)
{
	int	i;
	char **temp;

	if (argc > 2)
	{
		if (arg_to_stack(argc, argv, a) == -1)
			return (error(a, b));
	}
	else if (argc == 1)
		return (0);
	else
	{
		temp = ft_split(argv[1], ' ', a);
		if (arg_to_stack_str(temp, a) == -1)
			return (error(a, b));
		i = 0;
		while (i < a->len)
		{
			free (temp[i]);
			i++;
		}
		free (temp);
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

	init(&a, &b);
	check_args(argc, argv, &a, &b);
	// printf("STACK A BEFORE:\n");
	// print_stack(&a);
	// printf("STACK B BEFORE:\n");
	// print_stack(&b);

	// printf("\nOPERATIONS:\n");
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