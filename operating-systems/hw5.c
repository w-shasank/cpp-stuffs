/*Now write a program that uses wait() to wait for the child process
to finish in the parent. What does wait() return? What happens if
you use wait() in the child?*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
    int rc = fork();
    if(rc<0)
    {
        printf("Unable to fork :");
    }
    else if(rc==0)
    {
    
     printf("Child : %d",getpid()  );

    }

    else
    {
        printf("The parent :");
         int b= wait(NULL);
         
     printf("Wait returned the given value %d and the pid is %d",b,getpid());
    }
    return 0;
}

   //For wait() in the parent process
//Child : 107492The parent :Wait returned the given value 107492 and the pid is 107491
 

//for wait() in the child process 
//The parent :Wait returned the given value -1 Child 

//wait() returned -1 when it is called in the child process because the child process dont have any child to wait for their termination and is immediately terminated
//returns the pid of the child when called at the parent process