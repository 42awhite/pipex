/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:59:39 by ablanco-          #+#    #+#             */
/*   Updated: 2023/11/22 20:46:53 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec(char *cmd, char **envp)
{
	char	*fn_cmd;
	char	**cmd_arg;

	cmd_arg = ft_split(cmd, ' ');
	if (cmd_arg == NULL || cmd_arg[0] == NULL)
	{
		ft_printf("%s: cmd not found", cmd);
		exit(1);
	}
	if (!strncmp(cmd_arg[0], "/", 1) || !strncmp(cmd_arg[0], "./", 2)
		|| !strncmp(cmd_arg[0], "../", 3))
	{
		execve(cmd_arg[0], cmd_arg, envp);
		perror(cmd_arg[0]);
		exit(0);
	}
	else
	{
		fn_cmd = final_cmd(cmd_arg[0], envp);
		execve(fn_cmd, cmd_arg, envp);
		perror(cmd_arg[0]);
		exit(0);
	}
}
