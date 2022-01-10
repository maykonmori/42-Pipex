/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 08:54:12 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/06 18:36:04 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	*ft_calloc(size_t num, size_t size)
{
	size_t	aux;
	void	*c;

	aux = num * size;
	c = malloc(aux);
	if (!c)
		return (0);
	ft_bzero(c, aux);
	return (c);
}

static void	complement_split(char *s, char c, char **arr)
{
	size_t	cont;
	size_t	cchr;
	size_t	carr;

	cont = 0;
	carr = -1;
	while (s[cont] != '\0')
	{
		if (s[cont] == c)
			cont++;
		else
		{
			cchr = 0;
			while (s[cont] != c && s[cont] != '\0')
			{
				cont++;
				cchr++;
			}
			arr[++carr] = ft_calloc(cchr + 1, sizeof(char));
			ft_strlcpy(arr[carr], &s[cont - cchr], cchr + 1);
		}
	}
	arr[carr + 1] = NULL;
}

static size_t	str_quantity(char *str, char del)
{
	size_t	qstr;
	size_t	cont;

	qstr = 0;
	cont = 0;
	while (str[cont] != '\0')
	{
		if (del == str[cont])
		{
			cont++;
		}
		else
		{
			while (str[cont] != del && str[cont] != '\0')
			{
				cont++;
			}
			qstr++;
		}
	}
	return (qstr);
}

char	**ft_split(char *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)ft_calloc(str_quantity(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	complement_split(s, c, arr);
	return (arr);
}
