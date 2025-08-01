#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
    while(1)
    {
    printf("Hello world !! (pid : %d)\n",(int)getpid());
    int rc =fork();
    if(rc<0)
    {
        fprintf(stderr,"Fork Failed :\n");
        exit(1);
    }
    else if (rc==0)
    {
        printf("Hello I am child (pid ; %d)",(int)getpid()); 
    }
    else{
        printf("Hello, I am a parent of %d (pid : %d)\n",(int)getpid(),rc );
    }

}

    return 0;
}