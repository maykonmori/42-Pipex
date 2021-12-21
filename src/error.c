/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:22:23 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/21 18:51:34 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_ar(char *s, int n)
{
	printf("\033[31mERROR: %s\n\e[0m", s);
	printf("\033[31mCommand: ./pipex file_in <cmd1> <cmd2> file_out\n\e[0m");
	exit(n);
}

void	error(int e)
{
	perror("\033[31mError\e[0m");
	exit(e);
}

void	error_nfound(int e)
{
	write(2, "\033[31mError:\e[0m", 17);
	write(2, " command not found", 19);
	write(2, "\n", 1);
	exit(e);
}
