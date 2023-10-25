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
    char *tmp_cmd;

	i = 0;
	while (all_path[i])
    {
        tmp_cmd = ft_strjoin(all_path[i], "/"); 
        cmd = ft_strjoin(tmp_cmd, cmd_to_find);
        //system("sleep 10");
        free(tmp_cmd);
        if (access(cmd, F_OK) == 0)
        	return(cmd);
        free(cmd);
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