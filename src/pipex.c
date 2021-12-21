/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:26:56 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/21 18:38:13 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	pipex(t_pipex	*data)
{
	if (pipe(data->args.fd) == -1)
		error(EXIT_FAILURE);
	data->child = fork();
	if (data->child == -1)
		error(EXIT_FAILURE);
	if (data->child == 0)
		child_proc(data);
	close(data->args.fd[1]);
	data->child = fork();
	if (data->child == 0)
		parent_proc(data);
	waitpid(data->child, NULL, 0);
	close(data->args.fd[0]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (argc != 5)
	{
		if (argc > 5)
			error_ar("Too many arguments", EXIT_FAILURE);
		if (argc < 5)
			error_ar("Have few arguments", EXIT_FAILURE);
	}
	else
	{
		init_args(argc, argv, envp, &data);
		pipex(&data);
	}
	return (0);
}

// int	main(int argc, char **argv, char **envp)
// {
// 	t_pipex	data;

// 	if (argc != 5)
// 	{
// 		if (argc > 5)
// 			error_ar("Too many arguments", EXIT_FAILURE);
// 		if (argc < 5)
// 			error_ar("Have few arguments", EXIT_FAILURE);
// 	}
// 	init_args(argc, argv, envp, &data);
// 	pipex(&data);
// 	return (0);
// }
