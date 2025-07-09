#include<iostream>
#include<string>
using namespace std;
  
   class entity{
    protected :
        void namer(){
            cout<<"My name is Shashank:";
        }

   };
   class person : public entity{
    public :
        void cafe()
        {
            cout<<"HEllo";
        }
        void showme()
        {
             namer();
        }
   };

int main()
{
    person c1;
    c1.showme();
    c1.cafe();
    return 0;
}
