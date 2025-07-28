#include<iostream>
using namespace std;
class Base {
   protected :
        int baseNumber;
    public:
    Base(int x=0):baseNumber(x)
    {}
    virtual ~Base()
    {
        cout<<endl<<"The destructor is called :";
    }
};
class Derived :public Base{
    private :
        int derivedNumber ;
    public:
        Derived(int First=0,int Second =0):Base(First),derivedNumber(Second)
        {
            cout<<endl<<"The constructor of the base class is called :";

        }
};
int main()
{
    int num=56;
    char *b = reinterpret_cast<char*>(num);
    cout<<endl<<static_cast<void *>(b);
    cout<<"The casting is done and dusted :"
    return 0;
}