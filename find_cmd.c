#include "pipex.h"

char    *find_path(char **envp)
{
    char *path;
    int i = 0;

    while (envp[i])
    {
        if (!ft_strncmp("PATH=", envp[i], 5))
        {
            path = &envp[i][5];
            return(path);
        }
        i++;
    }
    return(NULL);
}
char *find_cmd(char **all_path, char *cmd_to_find)
{
	int i;
	char *cmd;

	i = 0;
	while (all_path[i])
    {
        cmd = ft_strjoin(all_path[i], "/"); //MIRAR POSIBLES LIKS
        cmd = ft_strjoin(cmd, cmd_to_find);
        if (access(cmd, F_OK) == 0)
        	return(cmd);
        i++;
    }
    return(NULL);
}

char *final_cmd (char *cmd, char **envp)
{
    char *path;
    char **all_path;
    char *final_cmd;

    path = find_path(envp);
    all_path = ft_split(path, ':');
	final_cmd = find_cmd(all_path, cmd);
    return(final_cmd);
}