/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:58:17 by ablanco-          #+#    #+#             */
/*   Updated: 2023/10/25 19:08:49 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(char *ar_1, char *limit)
{
	char *line;
	int	fd;

	fd = open("here_doc.txt", O_RDONLY);
	while(limit != get_next_line[0]) //Este gnl no va a ser el mismo que el de abajo, poner while 1 para bucle infinito, Hacer break con el delimitador.
	{
		line = get_next_line[0];
		ft_putstr_fd(line, fd);
	}
}


int	main(int argc, char *argv[], char *envp[])
{
	int fd[2];
	char *hd;
		
	hd = "here_doc";
	//if (argc <= 6)
	//	return(0);
	if (ft_strncmp(argv[1], hd, 7) == 0)
		here_doc(argv[1], argv[2], fd[0]);
	pipe(fd);
	input_child(argv[3], argv[4], fd, envp);
	output_child(argv[6], argv[5], fd, envp);
	return(0);
}
