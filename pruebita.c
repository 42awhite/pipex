#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


#define READ_END    0 //Extremo lectura
#define WRITE_END   1 // Extremo escritura

#define FILE_NAME "file.txt"

int main(int argc, char **argv)
{
    int fd1[2]; //Extremo de lectura fd1[0] y el de escritura fd1[1]
    int fd2;    
    int status, pid; //status = noseque del padre, pid = identificador proceso hijos

    pipe(fd1);

    pid = fork();

    if(pid == 0)    //hijo 1 ejecuta "ls -l"
    {
        close(fd1[READ_END]); //Se cierra extremo no necesario

        dup2(fd1[WRITE_END], STDOUT_FILENO);
        close(fd1[WRITE_END]);

        execlp("/bin/ls", "ls", "-l", NULL);
    }
    else        //padre
    {
        close(fd1[WRITE_END]);

        pid = fork();

        if(pid == 0) // 2º hijo que va a ser wc
        {
            fd2 = open(FILE_NAME, O_WRONLY);
            dup2(fd1[READ_END], STDIN_FILENO);
            close(fd1[READ_END]);
            
            dup2(fd2, STDOUT_FILENO);

            execlp("/usr/bin/wc", "wc", NULL);
        }
        else //padre
            close(fd1[READ_END]);
        //wait para cada uno de los hijos
        wait(&status);
        wait(&status);

        return(0);
    }
}