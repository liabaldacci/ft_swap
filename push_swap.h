/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranco- <nfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:24:09 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/26 05:41:50 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef	PUSH_SWAP
# define	PUSH_SWAP
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>   
# include <fcntl.h>
# include <string.h>

typedef struct	s_stack
{
	int	len;
	int	*stack;
	int	id;
	int	min;
	int	max;
	int	chunk_count;
}	t_stack;

int	main(int argc, char **argv);
int	ft_isdigit(int c);
int	init(t_stack *a, t_stack *b);
int	error(t_stack *a, t_stack *b);
int	sort(t_stack *a, t_stack *b);
int	sort_large(t_stack *a, t_stack *b);
int	sort_five(t_stack *a, t_stack *b);
int	sort_three(t_stack *a);
int	find_min_idx(t_stack *stack);
int	decide_chunks(int len);
int	split_chunks(t_stack *a, t_stack *b, int chunks);
int	find_max_idx(t_stack *stack);
int	find_min_idx(t_stack *stack);
int	find_max(t_stack *stack);
int	find_min(t_stack *stack);
int	find_threshold(t_stack *a, int chunks);
int	ft_abs(int i);
int	check_args(int argc, char *argv[], t_stack *a, t_stack *b);
char	**ft_split(char const *s, char c, t_stack *a);
long	ft_atoi(const char *str);
void	sx(t_stack *s);
void	ss(t_stack *one, t_stack *two);
void	px(t_stack *src, t_stack *dst);
void	rx(t_stack *s);
void	rr(t_stack *one, t_stack *two);
void	rrx(t_stack *s);
void	rrr(t_stack *one, t_stack *two);
void	*ft_calloc(size_t count, size_t size);
void	*ft_calloc_alternative(size_t count, size_t size);
void	return_single_chunk(t_stack *a, t_stack *b, int min);
void	return_all_chunks(t_stack *a, t_stack *b, int chunks, int thresh);
void	sort_last_chunk(t_stack *a, t_stack *b);
void	send_smallest(t_stack *a, t_stack *b);
void	single_chunk(t_stack *a, t_stack *b, int min);
void	send_chunk(t_stack *a, t_stack *b, int thresh);

#endif