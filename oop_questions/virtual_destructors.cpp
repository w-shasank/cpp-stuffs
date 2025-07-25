#include<iostream>
using namespace std;
class base{
    protected:
        int baseVal;
    public:
     base(int x=0):baseVal(x)
    {
        cout<<"Base Constructor called";
    }
    virtual ~  base()
    {
        cout<<endl<<"Base destructor called";
    }
};
class derived : public base{
    private:
    int derivedValue;
public:
   derived(int x,int y):base(x),derivedValue(y){
    cout<<"Derived Constructor Called :";
   }
  ~derived()
   {
    cout<<endl<<"Derived destructor called :";
   }
};


int main()
{
    base *b = new derived(10,20);
    delete b;
    return 0;
}