/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:39:22 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/05 20:43:38 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_args(int argc, char **argv, char **envp, t_pipex *data)
{
	data->args.argc = argc;
	data->args.argv = argv;
	data->args.envp = envp;
}
