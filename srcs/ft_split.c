/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranco- <nfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 21:51:08 by nfranco-          #+#    #+#             */
/*   Updated: 2021/06/24 21:53:36 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int		ft_nelements(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static int		ft_strlen_char(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char		**ft_callocelements(char const *s, char c)
{
	char	**new;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!(new = (char **)ft_calloc((ft_nelements(s, c) + 1), sizeof(char *))))
		return (NULL);
	if (ft_nelements(s, c) == 0)
		return (new);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!(new[j] = (char *)ft_calloc((ft_strlen_char(s + i, c) + 1), 1)))
			return (NULL);
		k = 0;
		while (s[i] && s[i] != c)
			new[j][k++] = s[i++];
		while (s[i] && s[i] == c)
			i++;
		j++;
	}
	return (new);
}

char			**ft_split(char const *s, char c)
{
	char	**new;

	if (!s)
		return (NULL);
	new = ft_callocelements(s, c);
	return (new);
}
