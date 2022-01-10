/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forkcp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:26:59 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/05 20:43:45 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_proc(t_pipex *data)
{
	data->outf = open(data->args.argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data->outf < 0)
		error(EXIT_FAILURE);
	dup2(data->args.fd[0], STDIN_FILENO);
	dup2(data->outf, STDOUT_FILENO);
	close(data->args.fd[1]);
	handling_arg(data, 3);
	get_exec(data->args.argv[3], data);
}

void	child_proc(t_pipex *data)
{
	data->inputf = open(data->args.argv[1], O_RDONLY);
	if (data->inputf < 0)
		error(EXIT_FAILURE);
	dup2(data->inputf, STDIN_FILENO);
	dup2(data->args.fd[1], STDOUT_FILENO);
	close(data->args.fd[0]);
	handling_arg(data, 2);
	get_exec(data->args.argv[2], data);
}
