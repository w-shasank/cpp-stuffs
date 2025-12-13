#include<iostream>

void sayHello(int n)
{
    for(int i=0;i<n;i++){std::cout<<"Hello\n";}
}

int main()
{
     void (*funcPtr)(int) =&sayHello;
     funcPtr(4);
     return 0;
}