/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:58:17 by ablanco-          #+#    #+#             */
/*   Updated: 2023/11/17 23:49:11 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(char *limit)
{
	char *line;
	int	fd;
	char *limit_aux;

	limit_aux = ft_strjoin(limit, "\n");
	fd = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while(1)
	{
		line = sget_next_line(0);
		if (!ft_strncmp(line, limit_aux, ft_strlen(line)))
			break ;
		ft_putstr_fd(line, fd);
	}
	free(limit_aux);
	close(fd);
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
	int fd[2];
	int i;
	int flag = 0;

	if (argc < 5) //PONER EL LIMITE REAL CUANDO ACABES DE HACER PRUEBITAS
		return(0);
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
	{
		if (argc < 6)
			return (0);
		
		here_doc(argv[2]);
		flag = 1;
	}
		
	pipe(fd);
	input_child(argv[1], argv[2 + flag], fd, envp);
	i = 3 + flag;
	while(i < (argc - 2))
	{
		midle_child(argv[i], fd, envp);
		i++;
	}
	output_child(argv[argc - 1], argv[argc - 2], fd, envp);
	return(0);
}
