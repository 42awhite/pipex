/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:58:17 by ablanco-          #+#    #+#             */
/*   Updated: 2023/11/22 20:55:37 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	fd[2];
	int	status;

	if (argc != 5)
		return (0);
	pipe(fd);
	input_child(argv[1], argv[2], fd, envp);
	output_child(argv[4], argv[3], fd, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
	return (0);
}
