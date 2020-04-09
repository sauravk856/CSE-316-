#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argv, char **args)
{
    int pipefds[2];
    int writefd = open(*(args+2), O_WRONLY);
    int readfd = open(*(args+1), O_RDONLY);
    int pid = fork();
    if(pid != 0)
    {
        if(pipe(pipefds) == -1){
            printf("Unable to open file\n");
            return;
        }
        if(writefd == -1 || readfd == -1)
        {
            printf("Unable to open file\n");
            return;
        }
        while(1)
        {
            char r;
            int c = read(readfd[0], r, 1);
            if(c == 0)
                break;
            else
            {
                write(pipefds[2], c, 1);
            }
        }
    }
    else
    {
        while(1)
        {
            char r;
            int c = read(pipefds[0], r, 1);
            if(c == 0)
                break;
            else
            {
                write(writefd, c, 1);
            }
        }
    }
    return 0;
}
