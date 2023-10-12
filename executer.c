/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:59:39 by ablanco-          #+#    #+#             */
/*   Updated: 2023/10/12 13:16:09 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_exec(char *cmd, char **envp)
{
	char *fn_cmd;
	char **cmd_arg;
	
	cmd_arg = ft_split(cmd, ' ');
	fn_cmd = final_cmd(cmd_arg[0], envp);
	execve(fn_cmd, cmd_arg, envp);
}