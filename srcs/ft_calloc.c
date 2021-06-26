/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranco- <nfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 21:52:18 by nfranco-          #+#    #+#             */
/*   Updated: 2021/06/26 02:31:40 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr2;
	size_t	i;
	char	*ptr1;

	i = 0;
	ptr2 = malloc(count * size);
	ptr1 = ptr2;
	if (ptr1 == NULL)
		return (NULL);
	while (i < (count * size))
	{
		*ptr1 = '\0';
		ptr1++;
		i++;
	}
	return (ptr2);
}

void	*ft_calloc_alternative(size_t count, size_t size)
{
	void	*ptr2;
	size_t	i;
	char	*ptr1;

	i = 0;
	ptr2 = malloc(count * size);
	ptr1 = ptr2;
	if (ptr1 == NULL)
		return (NULL);
	while (i < (count * size))
	{
		*ptr1 = '-';
		ptr1++;
		i++;
	}
	return (ptr2);
}
