/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:30:44 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/22 16:58:56 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "./libft/libft.h"

# define PATH "/usr/local/sbin/:/usr/local/bin/:/usr/sbin/:/usr/bin/:/sbin/:/\
bin/:/usr/games/:/usr/local/games/:/snap/bin/"

typedef struct s_args
{
	int		argc;
	int		fd[2];
	char	**argv;
	char	**envp;
	int		wstatus;
}	t_args;

typedef struct s_space
{
	int	cmd_one;
	int	cmd_two;
}	t_space;

typedef struct s_pipex
{
	int		inputf;
	int		outf;
	t_space	space;
	t_args	args;
	pid_t	pid;

}	t_pipex;

void	init_args(int argc, char **argv, char **envp, t_pipex *data);
void	error_arg(int argc);
void	error(int e);
void	error_nfound(int e);
void	free_matriz(char **s);
char	*command_path(char *cmd);
void	parent_proc(t_pipex *data);
void	child_proc(t_pipex *data);
void	pipex(t_pipex	*data);
void	get_exec(char *argv, t_pipex *data);
void	handling_arg(t_pipex *data, int nargv);
void	return_space(char **command);

#endif