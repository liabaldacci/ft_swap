/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:30:48 by gadoglio          #+#    #+#             */
/*   Updated: 2021/05/28 18:02:49 by gadoglio         ###   ########.fr       */
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

	i = 1;
	while (i < argc)
	{
		if (is_valid_number(argv[i]) == 0)
			return (-1);
		a->stack[i - 1] = ft_atoi(argv[i]);
		printf("number: %i.\n", a->stack[i - 1]);
		i++;
	}
	return (0);	
}

int     main(int argc, char **argv)
{
	t_stack	a;
	// t_stack b;
	if (argc <= 1) //no numbers
		return (0);
	a.stack = (int *) malloc((argc - 1) * sizeof(int));
	a.len = argc - 1;
	arg_to_stack(argc, argv, &a);
	free(a.stack);
	printf("Started.");
	return (0);
}