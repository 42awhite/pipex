/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:58:17 by ablanco-          #+#    #+#             */
/*   Updated: 2023/08/31 20:07:33 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_pipex(int f1, int f2)
{
	int end[2];
	int	parent;
	
	pipe(end);
	parent = fork();
	if (parent < 0)
		return(perror("Fork: "));
	if (parent == 0) //Si el procecso padre = 0, estamos en el proceso hijo
		child_process(f1, cmd1);
	else
		parent_process(f2, cmd2);
		
}
int main (int argc, char **argv, char **envp)
{
	int f1;
	int f2;
	
	f1 = open(....completar.....)
}

//#define LEFT 1
//#define RIGHT 0

// int	main(int argc, char *argv[], char *envp[])
// {
// 	char *cmd1[] = {"ls", "-l", NULL};
// 	char *cmd2[] = {"wc", "-c", NULL};
// 	int fd[2];
// 	pid_t id;
		
// 	pipe(fd);
// 	dprintf(2, "L = %d R = %d\n", fd[LEFT], fd[RIGHT]);
// 	id = fork();
// 	if (id == 0)
// 	{
// 		close(fd[RIGHT]);
// 		dup2(fd[LEFT], 1);
// 		close(fd[LEFT]);
// 		execve("/bin/ls", cmd1, envp);
// 	}
// 	id = fork();
// 	if (id == 0)
// 	{
// 		close(fd[LEFT]);
// 		dup2(fd[RIGHT], 0);
// 		dup2(,);
// 		close(fd[RIGHT]);
// 		execve("/usr/bin/wc", cmd2, envp);
// 	}
// 	printf("hola Pepe\n");
// 	return(0);
// }
/*
int	main(int argc, char *argv[], char *envp[])
{
	char *cmd1[] = {"ls", "-l", NULL};
	pid_t id;
		
	id = fork();
	if (id == 0)
	{
	execve("/bin/ls", cmd1, envp);
	}
	return(0);
}
*/