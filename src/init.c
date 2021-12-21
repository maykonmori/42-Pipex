/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:39:22 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/17 23:55:14 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	init_args(int argc, char **argv, char **envp, t_pipex *data)
{
	data->args.argc = argc;
	data->args.argv = argv;
	data->args.envp = envp;
}
