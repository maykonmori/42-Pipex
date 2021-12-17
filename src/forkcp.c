/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forkcp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:26:59 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/15 20:52:15 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	parent_proc(char **argv, char **penv, int *fd)
{
	int		outf;

	outf = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outf < 0)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(outf, STDOUT_FILENO);
	close(fd[1]);
	get_exec(argv[3], penv);
}

void	child_proc(char **argv, char **penv, int *fd)
{
	int		inputf;

	inputf = open(argv[1], O_RDONLY);
	if (inputf < 0)
		error();
	dup2(inputf, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	get_exec(argv[2], penv);
}
