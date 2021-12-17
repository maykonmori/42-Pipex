/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:25:53 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/15 21:02:07 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*command_path(char *cmd)
{
	char	**path;
	char	*path_proc;
	char	*temp;
	int		i;

	path = ft_split(PATH, ':');
	i = 0;
	while (path[i])
	{
		temp = ft_strjoin(path[i], cmd);
		if (access(temp, F_OK) == 0)
		{
			free_matriz(path);
			return (temp);
		}
		free(temp);
		i++;
	}
	free_matriz(path);
	return (NULL);
}

void	get_exec(char *argv, char **penv)
{
	char	**command;

	command = ft_split(argv, ' ');
	if (execve(command_path(command[0]), command, penv) < 0)
		error();
}
