/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 16:36:59 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/05 14:24:20 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(char *s)
{
	char	*new;
	char	*res;
	ssize_t	i;

	i = 0;
	while ((s[i] != '\0'))
		i++;
	res = malloc(i + 1);
	new = res;
	while (*s)
		*new++ = *s++;
	*new = 0;
	return (res);
}
