/*Write another program using fork(). The child process should
print “hello”; the parent process should print “goodbye”. You should
try to ensure that the child process always prints first; can you do
this without calling wait() in the parent?

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

//Waiting for the parent process to conclude its execution using the wait() system call:
//This one lets the child process to execute first and then the parent using the wait() function call at the parent process.
*/


//Implementation of the given code without using the wait system call
