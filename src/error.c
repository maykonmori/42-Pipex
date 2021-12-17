/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:22:23 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/15 20:24:45 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_ar(char *s, int n)
{
	printf("\033[31mERROR: %s\n\e[0m", s);
	printf("\033[31mCommand: ./pipex file_in <cmd1> <cmd2> file_out\n\e[0m");
	exit(n);
}

void	error(void)
{
	perror("\033[31m/Error\e[0m");
	exit(EXIT_FAILURE);
}
