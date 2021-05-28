/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:24:09 by gadoglio          #+#    #+#             */
/*   Updated: 2021/05/28 17:57:57 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include <stdio.h>
# include <stdlib.h>
# include <math.h>   
# include <fcntl.h>
#include <string.h>

typedef struct  s_stack
{
    int			len;
	int			*stack;
}               t_stack;

int     main(int argc, char **argv);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);



#endif