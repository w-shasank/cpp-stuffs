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
    person p;
    p.cafe();
    p.showme();
    return 0;
}
