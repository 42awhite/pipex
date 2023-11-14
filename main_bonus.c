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

void	here_doc(char *limit)
{
	char *line;
	int	fd;

	fd = open("here_doc.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while(1)
	{
		line = sget_next_line(0);
		if (!ft_strncmp(line, limit, ft_strlen(limit)))
			break ;
		ft_putstr_fd(line, fd);
	}
}

/* MAIN PARA COMPROBAR SOLO FUN HERE_DOC
int main(void)
{
	char *delimit;

	delimit = "sal";
	here_doc(delimit);
	return(0);
}
*/

int	main(int argc, char *argv[], char *envp[])
{
	//int fd[2];
	char *hd;

	(void)envp[0];	
	hd = "here_doc";
	if (argc <= 1) //PONER EL LIMITE REAL CUANDO ACABES DE HACER PRUEBITAS
		return(0);
	if (ft_strncmp(argv[1], hd, ft_strlen(argv[1])) == 0)
		here_doc(argv[2]);
	/*
	pipe(fd);
	input_child(argv[3], argv[4], fd, envp);
	output_child(argv[6], argv[5], fd, envp);
	*/
	return(0);
}
