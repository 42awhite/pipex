/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:00:19 by ablanco-          #+#    #+#             */
/*   Updated: 2023/11/17 23:13:46 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

# define LEFT 1
# define RIGHT 0

void	input_child(char *infile, char *cmd, int *fd, char **envp);
void 	midle_child(char *cmd, int *fd, char **envp);
void	output_child(char *outfile, char *cmd, int *fd, char **envp);

char	*final_cmd (char *cmd, char **envp);
void	ft_exec(char *cmd, char **envp);

# endif

