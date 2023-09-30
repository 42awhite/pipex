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


int main (int argc, char **argv, char **envp)
{
    argc = 0;
    argv = NULL;
    char *path;
    char **all_path;

    //int i = 0;
    //while (envp[i])
    //{
    //    printf("%s\n", envp[i]);
    //    i++;
    //}
    //printf("\n------------HASTA AQUI ENVP------------------\n");

    path = find_path(envp);
    printf("%s \n",path);
    
    all_path = ft_split(path, ':');

    int i = 0;
    while (all_path[i])
    {
        printf("%s\n", all_path[i]);
        i++;
    }
}