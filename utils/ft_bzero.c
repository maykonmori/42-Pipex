/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:41:38 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/05 15:02:26 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	*ft_memset(void *s, int c, size_t len)
{
	size_t	aux;
	char	*t;

	t = s;
	aux = 0;
	while (aux < len)
	{
		t[aux] = c;
		aux++;
	}
	return (t);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}