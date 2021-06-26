/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranco- <nfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:05:15 by gadoglio          #+#    #+#             */
/*   Updated: 2021/06/26 02:57:04 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	atoi_error(void)
{
	write(2, "Error.\n", 7);
	exit(0);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	nbr;
	int		negative;

	nbr = 0;
	negative = 1;
	i = 0;
	while ((str[i] >= 8 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	if (nbr > 2147483647 || nbr < -2147483648)
		atoi_error();
	return (nbr * negative);
}
