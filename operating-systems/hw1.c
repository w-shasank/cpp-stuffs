/*Write a program that calls fork(). Before calling fork(), have the
main process access a variable (e.g., x) and set its value to some-
thing (e.g., 100). What value is the variable in the child process?
What happens to the variable when both the child and parent change
the value of x? **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int x = 100 ;
    int rc = fork();
    if(rc<0){
        printf("Fork failed\n");
        exit(1);
    }
    else if(rc==0)
    {
        printf("THe child process succesfully created with (P I D) :%d ",getpid());
        int x = 200; //MOdifying x in child process
        printf("Child process: x = %d\n", x);
    }
    else{
        printf("The parent process  with (P I D) :%d ",getpid());
        x = 300; //Mdifying x in parent process
        printf("Parent process: x = %d\n", x);
    }
    return 0;
}



 // Note: The child process has its own copy of x, which is 200.
        // The parent process has its own copy of x, which is 300.
        // Changes in one process do not affect the other.
