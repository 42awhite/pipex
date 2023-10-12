/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:59:39 by ablanco-          #+#    #+#             */
/*   Updated: 2023/10/12 17:08:08 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_exec(char *cmd, char **envp)
{
	char *fn_cmd;
	char **cmd_arg;
	
	cmd_arg = ft_split(cmd, ' ');
	if (access(cmd, F_OK + X_OK) != 0) //esto está malm hacer Pepeforma buscando la / ./ ../ en argv, si tiene esto no hacer join
	{
		fn_cmd = final_cmd(cmd_arg[0], envp);
		execve(fn_cmd, cmd_arg, envp);
	}
	else
		execve(cmd_arg[0], cmd_arg, envp);
}