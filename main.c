/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:58:17 by ablanco-          #+#    #+#             */
/*   Updated: 2023/05/08 19:06:42 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[], char *envp[])
{
	char *matrix[] = {"ls", "-l", NULL};
	pid_t id;

	id = fork();
	if (id == 0)
		execve("/bin/ls", matrix, envp);
	printf("hola Pepe\n");

	//while(envp[cont])
	//
	//{
	//	printf("%s, \n", envp[cont]);
	//	cont++;
	//}
	return(0);
}
