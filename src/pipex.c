/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:26:56 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/15 20:26:57 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	pipex(char **argv, char **penv, int *fd)
{
	pid_t	child;

	if (pipe(fd) == -1)
		error();
	child = fork();
	if (child == -1)
		error();
	if (child == 0)
		child_proc(argv, penv, fd);
	child = fork();
	if (child == 0)
	{
		waitpid(child, NULL, 0);
		parent_proc(argv, penv, fd);
	}
	close(fd[0]);
	close(fd[1]);
}

int	main(int argc, char **argv, char **penv)
{
	int	fd[2];

	if (argc != 5)
	{
		if (argc > 5)
			error_ar("Too many arguments", EXIT_FAILURE);
		if (argc < 5)
			error_ar("Have few arguments", EXIT_FAILURE);
	}
	pipex(argv, penv, fd);
	return (0);
}
