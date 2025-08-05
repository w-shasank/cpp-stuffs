#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
   int rc =fork();
   if(rc<0)
   {
    printf("Fork Failed \n");
   }
   else if(rc == 0)
   {
    printf("The child process is created :");
    printf("HELLO");
   }
   else{
    wait(NULL);
    printf("\nGOODBYE");
   }
   return 0;

}