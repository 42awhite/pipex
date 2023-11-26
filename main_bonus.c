/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:58:17 by ablanco-          #+#    #+#             */
/*   Updated: 2023/11/26 18:20:19 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(char *limit)
{
	char	*line;
	int		fd;
	char	*limit_aux;

	limit_aux = ft_strjoin(limit, "\n");
	fd = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		line = sget_next_line(0);
		if (!line || !ft_strncmp(line, limit_aux, ft_strlen(line)))
			break ;
		ft_putstr_fd(line, fd);
	}
	free(limit_aux);
	close(fd);
}

int	check_heredoc(char **argv, int argc)
{
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
	{
		if (argc < 6)
			exit(1);
		here_doc(argv[2]);
		return (1);
	}
	return (0);
}

void	wait_dad(int argc, int flag)
{
	int	status;
	int	n_cmd;

	n_cmd = argc - 3 - flag;
	while (n_cmd > 0)
	{
		waitpid(-1, &status, 0);
		n_cmd--;
	}
	exit(WEXITSTATUS(status));
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd[2];
	int	i;
	int	flag;

	if (argc < 5)
		return (0);
	flag = check_heredoc(argv, argc);
	pipe(fd);
	input_child(argv[1], argv[2 + flag], fd, envp);
	i = 3 + flag;
	while (i < (argc - 2))
	{
		midle_child(argv[i], fd, envp);
		i++;
	}
	output_child(argv[argc - 1], argv[argc - 2], fd, envp);
	close(fd[0]);
	close(fd[1]);
	if (flag == 1)
		unlink("here_doc");
	wait_dad(argc, flag);
	return (0);
}
