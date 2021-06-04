/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:24:09 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/04 20:41:56 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>   
# include <fcntl.h>
#include <string.h>

typedef struct  s_stack
{
    int			len;
	int			*stack;
	int			id; // 1 pra a, 2 pra b
}               t_stack;

int     main(int argc, char **argv);
long		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	sx(t_stack *s);
void	ss(t_stack *one, t_stack *two);
void	px(t_stack *src, t_stack *dst);
int		init(t_stack *a, t_stack *b, int argc);
void	rx(t_stack *s);
void	rr(t_stack *one, t_stack *two);
void	rrx(t_stack *s);
void	rrr(t_stack *one, t_stack *two);
int	error(t_stack *a, t_stack *b);
int	sort(t_stack *a, t_stack *b);



#endif