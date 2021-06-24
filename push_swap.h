/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranco- <nfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:24:09 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/25 00:48:43 by nfranco-         ###   ########.fr       */
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
	int			min;
	int			max;
	int			pb_nbr;
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
int		sort_large(t_stack *a, t_stack *b);
int	sort_five(t_stack *a, t_stack *b);
int	sort_three(t_stack *a);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);



#endif