/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:34:12 by ablanco-          #+#    #+#             */
/*   Updated: 2023/11/26 18:40:16 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define INPUT 0
#define OUTPUT 1

int	make_fork(void)
{
	int	id;

	id = fork();
	if (id < 0)
	{
		perror("id not found");
		exit(1);
	}
	return (id);
}

int	ft_open(char *file, int type)
{
	int	fd;

	fd = 0;
	if (type == INPUT)
		fd = open(file, O_RDONLY);
	if (type == OUTPUT)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror(file);
		exit(0);
	}
	return (fd);
}

void	input_child(char *infile, char *cmd, int *fd, char **envp)
{
	int	fd_file;
	int	id;

	id = make_fork();
	if (id == 0)
	{
		close(fd[RIGHT]);
		fd_file = ft_open(infile, INPUT);
		dup2(fd_file, 0);
		close(fd_file);
		dup2(fd[LEFT], 1);
		close(fd[LEFT]);
		ft_exec(cmd, envp);
	}
}

void	midle_child(char *cmd, int *fd, char **envp)
{
	int	id;
	int	prev;

	prev = fd[RIGHT];
	close(fd[LEFT]);
	pipe(fd);
	id = make_fork();
	if (id == 0)
	{
		close(fd[RIGHT]);
		dup2(prev, 0);
		close(prev);
		dup2(fd[LEFT], 1);
		close(fd[LEFT]);
		ft_exec(cmd, envp);
	}
}

void	output_child(char *outfile, char *cmd, int *fd, char **envp)
{
	int	id;
	int	fd_file;

	id = make_fork();
	if (id == 0)
	{
		close(fd[LEFT]);
		fd_file = ft_open(outfile, OUTPUT);
		dup2(fd[RIGHT], 0);
		close(fd[RIGHT]);
		dup2(fd_file, 1);
		close(fd_file);
		ft_exec(cmd, envp);
	}
}
