#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char  **argv)
{
    pid_t p;
    int n = atoi(*(argv+1));
    int status;
    p = fork();
    if(p != 0)
    {
        printf("The parent is waiting while child is working\n");
        wait(&status);
        printf("The child has finished and parent is exiting");
    }
    else 
    {
        if(n == 0)
        {
            printf("0 cannot form the desired sequence\n");
        }
        else if(n%2 == 1)
        {
            printf("Odd number cannot form the desired sequence\n");
        }
        else 
        {
            int i;
            for(i = n; i >= 1; i/=2)
            {
                printf("%d ", i);
            }
            printf("\n");
        }
    }
    
	return 0;
}
