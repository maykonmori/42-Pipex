/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:22:23 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/22 22:05:09 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_arg(int argc)
{
	if (argc > 5)
	{
		write(2, "\033[31mERROR: \e[0m", 17);
		write(2, "Too many arguments\n", 20);
		write(2, "Command: ./pipex file_in <cmd1> <cmd2> file_out\n", 49);
		exit(EXIT_FAILURE);
	}
	if (argc < 5)
	{
		write(2, "\033[31mERROR: \e[0m", 17);
		write(2, "Have few arguments\n", 20);
		write(2, "Command: ./pipex file_in <cmd1> <cmd2> file_out\n", 49);
		exit(EXIT_FAILURE);
	}
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
