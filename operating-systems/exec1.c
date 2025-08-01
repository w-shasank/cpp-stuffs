#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc , char *argv[])
{
    printf("HEllo this is a parent process : (pid :%d) \n",(int)getpid());
    int rc = fork();
    if(rc<0)
    {
        printf("THe fork has been failed .\n");
        exit(1);
    }
    else if (rc ==0)
    {
        printf("The child class of the process %d has been created with (pid ; %d)",(int)getpid(),rc);
         execlp("ls", "ls", "-l","../", NULL);

        perror("execlp failed");
        exit(1);
    }
     else{
        printf("Hello, I am a parent of %d (pid : %d)\n",(int)getpid(),rc );
    }
    return 0;
}