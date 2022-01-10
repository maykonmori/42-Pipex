/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:26:56 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/10 15:46:56 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_pipex	*data)
{
	if (pipe(data->args.fd) == -1)
		error(EXIT_FAILURE);
	data->pid = fork();
	if (data->pid == -1)
		error(EXIT_FAILURE);
	if (data->pid == 0)
		child_proc(data);
	parent_proc(data);
	waitpid(data->pid, &data->args.wstatus, 0);
	close(data->args.fd[1]);
	close(data->args.fd[0]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (argc != 5)
		error_arg(argc);
	else
	{
		init_args(argc, argv, envp, &data);
		pipex(&data);
		exit(WEXITSTATUS(data.args.wstatus));
	}
	return (0);
}
