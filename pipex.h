/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:30:44 by mjose-ye          #+#    #+#             */
/*   Updated: 2021/12/15 20:31:05 by mjose-ye         ###   ########.fr       */
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

void	error_ar(char *s, int n);
void	error(void);
void	free_matriz(char **s);
char	*command_path(char *cmd);
void	parent_proc(char **argv, char **penv, int *fd);
void	child_proc(char **argv, char **penv, int *fd);
void	pipex(char **argv, char **penv, int *fd);
void	get_exec(char *argv, char **penv);

#endif