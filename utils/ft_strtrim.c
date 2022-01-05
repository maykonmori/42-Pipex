/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 21:51:15 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/05 15:37:19 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_strchr(const char *str, int n)
{
	int	cont;

	cont = 0;
	while (str[cont] != '\0')
	{
		if (str[cont] == (char)n)
		{
			return ((char *)str + cont);
		}
		cont++;
	}
	if (n == '\0')
		return ((char *)str + cont);
	return (0);
}


static char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = (int) ft_strlen(str);
	while (i > -1)
	{
		if (str[i] == (unsigned char) c)
		{
			return ((char *)str + i);
		}
		i--;
	}
	return (0);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	srclen;
	char	*str;

	if (!s)
		return (NULL);
	srclen = ft_strlen(s);
	if (start > srclen)
		return (ft_strdup(""));
	if (start + len > srclen)
		len = srclen - start;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	ls1;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1) != NULL)
		s1++;
	ls1 = ft_strlen(s1);
	while (ls1 && ft_strrchr(set, s1[ls1]))
		ls1--;
	return (ft_substr((char *)s1, 0, ls1 + 1));
}
