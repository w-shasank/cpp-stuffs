#include<iostream>
using namespace std;
class entity{

     public:
       static int a;
        static int b;
    static  void printfun()
    {
        cout<<a<<endl;
    cout<<b<<endl;
    
    }
};

 
int main()
{
    entity e1,e2;
    cout<<"Enetr the values for entity : ";
    cin>>e1.a;
    
    cin>>e1.b;
    // cout<<e1.a<<endl;
    // cout<<e2.b<<endl;
    // cout<<e1.b<<endl;
    // cout<<e2.a<<endl;
      e1.printfun();
      e2.printfun();
    return 0;   
}