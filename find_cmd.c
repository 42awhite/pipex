/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:07:52 by ablanco-          #+#    #+#             */
/*   Updated: 2023/11/30 19:03:43 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(char *str)
{
	perror(str);
	exit(7);
}

char	*find_path(char **envp)
{
	char	*path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp("PATH=", envp[i], 5))
		{
			path = &envp[i][5];
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	*find_cmd(char **all_path, char *cmd_to_find)
{
	int		i;
	char	*cmd;
	char	*tmp_cmd;

	i = 0;
	while (all_path[i])
	{
		tmp_cmd = ft_strjoin(all_path[i], "/");
		if (!tmp_cmd)
			ft_perror("Join Error");
		cmd = ft_strjoin(tmp_cmd, cmd_to_find);
		if (!cmd)
			ft_perror("Join Error");
		free(tmp_cmd);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		free(cmd);
		i++;
	}
	return (NULL);
}

char	*final_cmd(char *cmd, char **envp)
{
	char	*path;
	char	**all_path;
	char	*final_cmd;

	path = find_path(envp);
	all_path = ft_split(path, ':');
	if (!all_path)
		ft_perror("Split error");
	final_cmd = find_cmd(all_path, cmd);
	return (final_cmd);
}
