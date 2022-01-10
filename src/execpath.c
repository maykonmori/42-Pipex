/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:25:53 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/10 15:46:38 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handling_arg(t_pipex *data, int nargv)
{
	int	i;
	int	j;

	i = 0;
	while (data->args.argv[nargv][i])
	{
		if (data->args.argv[nargv][i] == '\'')
		{
			j = i + 1;
			while (data->args.argv[nargv][j] != '\'')
			{
				if (data->args.argv[nargv][j] == ' ')
					data->args.argv[nargv][j] = '`';
				j++;
			}
			return ;
		}
		i++;
	}
	return ;
}

void	return_space(char **command)
{
	int		i;
	int		j;
	char	*temp;

	i = -1;
	while (command[++i])
	{
		j = -1;
		while (command[i][++j])
		{
			if (command[i][j] == '`')
			{
				while (command[i][j] == '`')
				{
					command[i][j] = ' ';
					j++;
				}
				temp = ft_strdup(command[i]);
				free(command[i]);
				command[i] = ft_strtrim(temp, "\'");
				free(temp);
				return ;
			}
		}
	}
}

char	*command_path(char *cmd)
{
	char	**path;
	char	*temp;
	int		i;

	if (cmd == NULL)
		return (NULL);
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

void	get_exec(char *argv, t_pipex *data)
{
	char	**command;
	char	*return_command;

	command = ft_split(argv, ' ');
	return_space(command);
	return_command = command_path(command[0]);
	if (execve(return_command, command, data->args.envp) < 0)
	{
		free_matriz(command);
		error_nfound(127);
	}
	if (return_command == NULL)
	{
		free_matriz(command);
		error(127);
	}
}
