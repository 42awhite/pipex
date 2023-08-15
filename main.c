/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:58:17 by ablanco-          #+#    #+#             */
/*   Updated: 2023/08/15 20:38:47 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[], char *envp[])
{
	char *cmd1[] = {"ls", "-l", NULL};
	char *cmd2[] = {"ls", NULL};
	int fd[2];
	pid_t id;
		
	pipe(fd);
	id = fork();
	if (id == 0)
		execve("/bin/ls", cmd1, envp);
	id = fork();
	if (id == 0)
		execve("/bin/ls", cmd2, envp);
	printf("hola Pepe\n");

	//while(envp[cont])
	//
	//{
	//	printf("%s, \n", envp[cont]);
	//	cont++;
	//}
	return(0);
}
